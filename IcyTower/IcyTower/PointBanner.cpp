#include "PointBanner.h"



PointBanner::PointBanner(Resource &resource)
{
	resource.setFont(font);
	resource.setPointsBanner(sprite);
	points.setFont(font);
	points.setCharacterSize(30);
	
	points.setPosition(BANNER_POSITION);
	sprite.setPosition(BANNER_POSITION);
}

void PointBanner::drawNow(sf::RenderWindow & Window, int point)
{
	points.setString(std::to_string(point));
	Window.draw(sprite);
	Window.draw(points);
}


PointBanner::~PointBanner()
{
}
