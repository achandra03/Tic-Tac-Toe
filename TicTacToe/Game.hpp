//
//  Game.hpp
//  TicTacToe
//
//  Created by Arnav Chandra on 7/4/19.
//  Copyright © 2019 Arnav Chandra. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include "Board.h"
#include <SFML/Graphics.hpp>
class Game
{
private:
    sf::RenderWindow window;
public:
    void render();
    void start();
    Game() : window{sf::VideoMode(1000, 1000), "Tic Tac Toe"} {}
    Board b();
};
#endif /* Game_hpp */
