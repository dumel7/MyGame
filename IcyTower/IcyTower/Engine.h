#pragma once
#include <list>
#include "Basic.h"
#include "Floor.h"
#include "Sides.h"
#include "Moving.h"
#include "Sand.h"
#include "Jumpy.h"
#include "Shadow.h"
#include "Background.h"
#include "Bonus.h"
#include "DeadBonus.h"
#include "ViewBonus.h"
#include "BasicBonus.h"
#include "TeleportBonus.h"
#include "GhostBonus.h"
#include "Enemy.h"
#include "Ghost.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Player.h"
#include "PointBanner.h"
#include "DeadWall.h"
class Engine
{
private:
	std::list<Floor *> floorList;
	std::list<Bonus *> bonusList;
	std::list<ToDraw *> interfaceList;
	std::list<Player *> playerList;
	std::list<Enemy *> enemyList;
	int lvl;
	sf::View *view;
	sf::RenderWindow *window;
	sf::Vector2f gravity;
	Resource *resource;
	int points;
	Game game;
	Key key;
public:
	Engine();
	void draw();											//rysowanie wszystkich elementow na planszy
	void start();											//inicjalizacja wszystkich elementow
	void initResource();									//inictalizacja zasobow
	void initKey();											//inicjalizacja poprawnych klawiszy strzalek
	void switchKey();										//zmiana klawiszy strzalek
	void setBoard();										//ustawia plansze i inicjalizuje elementy
	void keyboardPlayer(Player *player);					//spradza czy zostaly wcisniete klawisze strzalek
	void newLevel();										//inicjuje nowy poziom gry
	void newElements();										//inicjalizuje nowa platforme i ew. bonus
	void newBonus(Floor *floor);							//tworzy nowy bonus na platformie
	Floor * randomFloor(int number, sf::Vector2f pos);		//losuje nowy typ platformy
	void checkAndDeleteLastFloor();							//sprawdza czy platforma nie wyszla poza plansze i kasuje ja
	void checkAndDeleteLastBonus();							//sprawdza czy bonus nie wyszedl poza plansze i kasuje go
	void moveFloor();										//poruszanie platfroma ruszajaca sie
	void bonusPoints(int point);							//dodaje dodatkowe punkty grze
	void playerIsInRectGravity(Player * player);			//sprawdza czy player jest w obszarze przyspieszenia 
	void player();											//zarzadzanie player
	bool collisionPlayerWithFloors(Player * player);		//sprawdzanie czy zaszla kolizja platformy z playerem
	void collisionPlayerWithBonus(Player *player);			//sprawdzanie kolizji bonusu z playerem
	void checkAndDeletePlayers();							//sprawdzanie czy player nie spadl
	void findAndDeletePlayer(Player *player);				//szuka i kasuje podanego player
	void checkGame();										//sprawdza i aktualizuje stan gry
	void initParam();										//inicjalizuje poczatkowe parametry gry
	void deleteAll();										//kasuje wszystkie dane
	void resetView();										//resetuje widok okna
	void enemy();											//zarzadzanie przeciwnikami
	~Engine();
};