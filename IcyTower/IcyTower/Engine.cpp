#include "Engine.h"

Engine::Engine()
{
	window = new sf::RenderWindow(sf::VideoMode(WINDOW_X, WINDOW_Y, 32), NAME_GAME);
	view = new sf::View(sf::FloatRect(0.f, 0.f, WINDOW_X, WINDOW_Y));
	window->setView(*view);
	window->setFramerateLimit(FPS);
	srand(time(NULL));
	initParam();
	game = newGame;
}
void Engine::start()
{
	initResource();
	while (game == newGame) {
		setBoard();
		while (window->isOpen() && (game < 2)) {
			sf::Event event;
			while (window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window->close();
			}
			if (game == onGoing) {
				newElements();
				enemy();
				player();
				moveFloor();
			}
			checkGame();
			draw();
		}
		deleteAll();
		initParam();
	}
}
void Engine::initResource()
{
	try {
		resource = new Resource();
	}
	catch (ExceptionOpenError *e) {
		std::cout << e->getString() << e->getCode() << std::endl;
		game = close;
	}
}
void Engine::initKey()
{
	key.space = sf::Keyboard::Space;
	key.left = sf::Keyboard::Left;
	key.right = sf::Keyboard::Right;
}
void Engine::switchKey()
{
	std::swap(key.left, key.right);
}
void Engine::setBoard()
{
	//inicjalizacja banner z punktami
	interfaceList.push_front(new PointBanner(*resource));
	//tlo planszy
	interfaceList.push_front(new Background(*resource));
	//boki planszy
	interfaceList.push_front(new Sides(*resource));
	//postac
	playerList.push_front(new Player(*resource));
	//inicjalizacja platform
	newLevel();
	game = onGoing;
}
void Engine::keyboardPlayer(Player *player)
{
	player->slowDownXY(RIGHT_LEFT_STOP_ACCELERATION);
	if (sf::Keyboard::isKeyPressed(key.space)) {
		if (player->getMoveX() > PLAYER_SPEED_XY_SUPER_JUMP) {
			player->moveUp(SUPER_JUMP_ACCELERATION);
		}
		else {
			player->moveUp(JUMP_ACCELERATION);
		}
	}
	if (sf::Keyboard::isKeyPressed(key.right)) {
		player->moveRight(RIGHT_LEFT_ACCELERATION);
		return;
	}
	if (sf::Keyboard::isKeyPressed(key.left)) {
		player->moveLeft(RIGHT_LEFT_ACCELERATION);
		return;
	}
}
void Engine::newLevel()
{
	lvl++;
	Floor *floor = new Basic((WINDOW_X-2*WIDTH_SIDE)/DIMENSION, sf::Vector2f(WIDTH_SIDE,WINDOW_Y-WIDTH_SIDE),(*resource));
	floorList.push_front(floor);
	for (int y = WIDTH_SIDE; y < WINDOW_Y; y += WIDTH_SIDE) {
		newElements();
	}
}
void Engine::newElements()
{
	int number, x;
	std::list<Floor*> ::iterator i = floorList.begin();
	std::list<ToDraw*> ::iterator it = interfaceList.begin();
	it++;
	Background *background = dynamic_cast<Background*> (*it);
	if ((*i)->getY() - BETWEEN>0) {
		number = std::rand() % NUMBER_LVL[lvl] + NUMBER_LVL[lvl];
		x = std::rand() % (WINDOW_Y - number*DIMENSION) + WIDTH_SIDE;
		sf::Vector2f pos(x, (int) (*i)->getY() - WIDTH_SIDE);
		pos += background->getPositionRemainder();
       	floorList.push_front(randomFloor(number,pos));
		//inicjalizacja bonusa
 		newBonus(*floorList.begin());

	}
	checkAndDeleteLastFloor();
	checkAndDeleteLastBonus();
}
void Engine::newBonus(Floor *floor)
{
	if (!(std::rand() % 2)) {
		sf::Vector2f pos(floor->getX()+(std::rand()%((int)floor->getWidth())),floor->getY()-DIMENSION/2);
		switch (std::rand() % 5) {
			//podstawowy bonus
		case (0) :
			bonusList.push_front(new BasicBonus(pos, (*resource)));
			return;
			//obracajacy bonus
		case (1):
			bonusList.push_front(new ViewBonus(pos, (*resource)));
			return;
			//odejmujacy punkty
		case(2) :
			bonusList.push_front(new DeadBonus(pos, *resource));
			return;
			//teleportujacy
		case(3) :
			bonusList.push_front(new TeleportBonus(pos, *resource));
			return;
			//duszek
		case(4) :
			bonusList.push_front(new GhostBonus(pos, *resource));
			return;
		}
	}
}
Floor *Engine::randomFloor(int number, sf::Vector2f pos) {
	switch (std::rand() % 5) {
				case(0) :
					return new Basic(number, pos, (*resource));
								break;
				case(1) :
					return new Sand(number, pos, (*resource));
								break;
				case(2) :
					return new Jumpy(number, pos, (*resource));
								break;
				case(3) :
					return new Moving(number, pos, (*resource),MOVING_FLOOR_VELOCITY*(std::rand()%MOVING_FLOOR_MAX_INCREMENT_VELOCITY+MOVING_FLOOR_MIN_INCREMENT_VELOCITY));
								break;
				case(4) :
					return new Shadow(number, pos, (*resource),SHADOW_FLOOR_MAX_VELOCITY);
								break;
	}
}
void Engine::checkAndDeleteLastFloor() {
	if (floorList.back()->getY() > WINDOW_Y) {
		bonusPoints(1);
		delete floorList.back();
		floorList.pop_back();
	}
}
void Engine::checkAndDeleteLastBonus()
{
	if(!bonusList.empty())
		if (bonusList.back()->getY() > WINDOW_Y) {
			delete bonusList.back();
			bonusList.pop_back();
		}
}
void Engine::moveFloor()
{
	Moving *floorMoving;
	for (Floor* floor : floorList) {
		if (floorMoving = dynamic_cast<Moving*> (floor)) {
			if (floorMoving->collisionWithSides(WIDTH_SIDE, WINDOW_X - WIDTH_SIDE))
	 			floorMoving->changeDirection();
		}
	}
}
void Engine::bonusPoints(int point)
{
	if (points==LIMIT_LVL[lvl]) {
		lvl++;
	}
	points+=point;
}
void Engine::playerIsInRectGravity(Player *player) {
	if (player->intersectRect(GRAVITY_RECT)) {
		if(gravity.y<4)
 		gravity += GRAVITY_ACCELERATION;
	}
	else {
		if(gravity.y>GRAVITY.y)
		gravity -= GRAVITY_STOP_ACCELERATION;
	}
}
void Engine::player()
{
	for (Player* player : playerList) {
		keyboardPlayer(player);
		player->slowDownGravity(PLAYER_GRAVITY, collisionPlayerWithFloors(player));
		if (player->collisionWithSides(WIDTH_SIDE, WINDOW_X - WIDTH_SIDE)) {
			player->switchDirection();
		}
		playerIsInRectGravity(player);
		player->makeMove();
		player->makeMove(gravity);
		collisionPlayerWithBonus(player);
	}
	checkAndDeletePlayers();
}
bool Engine::collisionPlayerWithFloors(Player *player) {
	for (Floor* floor : floorList) {
		if (player->collisionWithFloor(floor)) {
			//platforma Piaskowa
			if (dynamic_cast<Sand*> (floor)) {
				player->setMove(sf::Vector2f(0.f,player->getMoveY()));
			}
			//platforma Jumpy
			if (dynamic_cast<Jumpy*> (floor)) {
				player->moveUp(SUPER_JUMP_ACCELERATION);
			}
			//platforma poruszajaca sie
			if (Moving *floorMoving = dynamic_cast<Moving*> (floor)) {
				player->makeMove(floorMoving->getMove());
			}
			//platforma Spadajaca
			if (Shadow *floorShadow = dynamic_cast<Shadow*> (floor)) {
				floorShadow->setYAccelarate(SHADOW_FLOOR_ACCELARATE);
			}
			return true;
		}
	}
	return false;
}
void Engine::collisionPlayerWithBonus(Player * player)
{
	if (!bonusList.empty()) {
		for (std::list<Bonus*>::iterator bonus = bonusList.begin(); bonus != bonusList.end(); bonus++) {
			if (player->collisionWithBonus(*bonus)) {
				if (dynamic_cast<ViewBonus*> (*bonus)) {
					view->rotate(180.f);
					window->setView(*view);
					switchKey();
				}
				if (dynamic_cast<BasicBonus*> (*bonus)) {
					bonusPoints(3);
				}
				if (dynamic_cast<DeadBonus*> (*bonus)) {
					bonusPoints(-5);
				}
				if (dynamic_cast<GhostBonus*> (*bonus)) {
					enemyList.push_front(new Ghost((*resource), player, points));
				}
				if (dynamic_cast<TeleportBonus*> (*bonus)) {
					player->setPosition(TELEPORT_POSITION);
				}
				delete *bonus;
				bonusList.erase(bonus);
				return;
			}
		}
	}
}
void Engine::checkAndDeletePlayers() {
	std::list<Player *>::iterator player = playerList.begin();
	std::list<Player *>::iterator playerDel;
	while (player != playerList.end()) {
		if ((*player)->isDead(WINDOW_Y) == true) {
			playerDel = player;
			player++;
			delete *playerDel;
			playerList.erase(playerDel);
		}
		else {
			player++;
		}
	}
	if (playerList.empty() == true) {
		resetView();
		interfaceList.push_back(new DeadWall(*resource,points));
		game = pause;
	}
}
void Engine::findAndDeletePlayer(Player * player)
{
	for (std::list<Player*>::iterator playerIt = playerList.begin(); playerIt != playerList.end(); playerIt++) {
		if (*playerIt == player) {
			delete *playerIt;
			playerList.erase(playerIt);
			return;
		}
	}
	return;
}
void Engine::checkGame()
{
	if (game == pause) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			game = close;
			return;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			game = newGame;
			return;
		}
	}
}
void Engine::initParam()
{
	initKey();
	points = 0;
	lvl = -1;
	gravity = sf::Vector2f(0.0f, 0.0f);
}
void Engine::deleteAll()
{
	for (std::list<ToDraw *>::iterator inter = interfaceList.begin(); inter != interfaceList.end(); inter++) {
		delete *inter;
	}
	for (std::list<Floor *>::iterator floor = floorList.begin(); floor != floorList.end(); floor++) {
		delete *floor;
	}
	for (std::list<Enemy *>::iterator enemy = enemyList.begin(); enemy != enemyList.end(); enemy++) {
		delete *enemy;
	}
	for (std::list<Bonus *>::iterator bonus = bonusList.begin(); bonus != bonusList.end(); bonus++) {
		delete *bonus;
	}
	for (std::list<Player *>::iterator player = playerList.begin(); player != playerList.end(); player++) {
		delete *player;
	}
	bonusList.clear();
	floorList.clear();
	interfaceList.clear();
	playerList.clear();
	enemyList.clear();
}
void Engine::resetView()
{
	view->reset(sf::FloatRect(0.f, 0.f, WINDOW_X, WINDOW_Y));
	window->setView(*view);
}
void Engine::enemy()
{
	std::list<Player*>::iterator player = playerList.begin();
	for (std::list<Enemy *>::iterator enemy = enemyList.begin(); enemy != enemyList.end();) {
		if (Ghost *ghost = dynamic_cast<Ghost*> (*enemy)) {
			ghost->setMove(ghost->calculateMove());
			ghost->makeMove();
			ghost->checkPosition();
			ghost->switchMovement();
			if(ghost->checkCollision()){
				findAndDeletePlayer(ghost->getPlayer());
				std::list<Enemy *>::iterator enemyToDel = enemy;
				delete ghost;
				enemyList.erase(enemyToDel);
				return;
			}
			if (ghost->checkDead(points)) {
				std::list<Enemy *>::iterator enemyToDel = enemy;
				enemy++;
				delete *enemyToDel;
				enemyList.erase(enemyToDel);
			}
			else {
				enemy++;
			}
		}
		else {
			enemy++;
		}
	}
}
void Engine::draw()
{
	window->clear();
	for (ToDraw* interface : interfaceList) {
		interface->drawNow(*window, gravity);
	}
	interfaceList.back()->drawNow(*window, points);
	if (game == onGoing) {
		for (Floor* floor : floorList) {
			floor->drawNow(*window, gravity);
		}
		for (Player* player : playerList) {
			player->drawNow(*window, gravity);
		}
		for (Bonus* bonus : bonusList) {
			bonus->drawNow(*window, gravity);
		}
		for each (Enemy* enemy in enemyList)
		{
			enemy->drawNow(*window, gravity);
		}
	}
	window->display();
}
Engine::~Engine()
{
	delete resource;
	delete view;
	delete window;
}