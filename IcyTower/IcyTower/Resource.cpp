#include "Resource.h"



Resource::Resource()
{
		
		//floor
		initFloorBasic();
		initFloorSand();
		initFloorJumpy();
		initFloorMoving();
		initFloorShadow();
		//interfejs
		initBackground();
		initSides();
		initPointsBanner();
		initFont();
		initDeadWall();
		//gracz
		initPlayer();
		//bonusy
		initViewBonus();
		initGhostBonus();
		//przeciwnik
		initGhost();
}

void Resource::initPlayer()
{
	if (!playerIm.loadFromFile(PATH_PLAYER)) {
		throw new ExceptionOpenError(PATH_PLAYER,2);
	}
	sf::Color color = playerIm.getPixel(5, 5);
	playerIm.createMaskFromColor(color, 0);
	if (!playerTex.loadFromImage(playerIm)) {
		throw new ExceptionOpenError(PATH_PLAYER, 3);
	}
}

void Resource::initGhost()
{
	if (!ghostTex.loadFromFile(PATH_GHOST)) {
		throw new ExceptionOpenError(PATH_GHOST, 2);
	}
}

void Resource::initBackground()
{
	if (!backgroungTex.loadFromFile(PATH_BACKGROUND)) {
		throw new ExceptionOpenError(PATH_BACKGROUND, 2);
	}
}

void Resource::initFloorBasic()
{
	if (!floorBasicTex.loadFromFile(PATH_FLOOR_BASIC)) {
		throw new ExceptionOpenError(PATH_FLOOR_BASIC, 2);
	}
	floorBasicTex.setRepeated(true);
}

void Resource::initFloorSand()
{
	if (!floorSandTex.loadFromFile(PATH_FLOOR_SAND)) {
		throw new ExceptionOpenError(PATH_FLOOR_SAND, 2);
	}
	floorSandTex.setRepeated(true);
}

void Resource::initFloorJumpy()
{

	sf::Image floorJumpyImage;
	if (!floorJumpyImage.loadFromFile(PATH_FLOOR_JUMPY)) {
		throw new ExceptionOpenError(PATH_FLOOR_JUMPY, 2);
	}
	sf::Color color = floorJumpyImage.getPixel(1, 1);
	floorJumpyImage.createMaskFromColor(color, 0);
	if (!floorJumpyTex.loadFromImage(floorJumpyImage)) {
		throw new ExceptionOpenError(PATH_FLOOR_JUMPY, 3);
	}
	floorJumpyTex.setRepeated(true);
}

void Resource::initFloorMoving()
{
	if (!floorMovingTex.loadFromFile(PATH_FLOOR_MOVING)) {
		throw new ExceptionOpenError(PATH_FLOOR_MOVING, 2);
	}
	floorMovingTex.setRepeated(true);
}

void Resource::initFloorShadow()
{
	if (!floorShadowTex.loadFromFile(PATH_FLOOR_SHADOW)) {
		throw new ExceptionOpenError(PATH_FLOOR_SHADOW, 2);
	}
	floorShadowTex.setRepeated(true);
}

void Resource::initSides()
{
	if (!sidesTex.loadFromFile(PATH_SIDES)) {
		throw new ExceptionOpenError(PATH_SIDES, 2);
	}
}

void Resource::initPointsBanner()
{
	sf::Image pointsBannerImage;
	if (!pointsBannerImage.loadFromFile(PATH_POINTS_BANNER)) {
		throw new ExceptionOpenError(PATH_POINTS_BANNER, 2);
	}
	sf::Color color =pointsBannerImage.getPixel(5, 5);
	pointsBannerImage.createMaskFromColor(color, 0);
	if (!pointsBannerTex.loadFromImage(pointsBannerImage)) {
		throw new ExceptionOpenError(PATH_POINTS_BANNER, 3);
	}
}

void Resource::initGhostBonus()
{
	if (!ghostBonusTex.loadFromFile(PATH_GHOST_BONUS))
	{
		throw new ExceptionOpenError(PATH_GHOST_BONUS, 2);
	}
}

void Resource::initFont()
{
	if (!pointsBannerFont.loadFromFile(PATH_POINTS_BANNER_FONT))
	{
		throw new ExceptionOpenError(PATH_POINTS_BANNER_FONT,4);
	}
}

void Resource::initDeadWall()
{
	sf::Image deadWallImage;
	if (!deadWallImage.loadFromFile(PATH_DEAD_WALL)) {
		throw new ExceptionOpenError(PATH_DEAD_WALL, 2);
	}
	sf::Color color = deadWallImage.getPixel(1, 1);
	deadWallImage.createMaskFromColor(color, 0);
	if (!deadWallTex.loadFromImage(deadWallImage)) {
		throw new ExceptionOpenError(PATH_DEAD_WALL, 2);
	}
	deadWallTex.setSmooth(true);
}

void Resource::initViewBonus()
{	
	if (!bonusViewTex.loadFromFile(PATH_BONUS_VIEW)) {
		throw new ExceptionOpenError(PATH_BONUS_VIEW, 2);
	}
	bonusViewTex.setRepeated(true);
}


