//
//  Game.h
//  TicTacToe
//
//  Created by Arnav Chandra on 6/29/19.
//  Copyright © 2019 Arnav Chandra. All rights reserved.
//

#ifndef Game_h
#define Game_h
#include <SFML/Graphics.hpp>
#include "Board.h"
#endif
class Game
{
    private:
        sf::RenderWindow window;
    
    public:
        void start();
        void render();
        Game() : window(sf::VideoMode(1000, 1000), "Tic Tac Toe") {}
    
};


