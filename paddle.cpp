#include "paddle.h"

Paddle::Paddle(sf::Vector2f size, sf::Vector2f initPos)
{
	shape = std::make_unique<sf::RectangleShape>(size);
	shape->setPosition(initPos);
	pos = initPos;
}

void Paddle::draw(sf::RenderWindow& window) {
	window.draw(*shape);
}