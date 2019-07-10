//
//  ChooseScreen.hpp
//  TicTacToe
//
//  Created by Arnav Chandra on 7/8/19.
//  Copyright © 2019 Arnav Chandra. All rights reserved.
//

#ifndef ChooseScreen_hpp
#define ChooseScreen_hpp

#include "cScreen.hpp"
#include <SFML/Window/Mouse.hpp>


//Class for the user to choose whether to host or connect to a game
class ChooseScreen : public cScreen
{
    public:
        ChooseScreen(void);
        virtual int Run(sf::RenderWindow &App);
    private:
        bool hostClicked(int x, int y);
        bool joinClicked(int x, int y);
};

#endif /* ChooseScreen_hpp */
