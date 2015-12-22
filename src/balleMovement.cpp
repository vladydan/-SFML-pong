#include <SFML/Graphics.hpp>
#include "prototypes.hpp"
#include <stdio.h>
#include <cmath>
#include <iostream>

float acceleration;

void ballMovement(t_game_elements *elements, sf::RenderWindow *window)
{
	float deltaTime = 3 + acceleration;
	// printf("%f\n", elements.ball->getPosition().y);
	// printf("%f\n", elements.ballAngle);
	elements->ball->move(std::cos(elements->ballAngle) * deltaTime, std::sin(elements->ballAngle) * deltaTime);

    if (elements->ball->getPosition().x - BALL_RADIUS < elements->playerOne->getPosition().x + BAT_WIDTH / 2 &&
        elements->ball->getPosition().x - BALL_RADIUS > elements->playerOne->getPosition().x &&
        elements->ball->getPosition().y + BALL_RADIUS >= elements->playerOne->getPosition().y - BAT_HEIGHT / 2 &&
        elements->ball->getPosition().y - BALL_RADIUS <= elements->playerOne->getPosition().y + BAT_HEIGHT / 2)
    {
    	if (elements->ball->getPosition().y > elements->playerOne->getPosition().y)
        	elements->ballAngle = 3.14159f - elements->ballAngle + (std::rand() % 20) * 3.14159f / 180;
    	else
    	    elements->ballAngle = 3.14159f - elements->ballAngle - (std::rand() % 20) * 3.14159f / 180;

	    elements->ball->setPosition(elements->playerOne->getPosition().x + BALL_RADIUS + BAT_WIDTH / 2 + 0.1f, elements->ball->getPosition().y);
	    acceleration += 0.3;
	}

	if (elements->ball->getPosition().x + BALL_RADIUS < elements->playerTwo->getPosition().x + BAT_WIDTH / 2 &&
        elements->ball->getPosition().x + BALL_RADIUS > elements->playerTwo->getPosition().x &&
        elements->ball->getPosition().y + BALL_RADIUS >= elements->playerTwo->getPosition().y - BAT_HEIGHT / 2 &&
        elements->ball->getPosition().y - BALL_RADIUS <= elements->playerTwo->getPosition().y + BAT_HEIGHT / 2)
    {
    	if (elements->ball->getPosition().y > elements->playerTwo->getPosition().y)
        	elements->ballAngle = 3.14159f - elements->ballAngle + (std::rand() % 20) * 3.14159f / 180;
    	else
    	    elements->ballAngle = 3.14159f - elements->ballAngle - (std::rand() % 20) * 3.14159f / 180;

	    elements->ball->setPosition(elements->playerTwo->getPosition().x - BALL_RADIUS - BAT_WIDTH / 2 - 0.1f, elements->ball->getPosition().y);
	    acceleration += 0.3;
	}

	if (elements->ball->getPosition().y > WINDOW_HEIGHT)
	{	
		elements->ballAngle = -elements->ballAngle;
		elements->ball->setPosition(elements->ball->getPosition().x, WINDOW_HEIGHT - 3);
	    acceleration += 0.3;
	}

	if (elements->ball->getPosition().y < 0)
	{
		elements->ballAngle = -elements->ballAngle;
		elements->ball->setPosition(elements->ball->getPosition().x, 3);
	    acceleration += 0.3;
	}
	if (elements->ball->getPosition().y > WINDOW_HEIGHT)
	{	
		elements->ballAngle = -elements->ballAngle;
		elements->ball->setPosition(elements->ball->getPosition().x, WINDOW_HEIGHT - 3);
	    acceleration += 0.3;
	}

}