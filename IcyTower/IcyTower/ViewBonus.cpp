#include "ViewBonus.h"



ViewBonus::ViewBonus(sf::Vector2f pos, Resource &resource):Bonus()
{
	resource.setViewBonus(sprite);
	setPosition(pos);
}

ViewBonus::~ViewBonus()
{
}
