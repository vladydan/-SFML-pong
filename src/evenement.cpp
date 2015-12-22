#include <SFML/Graphics.hpp>
#include "prototypes.hpp"
#include <stdio.h>

void evenementListener(sf::Event event, sf::RenderWindow *window, t_game_elements elements)
{
	float deltaTime = elements.clock.restart().asSeconds();

  	if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Escape)
        {
            window->close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        {
        	if (elements.playerOne->getPosition().y > 0)
        	{
            	elements.playerOne->move(0, -10);
        	}
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
        	if (elements.playerOne->getPosition().y < WINDOW_HEIGHT - BAT_HEIGHT)
        	{
            	elements.playerOne->move(0, 10);
        	}
        }
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))        {
        	if (elements.playerTwo->getPosition().y > 0)
            	elements.playerTwo->move(0, -10);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
        	if (elements.playerTwo->getPosition().y < WINDOW_HEIGHT - BAT_HEIGHT)
            	elements.playerTwo->move(0, 10);
        }
    }
    if (event.type == sf::Event::Closed)
        window->close();
}