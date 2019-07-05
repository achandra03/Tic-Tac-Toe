//
//  Board.h
//  TicTacToe
//
//  Copyright © 2019 Arnav Chandra. All rights reserved.
//

#ifndef Board_h
#define Board_h
#include <SFML/Graphics.hpp>
#endif
class Board
{
    private:
        const int O_WIN = 0;
        const int X_WIN = 1;
    
    public:
        sf::Sprite boardSprite;
        sf::Sprite xSprite;
        sf::Sprite oSprite;
        int checkWin();
        char board[3][3];
       // void setPiece(char player, int x, int y);
        Board();
};


