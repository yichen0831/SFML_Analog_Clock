#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <SFML/Graphics.hpp>

class Clock
{
public:
    Clock();
    ~Clock();
    
    void start();
    
private:
    sf::RenderWindow m_window;
    sf::Texture m_textureSFML;
    
    void drawClockFrame();
    void drawTimeIndicator();

};

#endif // CLOCK_HPP
