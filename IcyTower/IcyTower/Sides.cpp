#include "Sides.h"



Sides::Sides(Resource &resource)
{
	resource.setSideA(ssideA);
	resource.setSideB(ssideB);
}

void Sides::drawNow(sf::RenderWindow &Window, sf::Vector2f gravity)
{
	Window.draw(ssideA);
	Window.draw(ssideB);
}



Sides::~Sides()
{
}
