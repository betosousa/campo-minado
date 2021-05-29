#include "GameField.h"

GameField::GameField(int columns, int rows, int bombs) {
	_columns = columns;
	_rows = rows;
	_totalBombs = bombs;

	tiles = new bool[columns * rows];
	board = new int[columns * rows];
	flags = new bool[columns * rows];

	reset();
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
	int index = tilesIndex(x, y);
	if (!tiles[index]) return flags[index] ? sf::Color::Green : sf::Color::Yellow;
	else return isBomb(x, y) ? sf::Color::Red : sf::Color::Cyan;
}

bool GameField::open(int x, int y) {
	int index = tilesIndex(x, y);
	// se ja estiver aberto, retorna
	if (tiles[index]) return false;
	
	// abre tile atual
	tiles[index] = true;
	if (!isBomb(x, y)) _openTiles++;

	// se tile for vazio, percorre vizinhos
	if (board[index] == EMPTY) {
		for (int i = x - 1; i <= x + 1; i++) {
			for (int j = y - 1; j <= y + 1; j++) {
				if (i >= 0 && i < _columns && j >= 0 && j < _rows) {
					open(i, j);
				}
			}
		}
		
	}
	return isBomb(x, y);
}

bool GameField::isBomb(int x, int y) const {
	return board[tilesIndex(x, y)] == BOMB;
}

std::string GameField::getBoard(int x, int y) {
	int index = tilesIndex(x, y);
	if (tiles[index]) {
		return board[index] > 0 ? std::to_string(board[index]) : "";
	}
	return "";
}

void GameField::changeFlag(int x, int y) {
	int index = tilesIndex(x, y);
	// se estiver fechado, adiciona/remove flag
	if (!tiles[index]) 
		flags[index] = !flags[index];
}

int GameField::getTotalOpenTiles() const {
	return _openTiles;
}

int GameField::getTotalNonBombTiles() const {
	return _rows * _columns - _totalBombs;
}

void GameField::reset() {
	// inicializa os tiles como blocos fechados e vazios
	for (int i = 0; i < _columns * _rows; i++) {
		tiles[i] = false;
		board[i] = EMPTY;
		flags[i] = false;
	}
	_openTiles = 0;

	// inicializa bombas aleatoriamente
	srand(time(NULL));
	std::set<std::pair<int, int>> bombsSet;
	while (bombsSet.size() < _totalBombs)
	{
		int x = rand() % _columns, y = rand() % _rows;
		bombsSet.insert(std::pair<int, int>(x, y));
	}

	for (std::set<std::pair<int, int>>::iterator itr = bombsSet.begin(); itr != bombsSet.end(); itr++) {
		board[tilesIndex(itr->first, itr->second)] = BOMB;
		// percorre vizinhos de bombas e adiciona 1
		for (int i = itr->first - 1; i <= itr->first + 1; i++) {
			for (int j = itr->second - 1; j <= itr->second + 1; j++) {
				if (i >= 0 && i < _columns && j >= 0 && j < _rows && board[tilesIndex(i, j)] != BOMB) {
					board[tilesIndex(i, j)] += 1;
				}
			}
		}
	}
}