#pragma once

/// <summary>
/// Classe que representa um campo de jogo
/// </summary>
class GameField
{
private:
	int _bombs;
	int _columns, _rows;

public:
	GameField(int columns, int rows, int bombs);
	~GameField();
	int getRows() const; 
	int getColumns() const;
	int getBombs() const;
};

