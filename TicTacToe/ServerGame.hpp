

#ifndef ServerGame_hpp
#define ServerGame_hpp

#include <iostream>
#include <SFML/Network.hpp>
#include "char2D.h"

class ServerGame
{
public:
    ServerGame();
    void sendData(char data[3][3]);
    char2D receiveData();
    void connect();
    sf::TcpSocket client;
};
#endif /* ServerGame_hpp */
