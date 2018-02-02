#include "Background.h"



Background::Background(Resource &resource)
{
	resource.setBackground(sprite);
}

void Background::drawNow(sf::RenderWindow & Window,sf::Vector2f gravity)
{
	update(gravity);
	Window.draw(sprite);
}

sf::Vector2f Background::getPositionRemainder()
{
	int x, y;
	x = sprite.getPosition().x;
	y = sprite.getPosition().y;
	return sf::Vector2f(sprite.getPosition().x - x, sprite.getPosition().y - y);
}

void Background::update(sf::Vector2f gravity)
{
	sprite.move(gravity);
	sf::Vector2f vec = sprite.getPosition();
	if (vec.y > 0) {
		sprite.setPosition(sf::Vector2f(vec.x, vec.y-WINDOW_Y));
	}
}
Background::~Background()
{
}
