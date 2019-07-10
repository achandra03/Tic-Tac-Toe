#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "screens.hpp"
#include <iostream>
#include "GameScreen.h"
#include "ChooseScreen.hpp"
int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Tic Tac Toe");
    /*
    sf::Texture text;
    text.loadFromFile("/Users/arnavchandra/Desktop/tictactoe/TicTacToe/assets/board.png");
    sf::Sprite sprite;
    sprite.setTexture(text);
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Tic Tac Toe");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color(255, 255, 255));
        window.draw(sprite);
        window.display();
    }
    */
      std::vector<cScreen*> Screens;
      ChooseScreen cs;
      cs.Run(window);
      //GameScreen gs;
      //gs.Run(window);
    
    return 0;
}

