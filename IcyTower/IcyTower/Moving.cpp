#include "Moving.h"



Moving::Moving(int number, sf::Vector2f pos, Resource & resource, float xVelocity):Floor(),xVelocity(xVelocity)
{
	resource.setFloorMoving(sprite, number);
	setPosition(pos);
	//xVelocity = MOVING_FLOOR_VELOCITY;
}

bool Moving::collisionWithSides(int leftSide, int rightSide)
{
	if ((getX() + xVelocity < leftSide) || (getX() + xVelocity + getWidth() > rightSide)) {
		return true;
	}
	return false;
}

void Moving::changeDirection()
{
	xVelocity *= -1;
}

void Moving::drawNow(sf::RenderWindow & Window, sf::Vector2f gravity)
{
	this->Floor::drawNow(Window, sf::Vector2f(gravity.x + xVelocity, gravity.y));
}

sf::Vector2f Moving::getMove()
{
	return sf::Vector2f(xVelocity,0.f);
}

Moving::~Moving()
{
}
