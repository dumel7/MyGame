#include "GhostBonus.h"



GhostBonus::GhostBonus(sf::Vector2f pos, Resource &resource) :Bonus()
{
	resource.setGhostBonus(sprite);
	setPosition(pos);
}


GhostBonus::~GhostBonus()
{
}
