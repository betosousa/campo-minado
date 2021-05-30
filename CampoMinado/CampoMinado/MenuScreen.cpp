#include "MenuScreen.h"

MenuScreen::MenuScreen(sf::Font& font, unsigned int screenWidth, unsigned int screenHeight) : 
    _configColumns(font, "columns", screenWidth, screenHeight / 8, 60 + (screenHeight / 5), 5, 15, 10),
    _configRows(font, "rows", screenWidth, screenHeight / 8, 70 + (screenHeight / 5) + (screenHeight / 8), 5, 15, 10),
    _configBombs(font, "bombs", screenWidth, screenHeight / 8, 80 + (screenHeight / 5) + (2 * screenHeight / 8), 1, 20, 10) {

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
    _configColumns.update(event, window);
    _configRows.update(event, window);
    _configBombs.update(event, window);
}

void MenuScreen::draw(sf::RenderWindow& window) {
    if (!_isActive) return;

    window.draw(_text);
    _startButton.draw(window);
    _configColumns.draw(window);
    _configRows.draw(window);
    _configBombs.draw(window);
}

void MenuScreen::setStartButton(sf::Font& font, std::function<void(void)> onClick) {
    int btnH = _screenHeight / 5;
    _startButton = Button(onClick);
    _startButton.setEnabled(true);
    _startButton.setPosition( _screenWidth / 4, _screenHeight - (btnH + 15), _screenWidth / 2, btnH);
    _startButton.setText(font, "Start", btnH - 5);
}

unsigned int MenuScreen::getColumns() const {
    return _configColumns.getValue();
}

unsigned int MenuScreen::getRows() const {
    return _configRows.getValue();
}

unsigned int MenuScreen::getBombs() const {
    return _configBombs.getValue();
}