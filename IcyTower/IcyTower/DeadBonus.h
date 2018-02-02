#pragma once
#include "Bonus.h"
class DeadBonus :
	public Bonus
{
public:
	DeadBonus(sf::Vector2f pos, Resource &resource);
	~DeadBonus();
};

