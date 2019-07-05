//
//  Game.cpp
//  TicTacToe
//
//  Created by Arnav Chandra on 7/4/19.
//  Copyright © 2019 Arnav Chandra. All rights reserved.
//

#include "Game.hpp"

void Game::render()
{
    if(window.isOpen())
    {
        sf::Sprite bs = b.boardSprite;
        window.draw(bs);
    }
}

void Game::start()
{
    while(true)
    {
        if(!window.isOpen())
            break;
        render();
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
