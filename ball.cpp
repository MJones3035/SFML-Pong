#include "ball.h"

Ball::Ball(sf::Vector2f ballSize, float ballSpeed, sf::Vector2f ballInitPos)
{
	shape = std::make_unique<sf::RectangleShape>(ballSize);
	//shapeTrail = std::make_unique<sf::RectangleShape>(ballSize);
	shape->setPosition(ballInitPos);
	shape->setFillColor(sf::Color::Cyan);

	//shapeTrail->setPosition(ballInitPos);
	//shapeTrail->setFillColor(sf::Color(0, 255, 255, 100));

	size = ballSize;
	speed = ballSpeed;
	baseSpeed = speed;
	initPos = ballInitPos;

	reset(0.f);
}

void Ball::update(sf::RectangleShape& paddle1, sf::RectangleShape& paddle2, float dt) {

	durTime += dt;

	if (durTime > resetDur) {


		sf::Vector2f vec = Utils::normalizeVecF(dir) * speed * dt;
		// could normalize

		// window top and bottom collisions
		if (shape->getGlobalBounds().top + vec.y < 0.f || shape->getGlobalBounds().top + size.y + vec.y > Settings::WINDOW_HEIGHT) {
			vec.y = -vec.y;
			dir.y = -dir.y;


			speed += speedInc;
		}



		// if ball collides with paddle
		if (shape->getGlobalBounds().intersects(paddle1.getGlobalBounds()))
		{

			// paddle 1 x bounce
			if (shape->getGlobalBounds().left + vec.x < paddle1.getGlobalBounds().left + paddle1.getSize().x) {
				vec.x = -vec.x;
				dir.x = -dir.x;


				speed += speedInc;
			}
			// paddle 1 y bounce
			else if (shape->getGlobalBounds().top + size.y + vec.y > paddle1.getGlobalBounds().top || shape->getGlobalBounds().top + vec.y < paddle1.getGlobalBounds().top + paddle1.getSize().y) {
				//vec.y = -vec.y;
				//dir.y = -dir.y;

				if (vec.x < 0) {
					vec.x = abs(vec.x);
					dir.x = abs(dir.x);

					speed += speedInc;
				}

			}

		}
		else if (shape->getGlobalBounds().intersects(paddle2.getGlobalBounds())) {


			// paddle 2 x bounce
			if (shape->getGlobalBounds().left + size.x + vec.x > paddle2.getGlobalBounds().left) {
				vec.x = -vec.x;
				dir.x = -dir.x;


				speed += speedInc;
			}
			// paddle 2 y bounce
			else if (shape->getGlobalBounds().top + size.y + vec.y > paddle2.getGlobalBounds().top || shape->getGlobalBounds().top + vec.y < paddle2.getGlobalBounds().top + paddle2.getSize().y) {
				//vec.y = -vec.y;
				//dir.y = -dir.y;

				if (vec.x > 0) {
					vec.x = -abs(vec.x);
					dir.x = -abs(dir.x);


					speed += speedInc;
				}


			}
		}


		// window left and right collisions
		if (shape->getGlobalBounds().left + vec.x < 0.f) {
			reset(-1.f);
		}
		else if (shape->getGlobalBounds().left + size.x + vec.x > Settings::WINDOW_WIDTH) {
			reset(1.f);
		}
		else {
			pos += vec;
		}

		shape->setPosition(pos);
		//shapeTrail->setPosition(pos - vec * 100.f);
		
	}

};

void Ball::reset(float xDir) {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<float> dist(0.4f, 0.8f);

	float randXDir = (xDir == 0.f) ? dist(mt) : dist(mt) * xDir;

	dist = std::uniform_real_distribution<float> (0.f, 1.0f);

	float randYDir = dist(mt);

	pos = initPos;

	speed = baseSpeed;

	dir = Utils::normalizeVecF(sf::Vector2f(randXDir, randYDir));

	durTime = 0.f;
}


void Ball::draw(sf::RenderWindow& window) {
	window.draw(*shape);
	//window.draw(*shapeTrail);
};