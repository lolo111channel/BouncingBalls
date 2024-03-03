#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "./Ball.h"




int main()
{
    auto window = sf::RenderWindow{ { 1280u, 720u }, "Boucing Balls" };
    window.setFramerateLimit(144);
    std::vector<Ball> balls;


    sf::Clock clock;

    while (window.isOpen()) {

        for (auto event = sf::Event{}; window.pollEvent(event);) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {

                if (event.mouseButton.button == sf::Mouse::Left) {

                    Ball newBall = Ball(15.0, sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                    newBall.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
                    balls.push_back(newBall);
                    std::cout << balls.size() << std::endl;
                }
            }
            
        }

        sf::Time deltaTime = clock.restart();
   

        for (auto& i : balls)
        {
            i.moveBall(deltaTime);
        }


        for (auto& i : balls) {
            for (auto& j : balls) {
                i.reboundFromBall(j);
            }
        }


        window.clear();


        for (auto& i : balls)
        {
            window.draw(i);
        }

        window.display();
    }
}