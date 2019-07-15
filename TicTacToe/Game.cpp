//
//  Game.cpp
//  TicTacToe
//
//  Created by Arnav Chandra on 7/4/19.
//  Copyright © 2019 Arnav Chandra. All rights reserved.
//

#include "Game.hpp"
#include <iostream>

bool serverTurn = true;

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
                if(b.arr[i][j] == 'x')
                {
                    sf::Sprite xSprite;
                    xSprite.setTexture(xTexture);
                    xSprite.setPosition(sf::Vector2f(333 * i + 50, 333 * j + 50));
                    window.draw(xSprite);
                }
                else if(b.arr[i][j] == 'o')
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

/*void Game::start(sf::RenderWindow &window)
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
 */

void Game::serverStart(sf::RenderWindow &window)
{
    sf::Texture boardTexture;
    boardTexture.loadFromFile("/Users/arnavchandra/Desktop/tictactoe/TicTacToe/assets/board.png");
    boardSprite.setTexture(boardTexture);
    xTexture.loadFromFile("/Users/arnavchandra/Desktop/tictactoe/TicTacToe/assets/X.png");
    oTexture.loadFromFile("/Users/arnavchandra/Desktop/tictactoe/TicTacToe/assets/o.png");
    ServerGame sg;
    sg.connect();
    while(true)
    {
        while(window.isOpen())
        {
            sf::Event event;
            if(window.pollEvent(event))
            {
                if(event.type == sf::Event::MouseLeft)
                {
                    continue;
                }
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                    return;
                }
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    sf::Vector2i pos = sf::Mouse::getPosition(window);
                    if(pos.x < 0 || pos.y < 0 || pos.x > 1000 || pos.y > 1000)
                        continue;
                    std::cout << "x: " << pos.x << " y: " << pos.y <<  std::endl;
                    int boardX = handleX(pos.x);
                    int boardY = handleY(pos.y);
                    if(b.arr[boardX][boardY] != 'x' && b.arr[boardX][boardY] != 'o')
                    {
                        b.arr[boardX][boardY] = 'o';
                        window.clear(sf::Color(255, 255, 255));
                        render(window);
                        window.display();
                        sg.sendData(b.arr);
                        char2D newBoard = sg.receiveData();
                        setBoard(newBoard);
                    }
                }
            }
            window.clear(sf::Color(255, 255, 255));
            render(window);
            window.display();
        }
    }
}

void Game::clientStart(sf::RenderWindow &window)
{
    sf::Texture boardTexture;
    boardTexture.loadFromFile("/Users/arnavchandra/Desktop/tictactoe/TicTacToe/assets/board.png");
    boardSprite.setTexture(boardTexture);
    xTexture.loadFromFile("/Users/arnavchandra/Desktop/tictactoe/TicTacToe/assets/X.png");
    oTexture.loadFromFile("/Users/arnavchandra/Desktop/tictactoe/TicTacToe/assets/o.png");
    ClientGame cg;
    cg.connect();
    while(true)
    {
        while(window.isOpen())
        {
            window.clear(sf::Color(255, 255, 255));
            render(window);
            window.display();
            if(serverTurn)
            {
                char2D newBoard = cg.receiveData();
                setBoard(newBoard);
                serverTurn = false;
            }
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
                    sf::Vector2i pos = sf::Mouse::getPosition(window);
                    if(pos.x < 0 || pos.y < 0 || pos.x > 1000 || pos.y > 1000)
                        continue;
                    std::cout << "x: " << pos.x << " y: " << pos.y <<  std::endl;
                    int boardX = handleX(pos.x);
                    int boardY = handleY(pos.y);
                    if(b.arr[boardX][boardY] != 'x' && b.arr[boardX][boardY] != 'o')
                    {
                        b.arr[boardX][boardY] = 'x';
                        cg.sendData(b.arr);
                        serverTurn = true;
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
    if(x <= 350)
        return 0;
    if(x > 350 && x <= 650)
        return 1;
    return 2;
}

int Game::handleY(int y)
{
    if(y <= 350)
        return 0;
    if(y > 350 && y <= 650)
        return 1;
    return 2;
}

void Game::setBoard(char2D board)
{
    b = board;
}
