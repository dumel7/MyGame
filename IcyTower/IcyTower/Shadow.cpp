#include "Shadow.h"



Shadow::Shadow(int number, sf::Vector2f pos, Resource &resource, float maxVelocity) :Floor(), maxYVelocity(maxVelocity)
{
	resource.setFloorShadow(sprite, number);
	setPosition(pos);
	yVelocity = 0.f;
	yAccelarate = 0.f;
}

void Shadow::setYAccelarate(float yAcc)
{
	yAccelarate = yAcc;
}

void Shadow::drawNow(sf::RenderWindow & Window, sf::Vector2f gravity)
{
	if(yVelocity<maxYVelocity)
		yVelocity += yAccelarate;
	this->Floor::drawNow(Window, sf::Vector2f(gravity.x, gravity.y+yVelocity));
}



Shadow::~Shadow()
{
}
