#pragma once

#include<SFML/Graphics.hpp>
#include<functional>

#define HOVER_COLOR sf::Color::Yellow
#define NORMAL_COLOR sf::Color::White
#define PRESSED_COLOR sf::Color::Blue

/// <summary>
/// Classe que representa um botao
/// </summary>
class Button
{
private:
	sf::RectangleShape _rect;
	sf::Text _text;
	bool _isEnabled;
	int _state;
	unsigned int _posX, _posY;
	unsigned int _width, _height;

	// funcao a ser chamada quando o botao for clicado
	std::function<void(void)> action;

	bool isOverButton(sf::Vector2i screenPos);
public:
	Button();
	Button(std::function<void(void)> onClick);
	~Button();

	/// <summary>
	/// Atualiza estado do botao de acordo com eventos da tela
	/// </summary>
	/// <param name="event"></param>
	/// <param name="window"></param>
	void update(sf::Event& event, sf::RenderWindow& window);
	/// <summary>
	/// Desenha botao na tela
	/// </summary>
	/// <param name="window"></param>
	void draw(sf::RenderWindow& window);
	/// <summary>
	/// Habilita/desabilita botao
	/// </summary>
	/// <param name="value"></param>
	void setEnabled(bool value);
	/// <summary>
	/// Define representacao do botao na tela
	/// </summary>
	/// <param name="x">posicao x</param>
	/// <param name="y">posicao y</param>
	/// <param name="w">largura</param>
	/// <param name="h">altura</param>
	void setPosition(unsigned int x, unsigned int y, unsigned int w, unsigned int h);
	/// <summary>
	/// Define o texto exibido pelo botao
	/// </summary>
	/// <param name="font"></param>
	/// <param name="text"></param>
	/// <param name="size"></param>
	void setText(sf::Font& font, std::string text, unsigned int size);
};

enum ButtonState {
	Normal = 0,
	Hover = 1,
	Pressed = 2
};


