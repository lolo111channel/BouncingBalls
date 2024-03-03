#include "./Ball.h"


Ball::Ball(double size, float x, float y) {
	setRadius(size);
	setPosition(x, y);
	setOrigin(size / 2, size / 2);
}

void Ball::moveBall(sf::Time deltaTime) {

	if (getPosition().y >= 720 || getPosition().y <= 0) {

		direction.y = -direction.y;

	}

	if (getPosition().x >= 1280 || getPosition().x <= 0) {

		direction.x = -direction.x;

	}

	move(direction.x * movementSpeed * deltaTime.asMilliseconds(), direction.y * movementSpeed * deltaTime.asMilliseconds());
}

bool Ball::checkCollision(Ball& ball) {

	sf::FloatRect rect1(sf::Vector2f(getPosition().x, getPosition().y),sf::Vector2f(getRadius() * 2, getRadius() * 2));
	sf::FloatRect rect2(sf::Vector2f(ball.getPosition().x, ball.getPosition().y), sf::Vector2f(ball.getRadius(), ball.getRadius()));

	return rect1.intersects(rect2);
}


void Ball::reboundFromBall(Ball& ball) {
	
	if (this != &ball) {
		if (checkCollision(ball)){
			direction.x = -direction.x;
			direction.y = -direction.y;
		}

	}
}

void Ball::setDirection(float x, float y) {
	direction.x = x;
	direction.y = y;
}
