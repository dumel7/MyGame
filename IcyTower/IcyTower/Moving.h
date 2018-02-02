#pragma once
#include "Floor.h"
class Moving :
	public Floor
{
private:
	float xVelocity;
public:
	Moving(int number, sf::Vector2f pos, Resource &resource, float xVelocity);
	bool collisionWithSides(int leftSide, int rightSide);						//sprawdza czy nastapila kolizja ze stronami planszy
	void changeDirection();														//zmienia kierunek poruszania sie platformy
	void drawNow(sf::RenderWindow &Window, sf::Vector2f gravity);				
	sf::Vector2f getMove();														//zwraca vector predkosci poruszania sie platformy
	~Moving();
};

