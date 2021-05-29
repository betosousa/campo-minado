#include "Button.h"

Button::Button(sf::Font& font, std::string text, unsigned int x, unsigned int y, unsigned int w, unsigned int h, std::function<void(void)> onClick) {
    _text.setFont(font);
    _text.setCharacterSize(h / 2);
    _text.setFillColor(sf::Color::Black);
    _text.setString(text);
    _state = ButtonState::Normal;
    setPosition(x, y, w, h);
    action = onClick;
    _isEnabled = false;
}

Button::Button(sf::Font& font, std::function<void(void)> onClick) : Button(font, "button", 0, 0, 100, 50, onClick) {

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