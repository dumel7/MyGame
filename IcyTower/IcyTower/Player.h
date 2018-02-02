#pragma once
#include "ToDraw.h"
#include <list>
#include "Floor.h"
#include "Bonus.h"

class Player
	: public ToDraw
{
private:
	int steps=0;
	direction direct;
	movement motion;
	sf::Vector2f move;
	sf::Sprite sprite[9];
public:
	Player(Resource &resource);										//konstruktor
	void setMove(sf::Vector2f move);								//ustawia predkosc poruszania sie postaci
	float getX();													//zwraca polorzenie postaci X
	float getY();													//zwraca polorzenie postaci Y
	void drawNow(sf::RenderWindow &Window, sf::Vector2f gravity);	//sprawdza w ktora strone postac jest skierowana i rysuje na ekranie
	void makeMove(sf::Vector2f mov);								//wykonuje ruch postacia o zadany vektor mov
	void makeMove();												//wykonuje ruch postaci z prywatnego move
	sf::Vector2f getPosition();										//zwraca pozycje postaci
	sf::IntRect getIntRect();										//zwraca prostokat tworzzony przez postac
	void incrementMove(sf::Vector2f mov);							//zwieksza ruch o podany vektor
	void moveRight(float accelerate);								//poruszenie postacia w prawo
	void moveLeft(float accelerate);								//poruszenie postacia w lewo
	void moveUp(float accelerate);									//poruszenie postacia w gore
	void slowDownGravity(float gravity,bool is);					//spowolnienie postaci w ruchu poziomym
	void slowDownXY(float accelerate);								//spowolnienie postaci w ruchu pionowym
	void changeMovement(direction dir, movement mov);				//zmiana ruchu postaci i kierunku postaci
	movement switchMovement();										//zmiana ruchu postaci
	bool isJumping();												//zwraca czy postac jest wa trakcie skoku
	void switchDirection();											//zmiana kierunku poruszania sie postaci
	bool collisionWithSides(int leftSide, int rightSide);			//zwraca czy jest kolizja z stronami planszy
	bool collisionWithFloor(Floor * floor);							//zwraca czy jest kolizja z platforma
	bool collisionWithFloor(std::list<Floor*>& floorList);			//zwraca czy jest kolizja z jakakolwiek platforma z listy
	bool collisionWithBonus(Bonus *bonus);							//zwraca czy jest kolizja z bonusem
	bool collisionCheck(Floor *floor);								//zwraca czy jest kolizja z platforma
	bool intersectRect(sf::IntRect rect);							//zwraca czy posac koiduje z prostokatem
	float getMoveX();												//zwraca wartosc rucu X
	float getMoveY();												//zwraca wartosc ruchu Y
	sf::Vector2f getMove();											//zwraca wartosc vectora ruchu
	void setPosition(sf::Vector2f pos);								//ustawia pozycje postaci
	bool isDead(int y);												//zwraca czy postac przekroczyla y
	~Player();														//destruktor
};

