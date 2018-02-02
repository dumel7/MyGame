#pragma once
#include "Bonus.h"
class BasicBonus :
	public Bonus
{
public:
	BasicBonus(sf::Vector2f pos, Resource &resource);
	~BasicBonus();
};

