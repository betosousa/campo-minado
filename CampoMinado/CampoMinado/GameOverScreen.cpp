#include "GameOverScreen.h"

GameOverScreen::GameOverScreen(sf::Font& font, unsigned int screenWidth, unsigned int screenHeight, Button& btn) {
    
    unsigned int panelX = screenWidth / 5, panelY = screenHeight / 4;
    unsigned int panelW = 3 * screenWidth / 5, panelH = screenHeight / 2;

    _panel.setSize(sf::Vector2f(panelW, panelH));
    _panel.setFillColor(SEMI_TRANSPARENT);
    _panel.setPosition(panelX, panelY);
    
    _text.setFont(font);
    _text.setCharacterSize(screenHeight / std::strlen(GAME_OVER_STRING));
    _text.setFillColor(sf::Color::White);
    _text.setString(GAME_OVER_STRING);
    _text.setPosition(panelX + 30, panelY + 30);

    unsigned int btnH = panelH / 4;
    _restartButton = btn;
    _restartButton.setEnabled(true);
    _restartButton.setPosition(panelX + panelW / 4, panelY + panelH - (btnH + 5), panelW / 2, btnH);
    _restartButton.setText(font, "Restart", btnH - 5);
}

GameOverScreen::~GameOverScreen() {

}

void GameOverScreen::update(sf::Event& event, sf::RenderWindow& window) {
    if (!_isActive) return;
    _restartButton.update(event, window);
}

void GameOverScreen::draw(sf::RenderWindow& window) {
    if (!_isActive) return;
    window.draw(_panel);
    window.draw(_text);
    _restartButton.draw(window);
}