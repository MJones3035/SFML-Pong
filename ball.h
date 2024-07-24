#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>
#include <string>

#include "settings.h"
#include "utils.h"

class Ball {
public:
	Ball(sf::Vector2f ballSize, float ballSpeed, sf::Vector2f ballInitPos);
	void update(sf::RectangleShape& paddle1, sf::RectangleShape& paddle2, float dt);
	void draw(sf::RenderWindow& window);

private:
	void reset(float xDir);


	std::unique_ptr<sf::RectangleShape> shape;
	sf::Vector2f initPos;

	sf::Vector2f size;
	float baseSpeed;
	float speed;
	float speedInc = 25.f;
	sf::Vector2f dir;
	sf::Vector2f pos;

	float durTime = 0.f;
	const float resetDur = 1.f;

};