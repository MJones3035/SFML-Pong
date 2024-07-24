#include "pong.h"

Pong::Pong() 
{
	paddle1 = std::make_unique<Paddle>(paddleSize, paddleSpeed, paddle1InitPos);
	paddle2 = std::make_unique<Paddle>(paddleSize, paddleSpeed, paddle2InitPos);
	ball = std::make_unique<Ball>(ballSize, ballSpeed, ballInitPos);
};

void Pong::update(float dt) {

	sf::Vector2f paddle1Dir = Pong::getInput(sf::Keyboard::A, sf::Keyboard::D);

	if (paddle1Dir != sf::Vector2f(0, 0))
		paddle1->update(paddle1Dir, dt);

	sf::Vector2f paddle2Dir = Pong::getInput(sf::Keyboard::Left, sf::Keyboard::Right);

	if (paddle2Dir != sf::Vector2f(0, 0))
		paddle2->update(paddle2Dir, dt);

	ball->update(*paddle1->shape, *paddle2->shape, dt);

}

void Pong::draw(sf::RenderWindow& window) {
	paddle1->draw(window);
	paddle2->draw(window);
	ball->draw(window);
};

sf::Vector2f Pong::getInput(sf::Keyboard::Key upKey, sf::Keyboard::Key downKey) {
	sf::Vector2f vec = sf::Vector2f(0.f, 0.f);

	if (sf::Keyboard::isKeyPressed(upKey)) {
		vec += sf::Vector2f(0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(downKey)) {
		vec += sf::Vector2f(0.f, 1.f);
	}

	return vec;
};