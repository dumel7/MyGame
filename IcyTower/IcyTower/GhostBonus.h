#pragma once
#include "Bonus.h"
class GhostBonus :
	public Bonus
{
public:
	GhostBonus(sf::Vector2f pos, Resource &resource);
	~GhostBonus();
};

