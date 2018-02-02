#pragma once
#include "ToDraw.h"
#include "Player.h"
class Enemy :
	public ToDraw
{
protected:
	direction direct;
	sf::Sprite sprite;
public:
	Enemy();
	Enemy(Resource &resource, Player *player, int points);
	void drawNow(sf::RenderWindow & Window,sf::Vector2f gravity);
	~Enemy();
};

