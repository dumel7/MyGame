#pragma once
#include "Bonus.h"
class ViewBonus :
	public Bonus
{
public:
	ViewBonus(sf::Vector2f pos, Resource &resource);
	~ViewBonus();
};

