#include "paddle.h"

Paddle::Paddle(sf::Vector2f paddleSize, float paddleSpeed, sf::Vector2f paddleInitPos)
{
	shape = std::make_unique<sf::RectangleShape>(paddleSize);
	shape->setPosition(paddleInitPos);
	pos = paddleInitPos;

	size = paddleSize;
	speed = paddleSpeed;
	initPos = paddleInitPos;
};

void Paddle::update(sf::Vector2f dir, float dt) {
	Paddle::move(dir, dt);
};

void Paddle::move(sf::Vector2f dir, float dt) {
	sf::Vector2f vec = dir * speed * dt;

	if (shape->getGlobalBounds().top + vec.y > 0 && shape->getGlobalBounds().top + size.y + vec.y < Settings::WINDOW_HEIGHT)
	{
		pos += vec;

		shape->setPosition(pos);
	}

};

void Paddle::draw(sf::RenderWindow& window) {
	window.draw(*shape);
};