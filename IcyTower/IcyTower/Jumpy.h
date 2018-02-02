#pragma once
#include "Floor.h"
class Jumpy :
	public Floor
{
public:
	Jumpy();
	Jumpy(int number, sf::Vector2f pos, Resource & resource);
	~Jumpy();
};

