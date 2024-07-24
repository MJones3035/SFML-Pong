#include "ball.h"

Ball::Ball(float radius, sf::Vector2f initPos)
{
	shape = std::make_unique<sf::CircleShape>(radius);
	shape->setPosition(initPos);
	shape->setFillColor(sf::Color::Cyan);
	pos = initPos;
}

void Ball::draw(sf::RenderWindow& window) {
	window.draw(*shape);
}