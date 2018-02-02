#pragma once
#include "ToDraw.h"
class DeadWall :
	public ToDraw
{
private:
	sf::Sprite sprite;
	sf::Text points;
	sf::Font font;
public:
	DeadWall(Resource &resource, int point);
	void drawNow(sf::RenderWindow & Window, sf::Vector2f gravity);
	~DeadWall();
};

