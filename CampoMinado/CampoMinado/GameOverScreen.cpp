#include "GameOverScreen.h"

GameOverScreen::GameOverScreen(sf::Font& font, unsigned int screenWidth, unsigned int screenHeight) {
    
    _panelX = screenWidth / 5; _panelY = screenHeight / 4;
    _panelW = 3 * screenWidth / 5; _panelH = screenHeight / 2;

    _panel.setSize(sf::Vector2f(_panelW, _panelH));
    _panel.setFillColor(SEMI_TRANSPARENT);
    _panel.setPosition(_panelX, _panelY);
    
    _text.setFont(font);
    _text.setCharacterSize(screenHeight / std::strlen(GAME_OVER_STRING));
    _text.setFillColor(sf::Color::White);
    _text.setString(GAME_OVER_STRING);
    _text.setPosition(_panelX + 30, _panelY + 30);
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

void GameOverScreen::setRestartButton(sf::Font& font, std::function<void(void)> onClick) {
    unsigned int btnH = _panelH / 4;
    _restartButton = Button(onClick);
    _restartButton.setEnabled(true);
    _restartButton.setPosition(_panelX + _panelW / 4, _panelY + _panelH - (btnH + 5), _panelW / 2, btnH);
    _restartButton.setText(font, "Restart", btnH - 5);
}