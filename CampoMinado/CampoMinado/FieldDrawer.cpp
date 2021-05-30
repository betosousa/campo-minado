#include "FieldDrawer.h"

FieldDrawer::FieldDrawer(sf::Font& font, unsigned int columns, unsigned int rows, unsigned int bombs, unsigned int screenWidth, unsigned int screenHeight) 
    : _gameField(columns, rows, bombs) {
    _screenWidth = screenWidth; 
    _screenHeight = screenHeight;
    _text.setFont(font);
    initField(columns, rows, bombs);
}

FieldDrawer::~FieldDrawer() {

}

GameField FieldDrawer::getGameField() const {
    return _gameField;
}

void FieldDrawer::drawField(sf::RenderWindow &window) {
    for (int j = 0; j < _gameField.getRows(); j++) {
        for (int i = 0; i < _gameField.getColumns(); i++) {
            _block.setPosition(i * (_blockWidth + padding), j * (_blockHeight + padding));
            _block.setFillColor(_gameField.getColor(i, j));
            window.draw(_block);

            _text.setString(_gameField.getBoard(i, j));
            _text.setPosition(i * (_blockWidth + padding), j * (_blockHeight + padding));
            window.draw(_text);
        }
    }
}

bool FieldDrawer::open(sf::Vector2i screenPos) {
    bool isBomb = _gameField.open(screenPos.x / _blockWidth, screenPos.y / _blockHeight);
    bool isAllOpen = _gameField.getTotalOpenTiles() == _gameField.getTotalNonBombTiles();
    return isBomb || isAllOpen;
}

void FieldDrawer::changeFlag(sf::Vector2i screenPos) {
    _gameField.changeFlag(screenPos.x / _blockWidth, screenPos.y / _blockHeight);
}

void FieldDrawer::restart() {
    _gameField.reset();
}

void FieldDrawer::initField(unsigned int columns, unsigned int rows, unsigned int bombs) {
    _gameField.setField(columns, rows, bombs);
    
    // calcula tamanho do bloco com base no tamanho da tela
    _blockWidth = (_screenWidth - (columns - 1) * padding) / columns;
    _blockHeight = (_screenHeight - (rows - 1) * padding) / rows;

    _block = sf::RectangleShape(sf::Vector2f(_blockWidth, _blockHeight));
    _block.setFillColor(sf::Color::White);
        
    _text.setCharacterSize(_blockHeight);
    _text.setFillColor(sf::Color::Black);
}