#pragma once

#include "Screen.h"
#include "Button.h"

#define GAME_TITLE_STRING "Mine Sweep"

/// <summary>
/// Tela de menu inicial
/// </summary>
class MenuScreen :
    public Screen
{
private:
    unsigned int _screenWidth, _screenHeight;
    sf::Text _text;
    sf::RectangleShape _panel;
    Button _startButton;

public:
    MenuScreen(sf::Font& font, unsigned int screenWidth, unsigned int screenHeight);
    ~MenuScreen();
    void update(sf::Event& event, sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    void setStartButton(sf::Font& font, std::function<void(void)> onClick);
};

