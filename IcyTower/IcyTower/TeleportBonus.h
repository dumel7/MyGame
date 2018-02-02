#pragma once
#include "Bonus.h"
class TeleportBonus :
	public Bonus
{
public:
	TeleportBonus(sf::Vector2f pos, Resource &resource);
	~TeleportBonus();
};

