#pragma once
#include "Resource.h"
#include "Header.h"
#include <SFML\Graphics.hpp>
class ToDraw
{
public:
	ToDraw();
	virtual void drawNow(sf::RenderWindow &Window, sf::Vector2f gravity);
	virtual void drawNow(sf::RenderWindow &Window);
	virtual void drawNow(sf::RenderWindow &Window, int point);
	virtual void update();
	~ToDraw();
};

