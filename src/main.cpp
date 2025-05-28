#include <span>
#include <iostream>

#include <SFML/Graphics.hpp>

int main()
{

    while (window.isOpen())
    {
        sf::RenderWindow window(sf::VideoMode({ 200, 200 }), "SFML works!");
            while (const std::optional event = window.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                {
                    window.close();
                }
            }


        



        window.clear();
        window.display();
    }
}
