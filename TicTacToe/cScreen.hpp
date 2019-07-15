//
//  cScreen.hpp
//  TicTacToe
//
//  Created by Arnav Chandra on 7/8/19.
//  Copyright © 2019 Arnav Chandra. All rights reserved.
//

#ifndef cScreen_hpp
#define cScreen_hpp

#include <SFML/Graphics.hpp>
class cScreen
{
    public :
        virtual int Run (sf::RenderWindow &window) = 0;
};


#endif /* cScreen_hpp */
