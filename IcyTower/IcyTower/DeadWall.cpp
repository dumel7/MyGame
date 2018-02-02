#include "DeadWall.h"

DeadWall::DeadWall(Resource & resource, int point)
{
	resource.setFont(font);
	points.setFont(font);
	points.setCharacterSize(60);
	points.setPosition(DEAD_WALL_POINTS_POSITION);
	points.setString(std::to_string(point));
	points.setFillColor(sf::Color::Red);
	resource.setDeadWall(sprite);
}

void DeadWall::drawNow(sf::RenderWindow & Window, sf::Vector2f gravity)
{
	Window.draw(sprite);
	Window.draw(points);
}

DeadWall::~DeadWall()
{
}
