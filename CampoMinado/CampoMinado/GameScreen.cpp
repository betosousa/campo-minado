#include "GameScreen.h"

GameScreen::GameScreen(sf::Font& font, unsigned int screenWidth, unsigned int screenHeight, unsigned int columns, unsigned int rows, unsigned int bombs) :
    _field(font, columns, rows, bombs, screenWidth, screenHeight) {
    _isGameOver = false;
}

GameScreen::~GameScreen() {

}

void GameScreen::update(sf::Event& event, sf::RenderWindow& window) {
	if (!_isActive) return;
    
    if (event.type == sf::Event::MouseButtonReleased && !_isGameOver) {
        if (event.mouseButton.button == sf::Mouse::Left)
            _isGameOver = _field.open(sf::Mouse::getPosition(window));
        else if (event.mouseButton.button == sf::Mouse::Right)
            _field.changeFlag(sf::Mouse::getPosition(window));
    }
}

void GameScreen::draw(sf::RenderWindow& window) {
    if (!_isActive) return;

    _field.drawField(window);
}

bool GameScreen::isGameOver() const {
	return _isGameOver;
}

void GameScreen::reinitGame() {
    _isGameOver = false;
    _field.restart();
}