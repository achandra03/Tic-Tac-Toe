#include <SFML/Graphics.hpp>
#include "Game.hpp"
int main()
{
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
    
      Game g;
      g.start();
    
    return 0;
}

