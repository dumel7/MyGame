#include "Floor.h"




Floor::Floor()
{
}



void Floor::drawNow(sf::RenderWindow & Window, sf::Vector2f gravity)
{
	sprite.move(gravity);
	Window.draw(sprite);
}

void Floor::setPosition(sf::Vector2f pos)
{
	sprite.setPosition(pos);
}

float Floor::getX()
{
	return sprite.getPosition().x;
}

float Floor::getY() 
{
	return sprite.getPosition().y;
}

float Floor::getWidth()
{
	return sprite.getTextureRect().width;
}


Floor::~Floor()
{
}
