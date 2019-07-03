//
//  Game.cpp
//  TicTacToe
//
//  Copyright © 2019 Arnav Chandra. All rights reserved.
//

#include "Game.h"
#include <SFML/Window/Mouse.hpp>
#include <iostream>
        void Game::render()
        {
            if(window.isOpen())
            {
                sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }
                window.clear(sf::Color(255, 255, 255));
                window.display();
            }
        }


        void Game::start()
        {
            while(true)
            {
                if(!window.isOpen())
                    break;
                render();
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    sf::Vector2i position = sf::Mouse::getPosition(window);
                    std::cout << "x :" << position.x << std::endl;
                    std::cout << "y :" << position.y << std::endl;
                }
            }
        }

