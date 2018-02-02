#include "Sand.h"



Sand::Sand(int number, sf::Vector2f pos, Resource &resource) :Floor()
{
	resource.setFloorSand(sprite, number);
	setPosition(pos);
}

Sand::~Sand()
{
}
