#include "Player.h"
Player::Player(Resource &resource)
{
	resource.setPlayer(sprite);
	move.x = 0;
	move.y = 0;
	motion = idle1;
	direct = idle;
	sprite[motion].setPosition(sf::Vector2f(WINDOW_X / 2, WINDOW_Y - 100 - 51));
}
void Player::setMove(sf::Vector2f move)
{
	this->move = move;
}
void Player::drawNow(sf::RenderWindow & Window, sf::Vector2f gravity)
{
	if (direct != idle)
		sprite[motion].setScale(sf::Vector2f(direct, 1));
	Window.draw(sprite[motion]);
}
void Player::makeMove(sf::Vector2f mov) {
	sprite[motion].move(mov);
}
void Player::makeMove(){
	sprite[motion].move(move);	
}

sf::Vector2f Player::getPosition()
{
	return sprite[motion].getPosition();
}

sf::IntRect Player::getIntRect()
{
	return sprite[motion].getTextureRect();
}

void Player::incrementMove(sf::Vector2f mov) {	
	move += mov;	
}
void Player::moveRight(float accelerate) {
	if (abs(move.x) < PLAYER_MAX_SPEED_XY) {
		move.x += accelerate;
	}
	changeMovement(right, switchMovement());
}
void Player::moveLeft(float accelerate) {
	if (abs(move.x) < PLAYER_MAX_SPEED_XY) {
		move.x -= accelerate;
	}
	changeMovement(left, switchMovement());
}
void Player::moveUp(float accelerate) {
	if (move.y >= 0.0f) {
		if (motion < 5) {
			move.y -= accelerate;
				if (direct == idle) {
					changeMovement(direct, jump);
				}
				else {
					changeMovement(direct, jump1);
				}
		}
	}
}
void Player::slowDownGravity(float gravity, bool is) {
	if (motion >= 5){
		if (move.y > 0.0f) {
			changeMovement(direct, jump3);
		}
		else {
			if ((move.y == 0.0f) && (motion == jump3)) {
				if (direct == idle) {
					changeMovement(direct, idle1);
				}
				else {
					changeMovement(direct, walk1);
				}
				
			}
		}
		move.y += gravity;
		return;
	}
	if (!is) {
		move.y += gravity;
	}
}
void Player::slowDownXY(float accelerate) {
	if (abs(move.x) <= 0.2f) {
		move.x = 0.0f;
		if(motion<5)	changeMovement(idle, idle1);
		return;
	}
	if (move.x > 0) {
		move.x -= accelerate;
	}
	else {
		move.x += accelerate;
	}
}
void Player::changeMovement(direction dir, movement mov)
{
	sf::Vector2f vec = sprite[motion].getPosition();
	motion = mov;
	sprite[motion].setPosition(vec);
	direct = dir;
}

movement Player::switchMovement()
{
	if (motion == idle1) 
		return walk1;
	if (steps > MAX_NEMBER_STEPS) {
		steps = 0;
		switch (motion) {
		case walk1: return walk2;
		case walk2: return walk3;
		case walk3: return walk4;
		case walk4: return walk1;
		}
	}
	if (motion == jump) return jump1;
	steps += abs(move.x);
	return motion;
}
bool Player::isJumping()
{
	if (motion >= 5) return true;
	return false;
}
void Player::switchDirection() {
		direct = static_cast<direction>(direct*(-1));
}
bool Player::collisionWithSides(int leftSide, int rightSide)
{
	if ((getX() + move.x - PLAYER_WIDTH/2< leftSide) || (getX() + move.x +PLAYER_WIDTH/2 > rightSide)) {
		move.x *= -1;
		return true;
	}
	return false;
}
bool Player::collisionWithFloor(Floor *floor) {
	if (collisionCheck(floor) == true) {
		if (move.y > 0.0f) {
			move.y = 0.0f;
		}
		return true;
	}
	return false;
}
bool Player::collisionWithFloor(std::list<Floor*>& floorList)
{
		for (std::list<Floor*>::iterator floorIt = floorList.begin(); floorIt != floorList.end(); floorIt++) {
			if (collisionCheck(*floorIt) == true) {
				if (move.y > 0.0f) {
					
					move.y = 0.0f;
				}
				return true;
			}
		}
		return false;
}
bool Player::collisionWithBonus(Bonus * bonus)
{
	
	if ((getX() + PLAYER_WIDTH/2.0f > bonus->getX()) && (getX() - PLAYER_WIDTH/2.f < bonus->getX()+bonus->getDimension().x)) {
		if ((getY() + PLAYER_HEIGHT/2.0f > bonus->getY()) && (getY() - PLAYER_HEIGHT/2.f < bonus->getY() + bonus->getDimension().y)) {
			return true;
		}
	}
	return false;
}
bool Player::collisionCheck(Floor *floor)
{
	//sprawdzanie y
	if(((getY() + PLAYER_HEIGHT/2.0f + abs(move.y) + PLAYER_GRAVITY) >= floor->getY()) && ( (*floor).getY() >= (getY() + PLAYER_HEIGHT / 2.0f - abs(move.y) - PLAYER_GRAVITY))){
		//sprawdzanie x
		if ((getX() + PLAYER_WIDTH / 2.0f >= (*floor).getX()) && ((*floor).getX() + (*floor).getWidth() >= getX() - PLAYER_WIDTH / 2.0f)) {
			return true;
		}
	}
	return false;
}
bool Player::intersectRect(sf::IntRect rect) {
	return rect.contains(sprite[motion].getPosition().x, sprite[motion].getPosition().y);
}
float Player::getMoveX() {
	return move.x;
}
float Player::getMoveY() {
	return move.y;
}
sf::Vector2f Player::getMove()
{
	return move;
}
void Player::setPosition(sf::Vector2f pos)
{
	sprite[motion].setPosition(pos);
}
bool Player::isDead(int y)
{
	if (sprite[motion].getPosition().y > y) 
		return true;
	return false;
}
float Player::getX() { 
	return sprite[motion].getPosition().x; 
}

float Player::getY() { 
	return sprite[motion].getPosition().y; 
}

Player::~Player()
{
}