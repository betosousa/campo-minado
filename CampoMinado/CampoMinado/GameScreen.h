#pragma once

#include "Screen.h"
#include "GameField.h"
#include "FieldDrawer.h"
#include "Button.h"

/// <summary>
/// Tela principal do jogo
/// </summary>
class GameScreen :
    public Screen
{
private:
    FieldDrawer _field;
    bool _isGameOver;
public:
    GameScreen(sf::Font& font, unsigned int screenWidth, unsigned int screenHeight, unsigned int columns, unsigned int rows, unsigned int bombs);
    ~GameScreen();
    void update(sf::Event& event, sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    bool isGameOver() const;
    void reinitGame();
};

