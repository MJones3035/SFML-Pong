#include "paddle.h"

Paddle::Paddle(int num)
{
	shape = std::make_unique<sf::RectangleShape>(size);

	switch (num) 
	{
	case 1:
		pos = paddle1InitPos; break;
	case 2:
		pos = paddle2InitPos; break;
	default:
		break;
	}

	shape->setPosition(pos);
	shape->setOrigin(size.x / 2, size.y / 2);
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