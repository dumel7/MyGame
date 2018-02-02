#pragma once
#include "ToDraw.h"
class Background :
	public ToDraw
{
private:
	sf::Sprite sprite;
public:
	Background(Resource &resource);
	void drawNow(sf::RenderWindow &Window, sf::Vector2f gravity);
	sf::Vector2f getPositionRemainder();								//zwraca przesunie tla wzgleden pelnej liczby
	void update(sf::Vector2f gravity);									//aktualizuje pozycje tla
	~Background();
};

