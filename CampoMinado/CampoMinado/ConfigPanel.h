#pragma once

#include "Screen.h"
#include "Button.h"

/// <summary>
/// Painel com texto e botoes para configuracao de uma variavel
/// </summary>
class ConfigPanel :
    public Screen
{
private:
    sf::Text _label, _valueText;
    Button _plusButton, _minusButton;
    unsigned int _minValue, _maxValue;
    unsigned int _panelWidth, _panelHeight;
    unsigned int _panelX, _panelY;
    unsigned int _value;
public:
    ConfigPanel(sf::Font& font, std::string label, unsigned int width, unsigned int height, unsigned int posY, unsigned int minValue, unsigned int maxValue, unsigned int value);
    ~ConfigPanel();
    void draw(sf::RenderWindow& window);
    void update(sf::Event& event, sf::RenderWindow& window);
    /// <summary>
    /// Retorna o valor escolhido para a variavel
    /// </summary>
    /// <returns></returns>
    unsigned int getValue() const;
};

