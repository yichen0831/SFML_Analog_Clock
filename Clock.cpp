#include "Clock.hpp"

#include <iostream>
#include <ctime>

Clock::Clock()
{
    
}

Clock::~Clock()
{
}

void Clock::start()
{
    m_window.create(sf::VideoMode(200, 200), "SFML Analog Clock", sf::Style::Close);
    m_window.setFramerateLimit(30);
    
    if(!m_textureSFML.loadFromFile("SFML.png")) {
        std::cerr << "Cannot load SFML.png" << std::endl;
    } 
    
    sf::Event event;
    while(m_window.isOpen()) {
        while(m_window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                m_window.close();
            }
        }
        
        m_window.clear(sf::Color(0, 0, 50, 255));
        drawClockFrame();
        drawTimeIndicator();
        
        m_window.display();
    }
}

void Clock::drawClockFrame()
{
    sf::CircleShape circle(100);
    circle.setFillColor(sf::Color(200, 200, 212));
    circle.setOutlineColor(sf::Color(180, 180, 200));
    circle.setOutlineThickness(-12.0f);
    
    m_window.draw(circle);
    
    sf::RectangleShape rectangle(sf::Vector2f(4, 6));
    rectangle.setFillColor(sf::Color(128, 128, 168));
    rectangle.setOrigin(2, 0);
    
    circle.setPointCount(3);
    circle.setOutlineThickness(0);
    
    for(size_t i=0; i<12; i++) {
        if(i % 3) {
            rectangle.setPosition(100.0f + sin(i * 30.0f / 180.0f * 3.14159f) * 74.0f, 100.0f - cos(i * 30.0f / 180.0f * 3.14159f) * 74.0f);
            rectangle.setRotation(30.0f * i);
            m_window.draw(rectangle);
        }
        else {
            circle.setRadius(10.0f);
            circle.setOrigin(8.66f, 8.66f);
            circle.setFillColor(sf::Color(80, 88, 120));
            circle.setRotation(180.0f + 30.0f * i);
            circle.setPosition(100.0f + sin(i*30.0f/180.0f*3.14159f) * 74.0f, 100.0f - cos(i*30.0f/180.0f*3.14159f) * 74.0f);
            m_window.draw(circle);
        }

    }
    

    if(m_textureSFML.getSize().x != 0) {
        sf::Sprite sprite;
        sprite.setTexture(m_textureSFML);
        sprite.scale(0.3f, 0.3f);
        sf::FloatRect rect = sprite.getGlobalBounds();
        float width = rect.width;
        float height = rect.height;
        sprite.setPosition(100.0f-width/2.0f, 160.0f-height);
        
        m_window.draw(sprite);
    }


}

void Clock::drawTimeIndicator()
{
    std::time_t time_now;
    std::time(&time_now);
    std::tm* timemark = std::localtime(&time_now);
    
    int hour = timemark->tm_hour;
    if(hour >= 12) {
        hour -= 12;
    }
    
    int minute = timemark->tm_min;
    int second = timemark->tm_sec;
    
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(10, 60));
    rectangle.setFillColor(sf::Color(166, 166, 180));
    rectangle.setOrigin(5, 60);
    rectangle.setRotation(hour * 30.0f + minute * 0.5f);
    rectangle.setPosition(100, 100);
    m_window.draw(rectangle);
    
    rectangle.setSize(sf::Vector2f(6, 75));
    rectangle.setFillColor(sf::Color(120, 120, 160));
    rectangle.setOrigin(3, 75);
    rectangle.setRotation(minute * 6.0f);
    m_window.draw(rectangle);
    
    rectangle.setSize(sf::Vector2f(2, 80));
    rectangle.setFillColor(sf::Color(36, 36, 36));
    rectangle.setOrigin(1, 80);
    rectangle.setRotation(second * 6.0f);
    m_window.draw(rectangle);
    
    sf::CircleShape circle(8);
    circle.setFillColor(sf::Color(33, 33, 57));
    circle.setOrigin(4.0f, 4.0f);
    circle.setPosition(96, 96);
    m_window.draw(circle);
    
    if(m_textureSFML.getSize().x != 0) {
        sf::Sprite sprite;
        sprite.setTexture(m_textureSFML);
        sf::FloatRect localRect = sprite.getLocalBounds();
        float localWidth = localRect.width;
        float localHeight = localRect.height;
        sprite.setOrigin(localWidth/2.0f, localHeight/2.0f);
        
        sprite.scale(0.2f, 0.2f);
        
        sprite.setRotation(second * 6.0f);
        sprite.setPosition(100.0f, 100.0f);
        m_window.draw(sprite);
    }
    
}
