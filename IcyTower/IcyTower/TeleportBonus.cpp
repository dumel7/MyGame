#include "TeleportBonus.h"



TeleportBonus::TeleportBonus(sf::Vector2f pos, Resource &resource) :Bonus()
{
	resource.setTeleportBonus(sprite);
	setPosition(pos);
}


TeleportBonus::~TeleportBonus()
{
}
