

#include "ServerGame.hpp"

ServerGame::ServerGame()
{
    
}

void ServerGame::sendData(char data[3][3])
{
    
    if (client.send(data, 9) != sf::Socket::Done)
    {
        //std::cout << "error" << std::endl;
    }
    
}

void ServerGame::connect()
{
    sf::TcpListener listener;
    
    // bind the listener to a port
    if (listener.listen(666) != sf::Socket::Done)
    {
        std::cout << "error" << std::endl;
    }
    
    // accept a new connection
    if (listener.accept(client) != sf::Socket::Done)
    {
        std::cout << "error" << std::endl;
    }
}

char2D ServerGame::receiveData()
{
    char2D data;
    std::size_t received;
    
    // TCP socket:
    if (client.receive(&data.arr[0][0], 9, received) != sf::Socket::Done)
    {
        // error...
    }
    return data;
}
