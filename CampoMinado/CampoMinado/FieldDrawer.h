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
};

