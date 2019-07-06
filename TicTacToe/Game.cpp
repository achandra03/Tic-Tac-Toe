//
//  Game.cpp
//  TicTacToe
//
//  Created by Arnav Chandra on 7/4/19.
//  Copyright © 2019 Arnav Chandra. All rights reserved.
//

#include "Game.hpp"
#include <iostream>

sf::RenderWindow window(sf::VideoMode(1000, 1000), "Tic Tac Toe");

Game::Game()
{

}

void Game::render()
{
    if(window.isOpen())
    {
        window.draw(boardSprite);
    }
}

void Game::start()
{
    sf::Texture boardTexture;
    boardTexture.loadFromFile("/Users/arnavchandra/Desktop/tictactoe/TicTacToe/assets/board.png");
    boardSprite.setTexture(boardTexture);
    sf::Texture xTexture;
    xTexture.loadFromFile("/Users/arnavchandra/Desktop/tictactoe/TicTacToe/assets/X.png");
    xSprite.setTexture(xTexture);
    sf::Texture oTexture;
    oTexture.loadFromFile("/Users/arnavchandra/Desktop/tictactoe/TicTacToe/assets/o.png");
    oSprite.setTexture(oTexture);
    while(true)
    {
        while(window.isOpen())
        {
            sf::Event event;
            if(window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                    return;
                }
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    sf::Vector2i pos = sf::Mouse::getPosition();
                    int boardX = handleX(pos.x);
                    int boardY = handleY(pos.y);
                    std::cout << "x: " << boardX << std::endl;
                    std::cout << "y: " << boardY << std::endl;
                    //std::cout << "x: " << pos.x << std::endl;
                    //std::cout << "y: " << pos.y << std::endl;
                }
            }
            window.clear(sf::Color(255, 255, 255));
            window.draw(boardSprite);
            window.display();
        }
    }
}

int Game::handleX(int x)
{
    if(x <= 1280)
        return 0;
    if(x > 1280 && x <= 1580)
        return 1;
    return 2;
}

int Game::handleY(int y)
{
    if(y <= 2410)
        return 0;
    if(y > 2410 && y <= 2705)
        return 1;
    return 2;
}
