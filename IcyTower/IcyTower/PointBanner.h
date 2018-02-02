#pragma once
#include "ToDraw.h"
class PointBanner :
	public ToDraw
{
private:
	sf::Sprite sprite;
	sf::Text points;
	sf::Font font;
public:
	PointBanner(Resource &resource);
	void drawNow(sf::RenderWindow &Window, int points);
	~PointBanner();
};

