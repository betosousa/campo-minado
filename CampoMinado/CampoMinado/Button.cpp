#include "Button.h"

Button::Button(std::function<void(void)> onClick) {
    _state = ButtonState::Normal;
    action = onClick;
    _isEnabled = false;
}

Button::Button() {
    
}

Button::~Button() {

}

bool Button::isOverButton(sf::Vector2i screenPos) {
    return screenPos.x > _posX && screenPos.x < _posX + _width 
        && screenPos.y > _posY && screenPos.y < _posY + _height;
}

void Button::update(sf::Event& event, sf::RenderWindow& window) {
    if (!_isEnabled) return;
    _state = ButtonState::Normal;
    if (isOverButton(sf::Mouse::getPosition(window))) {
        _state = ButtonState::Hover;
        if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
            _state = ButtonState::Pressed;
            action();
        }
    }    
}

void Button::draw(sf::RenderWindow& window) {
    if (!_isEnabled) return;

    switch (_state)
    {
    case ButtonState::Normal:
        _rect.setFillColor(NORMAL_COLOR);
        break;
    case ButtonState::Hover:
        _rect.setFillColor(HOVER_COLOR);
        break;
    case ButtonState::Pressed:
        _rect.setFillColor(PRESSED_COLOR);
        break;
    default:
        break;
    }

    window.draw(_rect);
    window.draw(_text);
}

void Button::setEnabled(bool value) {
	_isEnabled = true;
}

void Button::setPosition(unsigned int x, unsigned int y, unsigned int w, unsigned int h) {
    _posX = x; _posY = y;
    _width = w; _height = h;
    _text.setPosition(_posX, _posY);
    _rect.setPosition(_posX, _posY);
    _rect.setSize(sf::Vector2f(_width, _height));
}

void Button::setText(sf::Font& font, std::string text, unsigned int size) {
    _text.setFont(font);
    _text.setCharacterSize(size);
    _text.setFillColor(sf::Color::Black);
    _text.setString(text);
}