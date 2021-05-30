#pragma once

#include "GameField.h"
#include <SFML/Graphics.hpp>

/// <summary>
/// Classe para desenhar o campo de jogo na tela
/// </summary>
class FieldDrawer
{
private:
	const int padding = 2;

	GameField _gameField;
	sf::RectangleShape _block;
	sf::Text _text;
	float _blockWidth, _blockHeight;
	unsigned int _screenWidth, _screenHeight;

public:
	FieldDrawer(sf::Font& font, unsigned int columns, unsigned int rows, unsigned int bombs, unsigned int screenWidth, unsigned int screenHeight);
	~FieldDrawer();
	GameField getGameField() const;

	/// <summary>
	/// Desenha cada bloco do mapa na tela
	/// </summary>
	/// <param name="window">tela de jogo</param>
	void drawField(sf::RenderWindow &window);

	/// <summary>
	/// Abre um bloco de acordo com a posição na tela, retornando se o jogo acabou 
	/// </summary>
	/// <param name="screenPos"></param>
	bool open(sf::Vector2i screenPos);

	/// <summary>
	/// Marca/desmarca bloco como possivel bomba
	/// </summary>
	/// <param name="screenPos"></param>
	void changeFlag(sf::Vector2i screenPos);

	/// <summary>
	/// Reinicia a partida
	/// </summary>
	void restart();

	/// <summary>
	/// Inicializa o campo de jogo
	/// </summary>
	/// <param name="columns"></param>
	/// <param name="rows"></param>
	/// <param name="bombs"></param>
	void initField(unsigned int columns, unsigned int rows, unsigned int bombs);
};

