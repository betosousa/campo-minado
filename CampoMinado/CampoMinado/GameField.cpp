#include "GameField.h"

GameField::GameField(int columns, int rows, int bombs) {
	_columns = columns;
	_rows = rows;
	_totalBombs = bombs;
	
	_bombs = std::vector<std::pair<int, int>>(bombs, std::pair<int, int>());
	for (int i = 0; i < _totalBombs; i++) {
		_bombs[i].first = i;
		_bombs[i].second = i;
	}

	// inicializa os tiles como blocos fechados
	tiles = new bool[columns * rows];
	for (int i = 0; i < columns * rows; i++)
		tiles[i] = false;
}

GameField::~GameField() {
	
}

int GameField::getRows() const {
	return _rows;
}

int GameField::getColumns() const {
	return _columns;
}

int GameField::getBombs() const {
	return _totalBombs;
}

int GameField::tilesIndex(int x, int y) const {
	return x * _rows + y;
}

sf::Color GameField::getColor(int x, int y) const {
	if (!tiles[tilesIndex(x, y)]) return sf::Color::Yellow;
	else  return isBomb(x, y) ? sf::Color::Red : sf::Color::Cyan;
}

void GameField::open(int x, int y) {
	tiles[tilesIndex(x, y)] = true;
}

bool GameField::isBomb(int x, int y) const {
	for (int i = 0; i < _totalBombs; i++) {
		if (_bombs[i].first == x && _bombs[i].second == y) {
			return true;
		}
	}
	return false;
}