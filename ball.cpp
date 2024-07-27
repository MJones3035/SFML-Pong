#include "ball.h"

Ball::Ball()
{
	shape = std::make_unique<sf::RectangleShape>(size);
	//shapeTrail = std::make_unique<sf::RectangleShape>(ballSize);
	//shape->setPosition(ballInitPos);
	shape->setFillColor(sf::Color::Cyan);
	shape->setOrigin(sf::Vector2f(size.x / 2, size.y / 2));

	//shapeTrail->setPosition(ballInitPos);
	//shapeTrail->setFillColor(sf::Color(0, 255, 255, 100));
	speed = initSpeed;
	initPos = ballInitPos;

	paddleHitSoundBuffer = sf::SoundBuffer();
	if (!paddleHitSoundBuffer.loadFromFile("PaddleHitSound.wav"))
		throw EXIT_FAILURE;

	borderHitSoundBuffer = sf::SoundBuffer();
	if (!borderHitSoundBuffer.loadFromFile("BorderHitSound.wav"))
		throw EXIT_FAILURE;

	reset(0.f);
}

void Ball::update(sf::RectangleShape& paddle1, sf::RectangleShape& paddle2, float dt) {

	durTime += dt;

	if (durTime > resetDur) {



		handleCollisionBounce(paddle1, paddle2);

		sf::Vector2f vec = Utils::normalizeVecF(dir) * speed * dt;

		// window left and right collisions
		if (shape->getGlobalBounds().left + size.x < 0.f) {
			reset(-1.f);
			paddle2Scored = true;
		}
		else if (shape->getGlobalBounds().left > Settings::WINDOW_WIDTH) {
			reset(1.f);
			paddle1Scored = true;
		}
		else {
			pos += vec;
		}

		shape->setPosition(pos);
		//shapeTrail->setPosition(pos - vec * 100.f);
		
	}

};

void Ball::handleCollisionBounce(sf::RectangleShape& paddle1, sf::RectangleShape& paddle2) {

	// window top and bottom collisions
	if (shape->getGlobalBounds().top < 0.f) {
		dir.y = abs(dir.y);
		speed *= speedMult;

		borderHitSound = sf::Sound();
		borderHitSound.setBuffer(borderHitSoundBuffer);
		borderHitSound.play();
	}
	else if (shape->getGlobalBounds().top + size.y > Settings::WINDOW_HEIGHT) {
		dir.y = -abs(dir.y);
		speed *= speedMult;

		borderHitSound = sf::Sound();
		borderHitSound.setBuffer(borderHitSoundBuffer);
		borderHitSound.play();
	}

	// if ball collides with paddle
	if (shape->getGlobalBounds().intersects(paddle1.getGlobalBounds()) && dir.x < 0.f)
	{
		
		if (shape->getGlobalBounds().top > paddle1.getGlobalBounds().top + paddle1.getSize().y && shape->getGlobalBounds().left < paddle1.getGlobalBounds().left + paddle1.getSize().x) {
			dir.y = abs(dir.y);
		}
		else if (shape->getGlobalBounds().top + size.y < paddle1.getGlobalBounds().top && shape->getGlobalBounds().left < paddle1.getGlobalBounds().left + paddle1.getSize().x)
		{
			dir.y = -abs(dir.y);
		}
		else {
			dir.x = abs(dir.x);
			std::cout << dir.x << '\n';
		}

		paddleHitSound = sf::Sound();
		paddleHitSound.setBuffer(paddleHitSoundBuffer);
		paddleHitSound.play();

	}
	else if (shape->getGlobalBounds().intersects(paddle2.getGlobalBounds())  && dir.x > 0.f) {

		if (shape->getGlobalBounds().top > paddle2.getGlobalBounds().top + paddle1.getSize().y && shape->getGlobalBounds().left + size.x > paddle2.getGlobalBounds().left) {
			dir.y = abs(dir.y);
		}
		else if (shape->getGlobalBounds().top + size.y < paddle2.getGlobalBounds().top && shape->getGlobalBounds().left + size.x > paddle2.getGlobalBounds().left)
		{
			dir.y = -abs(dir.y);
		}
		else {
			dir.x = -abs(dir.x);
		}

		paddleHitSound = sf::Sound();
		paddleHitSound.setBuffer(paddleHitSoundBuffer);
		paddleHitSound.play();

	}

}

void Ball::reset(float xDir) {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<float> dist(0.4f, 0.8f);

	float randXDir = dist(mt);


	if (xDir == 0.f) {
		dist = std::uniform_real_distribution<float> (-1, 1);
		float randNum = dist(mt);
		xDir = (randNum >= 0.f) ? 1 : -1;

	}

	randXDir *= xDir;

	dist = std::uniform_real_distribution<float> (0.f, 1.0f);

	float randYDir = dist(mt);

	dist = std::uniform_real_distribution<float>(size.y, Settings::WINDOW_HEIGHT - size.y);

	pos = sf::Vector2f(initPos.x, dist(mt));

	shape->setPosition(pos);

	speed = initSpeed;

	dir = Utils::normalizeVecF(sf::Vector2f(randXDir, randYDir));

	durTime = 0.f;
}


void Ball::draw(sf::RenderWindow& window) {
	window.draw(*shape);
	//window.draw(*shapeTrail);
};