#include "Bonus.h"



Bonus::Bonus()
{
}

void Bonus::drawNow(sf::RenderWindow & Window, sf::Vector2f gravity)
{
	sprite.move(gravity);
	Window.draw(sprite);
	
}

void Bonus::setPosition(sf::Vector2f pos)
{
	sprite.setPosition(pos);
}
float Bonus::getX()
{
	return sprite.getPosition().x;
}

float Bonus::getY()
{
	return sprite.getPosition().y;
}
sf::IntRect Bonus::getRect()
{
	return sprite.getTextureRect();
}
sf::Vector2f Bonus::getDimension()
{
	return sf::Vector2f(sprite.getTextureRect().width*sprite.getScale().x,sprite.getTextureRect().height*sprite.getScale().y);
}
Bonus::~Bonus()
{
}
