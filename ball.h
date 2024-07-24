#pragma once
#include <SFML/Graphics.hpp>

class Ball {
public:
	//Ball(sf::Vector2f size, sf::Vector2f initPos);
	Ball(float radius, sf::Vector2f initPos);
	void draw(sf::RenderWindow& window);

	sf::Vector2f pos;

private:
	std::unique_ptr<sf::CircleShape> shape;
};