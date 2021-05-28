#include "GameField.h"


GameField::GameField(int columns, int rows, int bombs) {
	_columns = columns;
	_rows = rows;
	_totalBombs = bombs;
	
	// inicializa bombas aleatoriamente
	while (_bombs.size() < _totalBombs)
	{
		int x = rand() % columns, y = rand() % rows;
		_bombs.insert(std::pair<int, int>(x, y));
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
	for (std::set<std::pair<int, int>>::iterator itr = _bombs.begin(); itr != _bombs.end(); itr++) {
		if (itr->first == x && itr->second == y) {
			return true;
		}
	}
	return false;
}