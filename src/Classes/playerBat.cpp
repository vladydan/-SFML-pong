#include <SFML/Graphics.hpp>
#include "prototypes.hpp"

playerBat::playerBat(int x, int y)
{
	sf::RectangleShape rectangle(sf::Vector2f(120, 50));
    rectangle.setSize(sf::Vector2f(BAT_WIDTH, BAT_HEIGHT));
    rectangle.setPosition(x, y);
    rectangle.setFillColor(sf::Color::Green);
    shapeBat = rectangle;
}

void playerBat::setShape(sf::RectangleShape Shape)
{
	shapeBat = Shape;
}

sf::RectangleShape playerBat::getShape()
{
	return shapeBat;
}

void playerBat::move(int x, int y)
{
	shapeBat.move(x, y);
}

sf::Vector2f playerBat::getPosition()
{
	sf::Vector2f position = shapeBat.getPosition();
	return position;
}
