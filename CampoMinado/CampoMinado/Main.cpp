#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameField.h"
#include "FieldDrawer.h"
#include "Button.h"
#include "GameScreen.h"
#include "GameOverScreen.h"

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
    
    Button restartButton(
        [&gameScreen]() -> void {
            std::cout << "Reiniciando" << std::endl;
            gameScreen.reinitGame();
        });  

    GameOverScreen gameOverScreen(font, SCREEN_WIDTH, SCREEN_HEIGHT, restartButton);

    gameScreen.setActive(true);
    gameOverScreen.setActive(false);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            gameScreen.update(event, window);
            gameOverScreen.update(event, window);
        }

        window.clear();

        gameScreen.draw(window);
        gameOverScreen.setActive(gameScreen.isGameOver());
        gameOverScreen.draw(window);
                
        window.display();
    }
 
    return 0;
}