#pragma once
#include <SFML/Graphics.hpp>

class Paddle {
public:
	Paddle(sf::Vector2f size, sf::Vector2f initPos);
	void draw(sf::RenderWindow& window);

	sf::Vector2f pos;

private:
	std::unique_ptr<sf::RectangleShape> shape;
};