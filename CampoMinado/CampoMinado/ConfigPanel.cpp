#include "ConfigPanel.h"

ConfigPanel::ConfigPanel(sf::Font& font, std::string label, unsigned int width, unsigned int height, unsigned int posY, unsigned int minValue, unsigned int maxValue, unsigned int value) :
	_plusButton([&]()->void {_value = std::min(_value + 1, _maxValue); }),
	_minusButton([&]()->void {_value = std::max(_value - 1, _minValue); }) {
	
	_panelX = 10; _panelY = posY;
	_panelWidth = width; _panelHeight = height;

	_minValue = minValue; _maxValue = maxValue;
	_value = value;

	unsigned int fontSize = _panelHeight - 5;
	_label.setFont(font);
	_label.setCharacterSize(fontSize);
	_label.setFillColor(sf::Color::White);
	_label.setString(label);
	_label.setPosition(_panelX, _panelY);

	_minusButton.setEnabled(true);
	_minusButton.setPosition(_panelWidth - (3 * fontSize + 30), _panelY + 5, fontSize, fontSize);
	_minusButton.setText(font, "-", fontSize);

	_valueText.setFont(font);
	_valueText.setCharacterSize(fontSize);
	_valueText.setFillColor(sf::Color::White);
	_valueText.setPosition(_panelWidth - (2 * fontSize + 20), _panelY + 5);

	_plusButton.setEnabled(true);
	_plusButton.setPosition(_panelWidth - (fontSize + 10), _panelY + 5, fontSize, fontSize);
	_plusButton.setText(font, "+", fontSize);

	setActive(true);
}

ConfigPanel::~ConfigPanel() {

}

void ConfigPanel::draw(sf::RenderWindow& window) {
	if (!_isActive) return;

	window.draw(_label);
	_plusButton.draw(window);
	_valueText.setString(std::to_string(_value));
	window.draw(_valueText);
	_minusButton.draw(window);
}

void ConfigPanel::update(sf::Event& event, sf::RenderWindow& window) {
	if (!_isActive) return;

	_minusButton.update(event, window);
	_plusButton.update(event, window);
}

unsigned int ConfigPanel::getValue() const {
	return _value;
}