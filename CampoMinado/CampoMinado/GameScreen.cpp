#include "GameScreen.h"

#define LIFE_TEXT_SIZE 50

GameScreen::GameScreen(sf::Font& font, unsigned int screenWidth, unsigned int screenHeight) :
    _field(font, 10, 10, 10, screenWidth, screenHeight - LIFE_TEXT_SIZE) {
    _isGameOver = false;
    
    _lifesLabel.setFont(font);
    _lifesLabel.setPosition(0, screenHeight - LIFE_TEXT_SIZE);
    _lifesLabel.setCharacterSize(LIFE_TEXT_SIZE);
    _lifesLabel.setString("Lifes: ");

    _lifesText.setFont(font);
    _lifesText.setPosition(screenWidth - LIFE_TEXT_SIZE, screenHeight - LIFE_TEXT_SIZE);
    _lifesText.setCharacterSize(LIFE_TEXT_SIZE);

    initLifes(0);
}

GameScreen::~GameScreen() {

}

void GameScreen::update(sf::Event& event, sf::RenderWindow& window) {
	if (!_isActive) return;
    
    if (event.type == sf::Event::MouseButtonReleased && !_isGameOver) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            bool isBomb = _field.open(sf::Mouse::getPosition(window));
            _isGameOver = _field.isAllOpen() || (isBomb && _lifes-- <= 1);
            _lifesText.setString(std::to_string(_lifes));
        } else if (event.mouseButton.button == sf::Mouse::Right)
            _field.changeFlag(sf::Mouse::getPosition(window));
    }
}

void GameScreen::draw(sf::RenderWindow& window) {
    if (!_isActive) return;

    _field.drawField(window);
    window.draw(_lifesLabel);
    window.draw(_lifesText);
}

bool GameScreen::isGameOver() const {
	return _isGameOver;
}

void GameScreen::reinitGame() {
    _isGameOver = false;
    _field.restart();
    initLifes(_maxLifes);
}

void GameScreen::initGame(unsigned int columns, unsigned int rows, unsigned int bombs, short lifes) {
    _field.initField(columns, rows, bombs);
    initLifes(lifes);    
}

void GameScreen::initLifes(short value) {
    _lifes = _maxLifes = value;
    _lifesText.setString(std::to_string(_lifes));
}