#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameField.h"
#include "FieldDrawer.h"

int main()
{    
    FieldDrawer field(GameField(10, 10, 5));
    sf::RenderWindow window(sf::VideoMode(field.getScreenWidth(), field.getScreenHeight()), "Campo minado");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        field.drawField(window);        
        window.display();
    }
 
    return 0;
}