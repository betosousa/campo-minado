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
    unsigned int _screenWidth, _screenHeight;
    short _lifes, _maxLifes;
    sf::Text _lifesLabel, _lifesText;
    void initLifes(short value);
public:
    GameScreen(sf::Font& font, unsigned int screenWidth, unsigned int screenHeight);
    ~GameScreen();
    void update(sf::Event& event, sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    bool isGameOver() const;
    /// <summary>
    /// Reinicia o jogo com os mesmos parametros da ultima partida
    /// </summary>
    void reinitGame();
    /// <summary>
    /// Inicia a tela de jogo
    /// </summary>
    void initGame(unsigned int columns, unsigned int rows, unsigned int bombs);
};

