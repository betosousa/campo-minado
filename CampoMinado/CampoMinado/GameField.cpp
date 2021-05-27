#include "GameField.h"

GameField::GameField(int columns, int rows, int bombs) {
	_columns = columns;
	_rows = rows;
	_bombs = bombs;
	
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
	return _bombs;
}

int GameField::tilesIndex(int x, int y) const {
	return x * _rows + y;
}

sf::Color GameField::getColor(int x, int y) const {
	return tiles[tilesIndex(x, y)] ? sf::Color::Cyan : sf::Color::Yellow;
}

void GameField::open(int x, int y) {
	tiles[tilesIndex(x, y)] = true;
}