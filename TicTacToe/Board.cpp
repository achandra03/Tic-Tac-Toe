//
//  Board.cpp
//  TicTacToe
//
//  Coporight © 2019 Arnav Chandra. All rights reserved.
//
#include "Board.h"
#define x 'x'
#define o 'o'

Board::Board()
{

}

int Board::checkWin()
    {
        //Check for diagonal wins
        if((board[0][0] == x && board[1][1] == x && board[2][2] == x) || (board[0][2] == x && board[1][1] == x && board[2][0] == x))
            return X_WIN;
        if((board[0][0] == o && board[1][1] == o && board[2][2] == o) || (board[0][2] == o && board[1][1] == o && board[2][0] == o))
            return O_WIN;
        
        //Check for vertical wins
        if((board[0][0] == x && board[1][0] == x && board[2][0] == x) || (board[0][1] == x && board[1][1] == x && board[2][1] == x) || (board[0][2] == x && board[1][2] == x && board[2][2] == x))
            return X_WIN;
        if((board[0][0] == o && board[1][0] == o && board[2][0] == o) || (board[0][1] == o && board[1][1] == o && board[1][2] == o) || (board[2][0] == o && board[2][1] == o && board[2][2] == o))
            return O_WIN;
        
        //Check for horizontal wins
        if((board[0][0] == x && board[0][1] == x && board[0][2] == x) || (board[1][0] == x && board[1][1] == x && board[1][2] == x) || (board[2][0] == x && board[2][1] == x && board[2][2] == x))
            return X_WIN;
        if((board[0][0] == o && board[0][1] == o && board[0][2] == o) || (board[1][0] == o && board[1][1] == o && board[1][2] == o) || (board[2][0] == o && board[2][1] == o && board[2][2] == o))
            return O_WIN;
        return -1;
    }

/*void Board::setPiece(char player, int x, int y)
    {
        board[x][y] = player;
    }
*/
