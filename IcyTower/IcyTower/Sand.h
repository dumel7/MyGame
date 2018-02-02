#pragma once
#include "Floor.h"
class Sand :
	public Floor
{
public:
	Sand(int number, sf::Vector2f pos, Resource & resource);
	~Sand();
};

