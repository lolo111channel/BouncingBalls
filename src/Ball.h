#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

class Ball : public sf::CircleShape {

private:
	sf::Vector2f direction = sf::Vector2f(1.0, 1.0);
	float movementSpeed = 0.5;

public:
	Ball(double size) : sf::CircleShape(size) {}
	Ball(double size, float x, float y);


	void moveBall(sf::Time deltaTime);
	bool checkCollision(Ball& ball);
	void reboundFromBall(Ball& ball);
	void setDirection(float x, float y);
};


#pragma once

