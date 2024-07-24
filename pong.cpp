#include "pong.h"

Pong::Pong() 
{
	paddle1 = std::make_unique<Paddle>(paddleSize, paddle1InitPos);
	paddle2 = std::make_unique<Paddle>(paddleSize, paddle2InitPos);
	ball = std::make_unique<Ball>(ballRadius, ballInitPos);
};

void Pong::draw(sf::RenderWindow& window) {
	paddle1->draw(window);
	paddle2->draw(window);
	ball->draw(window);
};