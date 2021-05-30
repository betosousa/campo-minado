#pragma once

#include "Screen.h"
#include "Button.h"

#define GAME_OVER_STRING "GAME OVER"
#define SEMI_TRANSPARENT sf::Color(0,0,0,120)

/// <summary>
/// Tela de fim de jogo
/// </summary>
class GameOverScreen :
    public Screen
{
private:
    sf::Text _text;
    sf::RectangleShape _panel;
    Button _restartButton;
    unsigned int _panelX, _panelY, _panelW, _panelH;

public:
    GameOverScreen(sf::Font& font, unsigned int screenWidth, unsigned int screenHeight);
    ~GameOverScreen();
    void update(sf::Event& event, sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    void setRestartButton(sf::Font& font, std::function<void(void)> onClick);
};

