#include "BasicBonus.h"



BasicBonus::BasicBonus(sf::Vector2f pos, Resource &resource) :Bonus()
{
	resource.setBasicBonus(sprite);
	setPosition(pos);
}


BasicBonus::~BasicBonus()
{
}
