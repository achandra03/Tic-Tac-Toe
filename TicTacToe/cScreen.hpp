
#ifndef cScreen_hpp
#define cScreen_hpp

#include <SFML/Graphics.hpp>
class cScreen
{
    public :
        virtual int Run (sf::RenderWindow &window) = 0;
};


#endif /* cScreen_hpp */
