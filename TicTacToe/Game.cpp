//
//  Game.cpp
//  TicTacToe
//
//  Created by Arnav Chandra on 7/4/19.
//  Copyright © 2019 Arnav Chandra. All rights reserved.
//

#include "Game.hpp"
#include <iostream>

bool X_turn = true;

Game::Game()
{

}

void Game::render(sf::RenderWindow &window)
{
    if(window.isOpen())
    {
        window.draw(boardSprite);
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(b.board[i][j] == 'x')
                {
                    sf::Sprite xSprite;
                    xSprite.setTexture(xTexture);
                    xSprite.setPosition(sf::Vector2f(333 * i + 50, 333 * j + 50));
                    window.draw(xSprite);
                }
                else if(b.board[i][j] == 'o')
                {
                    sf::Sprite oSprite;
                    oSprite.setTexture(oTexture);
                    oSprite.setPosition(sf::Vector2f(333 * i + 50, 333 * j + 50));
                    window.draw(oSprite);
                }
            }
        }
    }
}

void Game::start(sf::RenderWindow &window)
{
    sf::Texture boardTexture;
    boardTexture.loadFromFile("/Users/arnavchandra/Desktop/tictactoe/TicTacToe/assets/board.png");
    boardSprite.setTexture(boardTexture);
    //sf::Texture xTexture;
    xTexture.loadFromFile("/Users/arnavchandra/Desktop/tictactoe/TicTacToe/assets/X.png");
    //xSprite.setTexture(xTexture);
    //sf::Texture oTexture;
    oTexture.loadFromFile("/Users/arnavchandra/Desktop/tictactoe/TicTacToe/assets/o.png");
    //oSprite.setTexture(oTexture);
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
                    if(X_turn && b.board[boardX][boardY] != 'x' && b.board[boardX][boardY] != 'o')
                    {
                        b.board[boardX][boardY] = 'x';
                        X_turn = false;
                    }
                    else if(!X_turn && b.board[boardX][boardY] != 'x' && b.board[boardX][boardY] != 'o')
                    {
                        b.board[boardX][boardY] = 'o';
                        X_turn = true;
                    }
                }
            }
            window.clear(sf::Color(255, 255, 255));
            render(window);
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
