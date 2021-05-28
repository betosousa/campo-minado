#include "FieldDrawer.h"

FieldDrawer::FieldDrawer(GameField gf) : _gameField(gf.getColumns(), gf.getRows(), gf.getBombs()) {
    // calcula tamanho do bloco com base no tamanho da tela
    _blockWidth = (screenWidth - (gf.getColumns() - 1) * padding) / gf.getColumns();
    _blockHeight = (screenHeight - (gf.getRows() - 1) * padding) / gf.getRows();
    
    _block = sf::RectangleShape(sf::Vector2f(_blockWidth, _blockHeight));
    _block.setFillColor(sf::Color::White);

    _font.loadFromFile("arial.ttf");
    _text.setFont(_font);
    _text.setCharacterSize(_blockHeight);
    _text.setFillColor(sf::Color::Black);
}

FieldDrawer::~FieldDrawer() {

}

GameField FieldDrawer::getGameField() const {
    return _gameField;
}

int FieldDrawer::getScreenWidth() const {
    return screenWidth;
}

int FieldDrawer::getScreenHeight() const {
    return screenHeight;
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
    return _gameField.open(screenPos.x / _blockWidth, screenPos.y / _blockHeight);
}
