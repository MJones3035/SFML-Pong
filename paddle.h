#pragma once
#include <SFML/Graphics.hpp>

#include "settings.h"

class Paddle {
public:
	Paddle(int num);
	void update(sf::Vector2f dir, float dt);
	void draw(sf::RenderWindow& window);

	std::unique_ptr<sf::RectangleShape> shape;

private:
	void move(sf::Vector2f dir, float dt);

	sf::Vector2f initPos;
	const sf::Vector2f paddle1InitPos = sf::Vector2f(size.x, Settings::WINDOW_HEIGHT / 2 - (size.y / 2));
	const sf::Vector2f paddle2InitPos = sf::Vector2f(Settings::WINDOW_WIDTH - size.x * 2, Settings::WINDOW_HEIGHT / 2 - (size.y / 2));
	const sf::Vector2f size = sf::Vector2f(25, 100);
	const float speed = 300.f;
	sf::Vector2f pos;

};