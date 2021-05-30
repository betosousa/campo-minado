#pragma once

#include <SFML/Graphics.hpp>
#include <utility>
#include <set>

#define BOMB -1
#define EMPTY 0


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
	bool* flags;

	int _openTiles;

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
	int getTotalOpenTiles() const;
	int getTotalNonBombTiles() const;
	/// <summary>
	/// Retorna a cor do bloco de acordo com o estado atual
	/// </summary>
	sf::Color getColor(int x, int y) const;
	/// <summary>
	/// Abre um tile no campo, retornando true caso o tile seja uma bomba 
	/// </summary>
	bool open(int x, int y);
	/// <summary>
	/// Retorna texto com total de bombas adjacentes
	/// </summary>
	std::string getBoard(int x, int y);
	/// <summary>
	/// Marca ou desmarca tile com bandeira
	/// </summary>
	void changeFlag(int x, int y);
	/// <summary>
	/// Reseta o campo de jogo
	/// </summary>
	void reset();
	/// <summary>
	/// Define os parametros do campo
	/// </summary>
	void setField(int columns, int rows, int bombs);
};

