#pragma once
#include "ToDraw.h"

class Floor :
	public ToDraw
{
public:
	sf::Texture tex;
	sf::Sprite sprite;
public:
	Floor();
	void drawNow(sf::RenderWindow &Window, sf::Vector2f gravity);
	void setPosition(sf::Vector2f pos);								//ustawia pozycje 
	float getX();													//zwraca pozycje X
	float getY();													//zwraca pozycje Y
	float getWidth();												//zwraca szerokosc sprite
	~Floor();
};

