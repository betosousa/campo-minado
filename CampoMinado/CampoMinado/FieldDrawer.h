#pragma once

#include "GameField.h"
#include <SFML/Graphics.hpp>

/// <summary>
/// Classe para desenhar o campo de jogo na tela
/// </summary>
class FieldDrawer
{
private:
	/// constantes
	const int screenWidth = 800, screenHeight = 600;
	const int padding = 2;

	/// propriedades
	GameField _gameField;
	sf::RectangleShape _block;
	sf::Text _text;
	sf::Font _font;

	float _blockWidth, _blockHeight;

public:
	FieldDrawer(GameField gf);
	~FieldDrawer();
	GameField getGameField() const;
	int getScreenWidth() const;
	int getScreenHeight() const;

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
};