void Resource::setFont(sf::Font &font)
{
	font = pointsBannerFont;
}

void Resource::setBackground(sf::Sprite & sprite)
{
	backgroungTex.setRepeated(true);
	sprite.setTexture(backgroungTex);
	sprite.setTextureRect(sf::IntRect(0, 0, WINDOW_X-2*WIDTH_SIDE, 2*WINDOW_Y));
	sprite.setPosition(WIDTH_SIDE, (-1)*WINDOW_Y);
}

void Resource::setSideA(sf::Sprite & sprite)
{
	sprite.setTexture(sidesTex);
	sprite.setTextureRect(sf::IntRect(0, 0, WIDTH_SIDE, WINDOW_Y));
	sprite.setPosition(0, 0);
}

void Resource::setSideB(sf::Sprite & sprite)
{
	sprite.setTexture(sidesTex);
	sprite.setTextureRect(sf::IntRect(WIDTH_SIDE, 0, 2 * WIDTH_SIDE, WINDOW_Y));
	sprite.setPosition(WINDOW_X - WIDTH_SIDE, 0);
}

void Resource::setPlayer(sf::Sprite sprite[9])
{
	for (int i = 0; i < 8; i++) {
		sprite[i].setTexture(playerTex);
		sprite[i].setTextureRect(sf::IntRect(i * 34, 4, 29, 51));
		sprite[i].setOrigin(sf::Vector2f(15, 26));
	}
	sprite[jump].setTexture(playerTex);
	sprite[jump].setTextureRect(sf::IntRect(jump * 34, 4, 29, 61));
	sprite[jump].setOrigin(sf::Vector2f(15, 29));
}

void Resource::setGhost(sf::Sprite & sprite)
{
	sprite.setTexture(ghostTex);
	sprite.setTextureRect(sf::IntRect(0.f, 0.f, ghostTex.getSize().x, ghostTex.getSize().y));
	sprite.setOrigin(sf::Vector2f(ghostTex.getSize().x / 2, ghostTex.getSize().y / 2));
}

void Resource::setFloorBasic(sf::Sprite & sprite,int number)
{
	sprite.setTexture(floorBasicTex);
	sprite.setTextureRect(sf::IntRect(0.f, 0.f, DIMENSION * number, floorBasicTex.getSize().y));
}

void Resource::setFloorSand(sf::Sprite & sprite, int number)
{
	sprite.setTexture(floorSandTex);
	sprite.setTextureRect(sf::IntRect(0.f, 0.f, DIMENSION * number, floorSandTex.getSize().y));
}

void Resource::setFloorJumpy(sf::Sprite & sprite, int number)
{
	sprite.setTexture(floorJumpyTex);
	sprite.setTextureRect(sf::IntRect(0.f, 0.f, DIMENSION * number, floorJumpyTex.getSize().y));
}

void Resource::setFloorMoving(sf::Sprite & sprite, int number)
{
	sprite.setTexture(floorMovingTex);
	sprite.setTextureRect(sf::IntRect(0.f, 0.f, DIMENSION * number, floorMovingTex.getSize().y));
}

void Resource::setFloorShadow(sf::Sprite & sprite, int number)
{
	sprite.setTexture(floorShadowTex);
	sprite.setTextureRect(sf::IntRect(0.f, 0.f, DIMENSION * number, floorShadowTex.getSize().y));
}

void Resource::setBasicBonus(sf::Sprite & sprite)
{
	sprite.setTexture(bonusViewTex);
	sprite.setScale(sf::Vector2f(0.1f, 0.1f));
	sprite.setColor(sf::Color::Green);
}

void Resource::setDeadBonus(sf::Sprite & sprite)
{
	sprite.setTexture(bonusViewTex);
	sprite.setScale(sf::Vector2f(0.1f, 0.1f));
	sprite.setColor(sf::Color::Red);
}

void Resource::setViewBonus(sf::Sprite & sprite)
{
	sprite.setTexture(bonusViewTex);
	sprite.setScale(sf::Vector2f(0.1f,0.1f));
	sprite.setColor(sf::Color::Blue);
}

void Resource::setTeleportBonus(sf::Sprite & sprite)
{
	sprite.setTexture(bonusViewTex);
	sprite.setScale(sf::Vector2f(0.1f, 0.1f));
	sprite.setColor(sf::Color::Black);
}

void Resource::setGhostBonus(sf::Sprite & sprite)
{
	sprite.setTexture(ghostBonusTex);
}

void Resource::setPointsBanner(sf::Sprite & sprite)
{
	sprite.setTexture(pointsBannerTex);
	sprite.setTextureRect(sf::IntRect(18.f,30.f,113.f,58.f));
	sprite.setScale(sf::Vector2f(0.9f,0.9f));
	sprite.setColor(sf::Color(255, 255, 255,168));
}

void Resource::setDeadWall(sf::Sprite & sprite)
{
	sprite.setTexture(deadWallTex);
	sprite.setPosition(sf::Vector2f(0.f, 0.f));
}

Resource::~Resource()
{
}
