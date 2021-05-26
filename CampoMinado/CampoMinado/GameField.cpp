#include "GameField.h"

GameField::GameField(int columns, int rows, int bombs) {
	_columns = columns;
	_rows = rows;
	_bombs = bombs;
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