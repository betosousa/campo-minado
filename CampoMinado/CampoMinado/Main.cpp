#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameField.h"
#include "FieldDrawer.h"

#define GAME_OVER_STRING "GAME OVER"

int main()
{    
    FieldDrawer field(GameField(10, 10, 10));
    sf::RenderWindow window(sf::VideoMode(field.getScreenWidth(), field.getScreenHeight()), "Campo minado");

    bool isGameOver = false;
    sf::Font font;
    font.loadFromFile("arial.ttf");
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(field.getScreenHeight() / std::strlen(GAME_OVER_STRING));
    text.setFillColor(sf::Color::Magenta);
    text.setString(GAME_OVER_STRING);
    text.setPosition(field.getScreenWidth() / 4, field.getScreenHeight() / 2);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonReleased && !isGameOver) 
                isGameOver = field.open(sf::Mouse::getPosition(window));
        }

        window.clear();
        field.drawField(window);

        if (isGameOver) 
            window.draw(text);
        
        window.display();
    }
 
    return 0;
}