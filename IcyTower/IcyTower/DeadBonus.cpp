#include "DeadBonus.h"



DeadBonus::DeadBonus(sf::Vector2f pos, Resource &resource) :Bonus()
{
	resource.setDeadBonus(sprite);
	setPosition(pos);
}


DeadBonus::~DeadBonus()
{
}
