#pragma once
#include "ToDraw.h"

class Sides
	:public ToDraw
{
private:
	sf::Sprite ssideA;		//lewa kolumna planszy
	sf::Sprite ssideB;		//prawa kolumna planszy
public:
	Sides(Resource &resource);
	void drawNow(sf::RenderWindow &Window, sf::Vector2f gravity);
	~Sides();
};

