#include "pong.h"

Pong::Pong() 
{
	paddle1 = std::make_unique<Paddle>(1);
	paddle2 = std::make_unique<Paddle>(2);
	ball = std::make_unique<Ball>();

	topBorder = std::make_unique<sf::RectangleShape>(borderSize);
	bottomBorder = std::make_unique<sf::RectangleShape>(borderSize);
	middleBorder = std::make_unique<sf::RectangleShape>(sf::Vector2f(borderSize.y, borderSize.x));

	topBorder->setPosition(sf::Vector2f(0, 0));
	bottomBorder->setPosition(sf::Vector2f(0, Settings::WINDOW_HEIGHT - borderSize.y));
	middleBorder->setPosition(sf::Vector2f(Settings::WINDOW_WIDTH / 2 - borderSize.y / 2, 0));


	    // Create a graphical text to display
    if (!font.loadFromFile("Teko-Bold.ttf"))
        throw EXIT_FAILURE;
	
	updateScoreText();

	scoreSoundBuffer = sf::SoundBuffer();
	if (!scoreSoundBuffer.loadFromFile("ScoreSound.wav"))
		throw EXIT_FAILURE;

};

void Pong::update(float dt) {

	sf::Vector2f paddle1Dir = Pong::getInput(sf::Keyboard::A, sf::Keyboard::D);

	if (paddle1Dir != sf::Vector2f(0, 0))
		paddle1->update(paddle1Dir, dt);

	sf::Vector2f paddle2Dir = Pong::getInput(sf::Keyboard::Left, sf::Keyboard::Right);

	if (paddle2Dir != sf::Vector2f(0, 0))
		paddle2->update(paddle2Dir, dt);

	ball->update(*paddle1->shape, *paddle2->shape, dt);

	if (ball->paddle1Scored) {
		++paddle1Score;
		updateScoreText();
		ball->paddle1Scored = false;

		ScoreSound = sf::Sound();
		ScoreSound.setBuffer(scoreSoundBuffer);
		ScoreSound.play();
	}
	else if (ball->paddle2Scored) {
		++paddle2Score;
		updateScoreText();
		ball->paddle2Scored = false;

		ScoreSound = sf::Sound();
		ScoreSound.setBuffer(scoreSoundBuffer);
		ScoreSound.play();
	}

}

void Pong::updateScoreText() {

	paddle1ScoreText = sf::Text(std::to_string(paddle1Score), font, 50);
	paddle1ScoreText.setPosition(paddle1ScoreTextPos);

	paddle2ScoreText = sf::Text(std::to_string(paddle2Score), font, 50);
	paddle2ScoreText.setPosition(paddle2ScoreTextPos);

}

void Pong::draw(sf::RenderWindow& window) {
	paddle1->draw(window);
	paddle2->draw(window);
	ball->draw(window);

	window.draw(*topBorder);
	window.draw(*bottomBorder);
	window.draw(*middleBorder);

	window.draw(paddle1ScoreText);
	window.draw(paddle2ScoreText);

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