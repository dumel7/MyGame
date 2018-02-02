#include "Jumpy.h"



Jumpy::Jumpy(int number, sf::Vector2f pos, Resource &resource) :Floor()
{
	resource.setFloorJumpy(sprite, number);
	setPosition(pos);
}


Jumpy::~Jumpy()
{
}
