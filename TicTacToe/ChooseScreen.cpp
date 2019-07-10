//
//  ChooseScreen.cpp
//  TicTacToe
//
//  Created by Arnav Chandra on 7/8/19.
//  Copyright © 2019 Arnav Chandra. All rights reserved.
//

#include "ChooseScreen.hpp"
#include <iostream>

ChooseScreen::ChooseScreen()
{
    
}



int ChooseScreen::Run(sf::RenderWindow &App)
{
    sf::Texture hosttext;
    hosttext.loadFromFile("/Users/arnavchandra/Desktop/tictactoe/TicTacToe/assets/hostbutton.png");
    sf::Sprite hostbuttonSprite;
    hostbuttonSprite.setTexture(hosttext);
    hostbuttonSprite.setPosition(300, 200);
    sf::Texture jointext;
    jointext.loadFromFile("/Users/arnavchandra/Desktop/tictactoe/TicTacToe/assets/joinbutton.png");
    sf::Sprite joinbuttonSprite;
    joinbuttonSprite.setTexture(jointext);
    joinbuttonSprite.setPosition(300, 550);
    while(true)
    {
        while (App.isOpen())
        {
            sf::Event event;
            while (App.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    App.close();
                    return 0;
                }
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    sf::Vector2i coord = sf::Mouse::getPosition();
                    int x = coord.x;
                    int y = coord.y;
                    if(hostClicked(x, y))
                        std::cout << "host clicked" << std::endl;
                    if(joinClicked(x, y))
                        std::cout << "join clicked" << std::endl;
                }
                
            }
            App.clear(sf::Color(255, 255, 255));
            App.draw(hostbuttonSprite);
            App.draw(joinbuttonSprite);
            App.display();
        }
    }
    return 0;
}

bool ChooseScreen::hostClicked(int x, int y)
{
    return x >= 1240 && y >= 2260 && x <= 1640 && y <= 2490;
}

bool ChooseScreen::joinClicked(int x, int y)
{
    return x >= 1240 && y >= 2620 && x <= 1640 && y <= 2840;
}
