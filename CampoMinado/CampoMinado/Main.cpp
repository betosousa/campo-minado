#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameField.h"
#include "FieldDrawer.h"
#include "Button.h"

#include <iostream>

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

    Button restartButton(font, "Restart", field.getScreenWidth() / 2, 100 + field.getScreenHeight() / 2, 100, 50, 
        [&isGameOver, &field]() -> void {
            std::cout << "Reiniciando" << std::endl;
            isGameOver = false;
            field.restart();
        });

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonReleased && !isGameOver) {
                if (event.mouseButton.button == sf::Mouse::Left)
                    isGameOver = field.open(sf::Mouse::getPosition(window));
                else if (event.mouseButton.button == sf::Mouse::Right)
                    field.changeFlag(sf::Mouse::getPosition(window));
            }

            restartButton.update(event, window);
        }

        window.clear();
        field.drawField(window);

        if (isGameOver) {
            window.draw(text);
            restartButton.setEnabled(true);
            restartButton.draw(window);
        }
        
        window.display();
    }
 
    return 0;
}