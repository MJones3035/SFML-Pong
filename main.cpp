#include <stdio.h>
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

#include "pong.h"
#include "settings.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(Settings::WINDOW_WIDTH, Settings::WINDOW_HEIGHT), "Pong");
    sf::ContextSettings settings;
    settings.antialiasingLevel = 4;

    std::unique_ptr<Pong> game(std::make_unique<Pong>());

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        game->draw(window);
        window.display();
    }

    return 0;


#ifdef _DEBUG
    _onexit(_CrtDumpMemoryLeaks);
#endif
}

