#include "Enemy.h"



Enemy::Enemy()
{
}

Enemy::Enemy(Resource & resource, Player * player, int points)
{
}


void Enemy::drawNow(sf::RenderWindow &Window,sf::Vector2f gravity)
{
	sprite.setScale(sf::Vector2f(direct, 1));
	
	Window.draw(sprite);
}

Enemy::~Enemy()
{
}
