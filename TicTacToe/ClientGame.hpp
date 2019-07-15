

#ifndef ClientGame_hpp
#define ClientGame_hpp

#include <SFML/Network.hpp>
#include "char2D.h"

class ClientGame
{

    public:
        ClientGame();
        void sendData(char data[3][3]);
        void connect();
        char2D receiveData();
        sf::TcpSocket socket;
};

#endif /* ClientGame_hpp */
