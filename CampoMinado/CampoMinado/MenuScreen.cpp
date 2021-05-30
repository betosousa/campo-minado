#include "MenuScreen.h"

MenuScreen::MenuScreen(sf::Font& font, unsigned int screenWidth, unsigned int screenHeight) {
    _screenWidth = screenWidth;
    _screenHeight = screenHeight;

    _text.setFont(font);
    _text.setCharacterSize(_screenHeight / 5);
    _text.setFillColor(sf::Color::White);
    _text.setString(GAME_TITLE_STRING);
    _text.setPosition(50, 30);
}

MenuScreen::~MenuScreen() {

}

void MenuScreen::update(sf::Event& event, sf::RenderWindow& window) {
    if (!_isActive) return;
    _startButton.update(event, window);
}

void MenuScreen::draw(sf::RenderWindow& window) {
    if (!_isActive) return;
    window.draw(_text);
    _startButton.draw(window);
}

void MenuScreen::setStartButton(sf::Font& font, std::function<void(void)> onClick) {
    int btnH = _screenHeight / 5;
    _startButton = Button(onClick);
    _startButton.setEnabled(true);
    _startButton.setPosition( _screenWidth / 4, _screenHeight - (btnH + 15), _screenWidth / 2, btnH);
    _startButton.setText(font, "Start", btnH - 5);
}