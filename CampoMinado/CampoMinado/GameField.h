#pragma once

#include <SFML/Graphics.hpp>
#include <utility>
#include <set>

#define BOMB -1

/// <summary>
/// Classe que representa um campo de jogo
/// </summary>
class GameField
{
private:
	int _totalBombs;
	int _columns, _rows;

	bool* tiles;
	int* board;

	/// <summary>
	/// Retorna o indice no array de tiles relativo ao (x, y) do bloco
	/// </summary>
	/// <returns></returns>
	int tilesIndex(int x, int y) const;
	/// <summary>
	/// Verifica se a posição pertence ao vetor de bombas
	/// </summary>
	bool isBomb(int x, int y) const;
public:
	GameField(int columns, int rows, int bombs);
	~GameField();
	int getRows() const; 
	int getColumns() const;
	int getBombs() const;
	/// <summary>
	/// Retorna a cor do bloco de acordo com o estado atual
	/// </summary>
	sf::Color getColor(int x, int y) const;
	/// <summary>
	/// Abre um tile no campo
	/// </summary>
	void open(int x, int y);
	/// <summary>
	/// Retorna texto com total de bombas adjacentes
	/// </summary>
	std::string getBoard(int x, int y);
};

