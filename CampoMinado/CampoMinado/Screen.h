#pragma once

#include <SFML/Graphics.hpp>

/// <summary>
/// Classe base que represnta uma tela do jogo
/// </summary>
class Screen
{
protected:
	bool _isActive;
public:
	/// <summary>
	/// Atualiza estado dos elementos da tela de acordo com o evento passado
	/// </summary>
	/// <param name="event"></param>
	/// <param name="window"></param>
	virtual void update(sf::Event& event, sf::RenderWindow& window) {}
	/// <summary>
	/// Desenha os elementos da tela
	/// </summary>
	/// <param name="window"></param>
	virtual void draw(sf::RenderWindow& window) {}
	/// <summary>
	/// Habilita/desabilita a tela
	/// </summary>
	/// <param name="value"></param>
	void setActive(bool value);
};

