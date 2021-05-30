#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameField.h"
#include "FieldDrawer.h"
#include "Button.h"
#include "GameScreen.h"
#include "GameOverScreen.h"
#include "MenuScreen.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main()
{    
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Falha ao carregar fonte" << std::endl;
    }
    
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), GAME_TITLE_STRING);
    
    GameScreen gameScreen(font, SCREEN_WIDTH, SCREEN_HEIGHT);
          
    GameOverScreen gameOverScreen(font, SCREEN_WIDTH, SCREEN_HEIGHT);
    gameOverScreen.setRestartButton(font, 
        [&gameScreen]() -> void {
            std::cout << "Reiniciando" << std::endl;
            gameScreen.reinitGame();
        });
    
    MenuScreen menuScreen(font, SCREEN_WIDTH, SCREEN_HEIGHT);
    menuScreen.setStartButton(font, 
        [&gameScreen, &gameOverScreen, &menuScreen]() -> void {
            std::cout << "Iniciando jogo" << std::endl;
            gameScreen.setActive(true);
            gameOverScreen.setActive(false);
            menuScreen.setActive(false);

            gameScreen.initGame(menuScreen.getColumns(), menuScreen.getRows(), menuScreen.getBombs(), menuScreen.getLifes());
        });

    menuScreen.setActive(true);
    gameScreen.setActive(false);
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
            menuScreen.update(event, window);
        }

        window.clear();

        menuScreen.draw(window);
        gameScreen.draw(window);
        gameOverScreen.setActive(gameScreen.isGameOver());
        gameOverScreen.draw(window);
                
        window.display();
    }
 
    return 0;
}