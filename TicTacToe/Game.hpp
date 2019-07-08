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
#include <SFML/Window/Mouse.hpp>
class Game
{
private:
    //sf::Sprite oSprite;
    //sf::Sprite xSprite;
    sf::Sprite boardSprite;
    sf::Texture xTexture;
    sf::Texture oTexture;
    //sf::Texture boardTexture;
public:
    void render();
    void start();
    int handleX(int x);
    int handleY(int y);
    Game();
    Board b;
};
#endif /* Game_hpp */
