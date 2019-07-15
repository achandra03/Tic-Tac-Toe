

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include "Board.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include "ServerGame.hpp"
#include "ClientGame.hpp"
#include "char2D.h"
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
    void render(sf::RenderWindow &window);
    //void start(sf::RenderWindow &window);
    void serverStart(sf::RenderWindow &window);
    void clientStart(sf::RenderWindow &window);
    void setBoard(char2D board);
    int handleX(int x);
    int handleY(int y);
    Game();
    char2D b;
};
#endif /* Game_hpp */
