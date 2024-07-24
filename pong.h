#pragma once
#include <memory>
#include <SFML/Graphics.hpp>

#include "settings.h"
#include "paddle.h"
#include "ball.h"

class Pong {
public:
	Pong();
	void draw(sf::RenderWindow& window);

private:
	const sf::Vector2f paddleSize = sf::Vector2f(25, 100);
	const float ballRadius = 15.f;
	const sf::Vector2f ballInitPos = sf::Vector2f(Settings::WINDOW_WIDTH / 2 - ballRadius, Settings::WINDOW_HEIGHT / 2 - ballRadius);
	const sf::Vector2f paddle1InitPos = sf::Vector2f(paddleSize.x, Settings::WINDOW_HEIGHT / 2 - (paddleSize.y / 2));
	const sf::Vector2f paddle2InitPos = sf::Vector2f(Settings::WINDOW_WIDTH - paddleSize.x * 2, Settings::WINDOW_HEIGHT / 2 - (paddleSize.y / 2));

	std::unique_ptr<Paddle> paddle1;
	std::unique_ptr<Paddle> paddle2;
	std::unique_ptr<Ball> ball;

};