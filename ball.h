#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <random>
#include <iostream>
#include <string>

#include "settings.h"
#include "utils.h"

class Ball {
public:
	Ball();
	void update(sf::RectangleShape& paddle1, sf::RectangleShape& paddle2, float dt);
	void draw(sf::RenderWindow& window);

	bool paddle1Scored = false;
	bool paddle2Scored = false;

private:
	void reset(float xDir);
	void handleCollisionBounce(sf::RectangleShape& paddle1, sf::RectangleShape& paddle2);



	std::unique_ptr<sf::RectangleShape> shape;
	//std::unique_ptr<sf::RectangleShape> shapeTrail;
	sf::Vector2f initPos;
	const sf::Vector2f ballInitPos = sf::Vector2f(Settings::WINDOW_WIDTH / 2 - size.x / 2, Settings::WINDOW_HEIGHT / 2 - size.y / 2);

	sf::SoundBuffer borderHitSoundBuffer;
	sf::SoundBuffer paddleHitSoundBuffer;

	sf::Sound borderHitSound;
	sf::Sound paddleHitSound;

	const sf::Vector2f size = sf::Vector2f(20, 20);
	const float initSpeed = 400.f;
	float speed;
	float speedMult = 1.05f;
	sf::Vector2f dir;
	sf::Vector2f pos;

	float durTime = 0.f;
	const float resetDur = 1.f;

};