#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameField.h"
#include "FieldDrawer.h"
#include "Button.h"
#include "GameScreen.h"

#include <iostream>

#define GAME_OVER_STRING "GAME OVER"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main()
{    
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Falha ao carregar fonte" << std::endl;
    }
    
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Campo minado");
    GameScreen gameScreen(font, SCREEN_WIDTH, SCREEN_HEIGHT, 10, 10, 10);

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(SCREEN_HEIGHT / std::strlen(GAME_OVER_STRING));
    text.setFillColor(sf::Color::Magenta);
    text.setString(GAME_OVER_STRING);
    text.setPosition(SCREEN_WIDTH / 4, SCREEN_HEIGHT / 2);

    Button restartButton(font, "Restart", SCREEN_WIDTH / 2, 100 + SCREEN_HEIGHT / 2, 100, 50,
        [&gameScreen]() -> void {
            std::cout << "Reiniciando" << std::endl;
            gameScreen.reinitGame();
        });  

    gameScreen.setActive(true);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            gameScreen.update(event, window);
            restartButton.update(event, window);
        }

        window.clear();
        gameScreen.draw(window);

        if (gameScreen.isGameOver()) {
            window.draw(text);
            restartButton.setEnabled(true);
            restartButton.draw(window);
        }
        
        window.display();
    }
 
    return 0;
}