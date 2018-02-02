#include "Ghost.h"
#include <math.h> 

Ghost::Ghost(Resource & resource,Player * player, int points):Enemy(),player(player),liveBeggingPoints(points)
{
	resource.setGhost(sprite);
	move.x = 0;
	move.y = 0;
	direct = right;
	sprite.setPosition(sf::Vector2f(WINDOW_X / 2, WINDOW_Y+40));
}
sf::Vector2f Ghost::calculateMove()
{
	float angle = (float)atan2f((player->getPosition().y - sprite.getPosition().y), (player->getPosition().x - sprite.getPosition().x));
	return sf::Vector2f(GHOST_SPEED*cos(angle),GHOST_SPEED*sin(angle));
}
void Ghost::checkPosition()
{
	if (getY() > WINDOW_Y+40) sprite.setPosition(sf::Vector2f(getX(), WINDOW_Y + 40));
}
void Ghost::switchMovement()
{
	if (player->getPosition().x > getX()) direct= right;
	else direct = left;
}
void Ghost::setMove(sf::Vector2f vec)
{
	move = vec;
}
void Ghost::makeMove(sf::Vector2f mov) {
	sprite.move(mov);
}
void Ghost::makeMove() {
	sprite.move(move);
}
bool Ghost::checkCollision()
{
	if ((player->getX() + PLAYER_WIDTH / 2.0f > getX()-sprite.getTextureRect().width/2) && (player->getX() - PLAYER_WIDTH / 2.f < getX() + sprite.getTextureRect().width/2)) {
		if ((player->getY() + PLAYER_HEIGHT / 2.0f > getY()-sprite.getTextureRect().height/2) && (player->getY() - PLAYER_HEIGHT / 2.f < getY() + sprite.getTextureRect().height/2)) {
			return true;
		}
	}
	return false;
}
float Ghost::getX()
{
	return sprite.getPosition().x;
}
float Ghost::getY()
{
	return sprite.getPosition().y;
}

Player * Ghost::getPlayer()
{
	return player;
}
bool Ghost::checkDead(int points)
{
	if (points - liveBeggingPoints >= GHOST_LIVE_TIME) {
		return true;
	}
	return false;
}
void Ghost::drawNow(sf::RenderWindow &Window,sf::Vector2f gravity)
{
	sprite.setScale(sf::Vector2f(direct, 1));
	sprite.move(gravity);
	Window.draw(sprite);
}
Ghost::~Ghost()
{
}
