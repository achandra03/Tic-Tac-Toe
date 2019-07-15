

#include "ClientGame.hpp"
#include <iostream>

ClientGame::ClientGame()
{

}


void ClientGame::connect()
{
    sf::Socket::Status status = socket.connect("127.0.0.1", 666);
    if (status != sf::Socket::Done)
    {
        std::cout << "error connecting" << std::endl;
    }
}

void ClientGame::sendData(char data[3][3])
{
    if(socket.send(data, 9) != sf::Socket::Done)
    {
        //error...
    }
}

char2D ClientGame::receiveData()
{
    char2D data;
    std::size_t received;
    if (socket.receive(&data.arr[0][0], 9, received) != sf::Socket::Done)
    {
        
    }
    return data;
}


