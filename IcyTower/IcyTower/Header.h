#pragma once
#include <SFML\Graphics.hpp>
#include <string>
const float PLAYER_HEIGHT = 48.0f;
const float PLAYER_WIDTH = 27.0f;
const int DIMENSION = 60;
const int WIDTH_SIDE = 100;
const int WINDOW_X = 800;
const int WINDOW_Y = 600;
const int BETWEEN = 40;						
const int NUMBER_LVL[5] = { 3,2,1,1,0 };					//limity dlugosci platform na kolejnych poziomach
const int LIMIT_LVL[5] = {20,50,80,110,200};				//limity punktowe na kolejne poziomy
const int MAX_NEMBER_STEPS = 35;							
const float RIGHT_LEFT_STOP_ACCELERATION = 0.3f;			
const float RIGHT_LEFT_ACCELERATION = 0.5f;
const float SUPER_JUMP_ACCELERATION = 11.f;
const float JUMP_ACCELERATION = 9.0f;
const float PLAYER_SPEED_XY_SUPER_JUMP = 5.0f;
const float PLAYER_MAX_SPEED_XY = 15.0f;
const float PLAYER_GRAVITY = 0.27f;
const float MOVING_FLOOR_VELOCITY = 0.27f;
const float SHADOW_FLOOR_MAX_VELOCITY = 5.0f;
const float SHADOW_FLOOR_ACCELARATE = 0.01f;
const int MOVING_FLOOR_MIN_INCREMENT_VELOCITY = 1;
const int MOVING_FLOOR_MAX_INCREMENT_VELOCITY = 7;
const int MULTIPLY = 10;
const int FPS = 60;
const char NAME_GAME[] = "Dom Tower";
const float GHOST_SPEED = 2.f;
const int GHOST_LIVE_TIME = 20;
const sf::Vector2f BANNER_POSITION(700.f, 20.f);							//pozycja bannera z punktami
const sf::IntRect GRAVITY_RECT(0,0,WINDOW_X,200);							
const sf::Vector2f GRAVITY(0.f, 0.2f);
const sf::Vector2f GRAVITY_ACCELERATION (0.f,0.15f);
const sf::Vector2f GRAVITY_STOP_ACCELERATION (0.f,0.05f);
const sf::Vector2f DEAD_WALL_POINTS_POSITION(600.0f,400.0f);
const sf::Vector2f PLAYER_SIDE_ACCELERATION(0.f, -1.5f);
const sf::Vector2f TELEPORT_POSITION(400.f, 100.f);							//pozycja pojawienia sie playera po spotkaniu z teleporem
enum direction {
	idle = 0,
	right = 1,
	left = -1
};
enum movement {
	idle1 = 0,
	walk1 = 1,
	walk2 = 2,
	walk3 = 3,
	walk4 = 4,
	jump1 = 5,
	jump2 = 6,
	jump3 = 7,
	jump = 8
};
enum Game {
	onGoing = 0,
	pause = 1,
	newGame = 2,
	close = 3
};
struct Key {
	sf::Keyboard::Key space;
	sf::Keyboard::Key right;
	sf::Keyboard::Key left;
};