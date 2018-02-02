#pragma once
#include "ToDraw.h"
class Bonus :
	public ToDraw
{
public:
	sf::Sprite sprite;
public:
	Bonus();
	void drawNow(sf::RenderWindow &Window, sf::Vector2f gravity);
	void setPosition(sf::Vector2f pos);								//ustawia pozycje 
	float getX();													//zwraca pozycje X
	float getY();													//zwraca pozycje Y
	sf::IntRect getRect();											//zwraca prostokat sprite
	sf::Vector2f getDimension();									//zwraca wymiary obiektu
	~Bonus();
};

