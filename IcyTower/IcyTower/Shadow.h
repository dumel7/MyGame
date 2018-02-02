#pragma once
#include "Floor.h"
class Shadow :
	public Floor
{
private:
	float maxYVelocity;
	float yVelocity;
	float yAccelarate;
public:
	Shadow(int number, sf::Vector2f pos, Resource &resource, float maxVelocity);
	void setYAccelarate(float yAcc);		//ustawienie przyspieszenia platformy w dol
	void drawNow(sf::RenderWindow & Window, sf::Vector2f gravity);
	~Shadow();
};

