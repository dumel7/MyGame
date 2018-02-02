#pragma once
#include "PathHeader.h"
#include "ExceptionOpenError.h"
#include "Header.h"
#include <SFML\Graphics.hpp>
#include <typeinfo>



class Resource
{
private:
	sf::Image playerIm;
	sf::Texture playerTex;
	sf::Texture floorBasicTex;
	sf::Texture floorSandTex;
	sf::Texture floorJumpyTex;
	sf::Texture floorMovingTex;
	sf::Texture floorShadowTex;
	sf::Texture backgroungTex;
	sf::Texture bonusViewTex;
	sf::Texture sidesTex;
	sf::Texture pointsBannerTex;
	sf::Texture deadWallTex;
	sf::Texture ghostTex;
	sf::Texture ghostBonusTex;
	sf::Font pointsBannerFont;
public:
	Resource();
private:
	void initPlayer();
	void initGhost();
	void initBackground();
	void initFloorBasic();
	void initFloorSand();
	void initFloorJumpy();
	void initFloorMoving();
	void initFloorShadow();
	void initSides();
	void initPointsBanner();
	void initGhostBonus();
	void initFont();
	void initDeadWall();
	void initViewBonus();
public:
	void setFont(sf::Font &font);
	void setBackground(sf::Sprite &sprite);
	void setSideA(sf::Sprite &sprite);
	void setSideB(sf::Sprite &sprite);
	void setPlayer(sf::Sprite sprite[9]);
	void setGhost(sf::Sprite &sprite);
	void setFloorBasic(sf::Sprite &sprite, int number);
	void setFloorSand(sf::Sprite &sprite, int number);
	void setFloorJumpy(sf::Sprite &sprite, int number);
	void setFloorMoving(sf::Sprite &sprite, int number);
	void setFloorShadow(sf::Sprite &sprite, int number);
	void setBasicBonus(sf::Sprite &sprite);
	void setDeadBonus(sf::Sprite &sprite);
	void setViewBonus(sf::Sprite &sprite);
	void setTeleportBonus(sf::Sprite &sprite);
	void setGhostBonus(sf::Sprite &sprite);
	void setPointsBanner(sf::Sprite &sprite);
	void setDeadWall(sf::Sprite &sprite);
	~Resource();
};

