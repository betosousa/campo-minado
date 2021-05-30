#include "MenuScreen.h"

#define CONFIG_SIZE (screenHeight / 10)
#define TITLE_SIZE (screenHeight / 5)
#define BASE 40
#define PADDING 10

MenuScreen::MenuScreen(sf::Font& font, unsigned int screenWidth, unsigned int screenHeight) : 
    _configColumns(font, "columns", screenWidth, CONFIG_SIZE, BASE + TITLE_SIZE, 5, 15, 10),
    _configRows(font, "rows", screenWidth, CONFIG_SIZE, BASE + PADDING + TITLE_SIZE + CONFIG_SIZE, 5, 15, 10),
    _configBombs(font, "bombs", screenWidth, CONFIG_SIZE, BASE + (2 * PADDING) + TITLE_SIZE + (2 * CONFIG_SIZE), 4, 20, 10),
    _configLifes(font, "lifes", screenWidth, CONFIG_SIZE, BASE + (3 * PADDING) + TITLE_SIZE + (3 * CONFIG_SIZE), 1, 3, 1) {

    _screenWidth = screenWidth;
    _screenHeight = screenHeight;

    _text.setFont(font);
    _text.setCharacterSize(TITLE_SIZE);
    _text.setFillColor(sf::Color::White);
    _text.setString(GAME_TITLE_STRING);
    _text.setPosition(50, 0);
}

MenuScreen::~MenuScreen() {

}

void MenuScreen::update(sf::Event& event, sf::RenderWindow& window) {
    if (!_isActive) return;

    _startButton.update(event, window);
    _configColumns.update(event, window);
    _configRows.update(event, window);
    _configBombs.update(event, window);
    _configLifes.update(event, window);
}

void MenuScreen::draw(sf::RenderWindow& window) {
    if (!_isActive) return;

    window.draw(_text);
    _startButton.draw(window);
    _configColumns.draw(window);
    _configRows.draw(window);
    _configBombs.draw(window);
    _configLifes.draw(window);
}

void MenuScreen::setStartButton(sf::Font& font, std::function<void(void)> onClick) {
    int btnH = _screenHeight / 6;
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

unsigned short MenuScreen::getLifes() const {
    return _configLifes.getValue();
}