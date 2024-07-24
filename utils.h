#pragma once
#include <SFML/Graphics.hpp>

class Utils {
public:
	static sf::Vector2f normalizeVecF(sf::Vector2f vec) {
		float length = sqrt(vec.x * vec.x + vec.y * vec.y);
		//float length = 1.f;

		float x = vec.x / length;
		float y = vec.y / length;

		return sf::Vector2f(x, y);
	}
};