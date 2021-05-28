#include "GameField.h"

GameField::GameField(int columns, int rows, int bombs) {
	_columns = columns;
	_rows = rows;
	_totalBombs = bombs;
	
	// inicializa os tiles como blocos fechados
	tiles = new bool[columns * rows];
	for (int i = 0; i < columns * rows; i++)
		tiles[i] = false;
	
	// inicializa campo com total de bombas adjacentes
	board = new int[columns * rows];
	for (int i = 0; i < columns * rows; i++)
		board[i] = 0;

	std::set<std::pair<int, int>> bombsSet;
	// inicializa bombas aleatoriamente
	while (bombsSet.size() < _totalBombs)
	{
		int x = rand() % columns, y = rand() % rows;
		bombsSet.insert(std::pair<int, int>(x, y));
	}
	
	for (std::set<std::pair<int, int>>::iterator itr = bombsSet.begin(); itr != bombsSet.end(); itr++) {
		board[tilesIndex(itr->first, itr->second)] = BOMB;
		// percorre vizinhos de bombas e adiciona 1
		for (int i = itr->first - 1; i <= itr->first + 1; i++) {
			for (int j = itr->second - 1; j <= itr->second + 1; j++) {
				if (i >= 0 && i < columns && j >= 0 && j < rows && board[tilesIndex(i, j)] != BOMB) {
					board[tilesIndex(i, j)] += 1;
				}
			}
		}
	}
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
	// se ja estiver aberto, retorna
	if (tiles[tilesIndex(x, y)]) return;
	
	// abre tile atual
	tiles[tilesIndex(x, y)] = true;
	
	// se tile for vazio, percorre vizinhos
	if (board[tilesIndex(x, y)] == 0) {
		for (int i = x - 1; i <= x + 1; i++) {
			for (int j = y - 1; j <= y + 1; j++) {
				if (i >= 0 && i < _columns && j >= 0 && j < _rows) {
					open(i, j);
				}
			}
		}
	}
}

bool GameField::isBomb(int x, int y) const {
	return board[tilesIndex(x, y)] == BOMB;
}

std::string GameField::getBoard(int x, int y) {
	if (tiles[tilesIndex(x, y)]) {
		return board[tilesIndex(x, y)] > 0 ? std::to_string(board[tilesIndex(x, y)]) : "";
	}
	return "";
}