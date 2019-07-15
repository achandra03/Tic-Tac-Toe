//
//  main2.cpp
//  TicTacToe
//
//  Created by Arnav Chandra on 7/11/19.
//  Copyright © 2019 Arnav Chandra. All rights reserved.
//

#include <iostream>
#include "Game.hpp"
#include <SFML/Graphics.hpp>
#include "ClientGame.hpp"
#include "char2D.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Tic Tac Toe");
   /* ClientGame cg;
    cg.connect();
    char2D arr = cg.receiveData();
    std::cout << arr.arr[0][0] << std::endl;
    */
    Game g;
    g.clientStart(window);
}
