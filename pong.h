#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

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
	void updateScoreText();

	const sf::Vector2f borderSize = sf::Vector2f(Settings::WINDOW_WIDTH, 5.f);

	std::unique_ptr<Paddle> paddle1;
	std::unique_ptr<Paddle> paddle2;
	std::unique_ptr<Ball> ball;

	int paddle1Score = 0;
	int paddle2Score = 0;

	sf::Font font;
	sf::Text paddle1ScoreText;
	sf::Text paddle2ScoreText;

	sf::SoundBuffer scoreSoundBuffer;

	sf::Sound ScoreSound;

	const sf::Vector2f paddle1ScoreTextPos = sf::Vector2f(Settings::WINDOW_WIDTH / 2 - 100.f, 25.f);
	const sf::Vector2f paddle2ScoreTextPos = sf::Vector2f(Settings::WINDOW_WIDTH / 2 + 90.f, 25.f);

	std::unique_ptr<sf::RectangleShape> topBorder;
	std::unique_ptr<sf::RectangleShape> bottomBorder;
	std::unique_ptr<sf::RectangleShape> middleBorder;



};