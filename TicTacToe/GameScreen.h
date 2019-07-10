//
//  GameScreen.h
//  TicTacToe
//
//  Created by Arnav Chandra on 7/8/19.
//  Copyright © 2019 Arnav Chandra. All rights reserved.
//

#ifndef GameScreen_h
#define GameScreen_h
#include <iostream>
#include "cScreen.hpp"
#include "Game.hpp"
#include <SFML/Graphics.hpp>
//Class for the screen running the game
class GameScreen : public cScreen
{
public:
    GameScreen(void);
    virtual int Run(sf::RenderWindow &App);
};

#endif /* GameScreen_h */
