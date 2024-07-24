#pragma once
#include <memory>
#include <SFML/Graphics.hpp>

#include "settings.h"
#include "paddle.h"
#include "ball.h"

class Pong {
public:
	Pong();
	void update(float dt);
	void draw(sf::RenderWindow& window);

private:
	sf::Vector2f getInput(sf::Keyboard::Key up, sf::Keyboard::Key down);


	const sf::Vector2f paddleSize = sf::Vector2f(25, 100);
	const sf::Vector2f ballSize = sf::Vector2f(20, 20);
	const float paddleSpeed = 250.f;
	const float ballSpeed = 400.f;
	const sf::Vector2f ballInitPos = sf::Vector2f(Settings::WINDOW_WIDTH / 2 - ballSize.x / 2, Settings::WINDOW_HEIGHT / 2 - ballSize.y / 2);
	const sf::Vector2f paddle1InitPos = sf::Vector2f(paddleSize.x, Settings::WINDOW_HEIGHT / 2 - (paddleSize.y / 2));
	const sf::Vector2f paddle2InitPos = sf::Vector2f(Settings::WINDOW_WIDTH - paddleSize.x * 2, Settings::WINDOW_HEIGHT / 2 - (paddleSize.y / 2));

	std::unique_ptr<Paddle> paddle1;
	std::unique_ptr<Paddle> paddle2;
	std::unique_ptr<Ball> ball;

};