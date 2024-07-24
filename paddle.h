#pragma once
#include <SFML/Graphics.hpp>

#include "settings.h"

class Paddle {
public:
	Paddle(sf::Vector2f paddleSize, float paddleSpeed, sf::Vector2f paddleInitPos);
	void update(sf::Vector2f dir, float dt);
	void draw(sf::RenderWindow& window);

	std::unique_ptr<sf::RectangleShape> shape;

private:
	void move(sf::Vector2f dir, float dt);

	sf::Vector2f initPos;

	sf::Vector2f size;
	float speed;
	sf::Vector2f pos;

};