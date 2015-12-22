#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "prototypes.hpp"
#include <stdio.h>
#include <iostream>

t_game_elements     	initializeEnvironnement(sf::RenderWindow *window)
{
    t_game_elements gameElements;
    sf::Texture texture;

    sf::CircleShape *shape = new sf::CircleShape(BALL_RADIUS);

    // shape->setFillColor(sf::Color(100, 250, 50));
    shape->setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

	sf::Texture *textureKappa = new sf::Texture;
    if (!textureKappa->loadFromFile("ressources/kappa.png"))
    {
    	printf("Cannot load image. CHeck if ressources/background.jpg exist");
    }
    shape->setTexture(textureKappa);
    // shape->setTextureRect(sf::IntRect(0, 100, 100, 100));

    gameElements.playerOne = new playerBat(0, (WINDOW_HEIGHT / 2) - (BAT_HEIGHT / 2));
    gameElements.playerTwo = new playerBat(WINDOW_WIDTH - BAT_WIDTH, (WINDOW_HEIGHT / 2) - (BAT_HEIGHT / 2));

    gameElements.ball = shape;
    gameElements.ballAngle =  (std::rand() % 360) * 2 * 3.14159f / 360;
    sf::Clock clock;
    clock.restart();

    gameElements.clock = clock;
    return (gameElements);
}

int 					main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 100;
    sf::RenderWindow 	window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pong", sf::Style::Default, settings);
    t_game_elements		elements;

    sf::Texture texture;
    if (!texture.loadFromFile("ressources/background.jpg"))
    {
    	printf("Cannot load image. CHeck if ressources/background.jpg exist");
    }
    sf::Sprite background;
	background.setTexture(texture);
	background.setScale(0.5, 0.5);
	// background.setPosition(sf::Vector2f(0, 0));
	// background.setOrigin(sf::Vector2f(0, 0));

	elements.background = background;

    elements = initializeEnvironnement(&window);
	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("ressources/kappa.ogg"))
	{
		printf("Cannot play music. Check if kappa.ogg is present.\n");
	}
	sf::Sound music;
	music.setBuffer(buffer);
	music.play();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
        	evenementListener(event, &window, elements);
        }
        ballMovement(&elements, &window);
        window.clear();
	    window.draw(background);
       	window.draw(elements.playerOne->getShape());
	    window.draw(elements.playerTwo->getShape());
	    window.draw(*elements.ball);
        window.display();
    }
    return 0;
}