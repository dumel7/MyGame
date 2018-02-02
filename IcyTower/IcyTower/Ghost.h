#pragma once
#include "Enemy.h"
#include "Player.h"
class Ghost :
	public Enemy
{
private:
	int liveBeggingPoints;		
	sf::Vector2f move;
	Player *player;
public:
	Ghost(Resource &resource, Player *player, int points);
	sf::Vector2f calculateMove();							//zwraca vector kierunku i predkosci ducha
	void checkPosition();									//sprawdza czy duch wyszedl poza plansze 				
	void switchMovement();									//zmienia kierunek poruszania sie ducha
	void setMove(sf::Vector2f vec);							//ustawia predkosc ducha
	void makeMove(sf::Vector2f vec);						//wykonuje ruch o zadany vektor 
	void makeMove();										//wykonuje ruch
	bool checkCollision();									//sprawdza czy zaistniala kolizja z player
	float getX();											//zwraca pozycje X 
	float getY();											//zwraca pozycje Y
	Player *getPlayer();									//zwraca wskaznik na player
	bool checkDead(int points);								//sprawdza czy nie powinien juz zginac
	void drawNow(sf::RenderWindow & Window, sf::Vector2f gravity);
	~Ghost();
};
