#include "Basic.h"


Basic::Basic(int number,sf::Vector2f pos, Resource &resource):Floor()
{
	resource.setFloorBasic(sprite, number);
	setPosition(pos);
}

Basic::~Basic()
{
}
