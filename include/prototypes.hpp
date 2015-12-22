#ifndef PROTOTYPES_H_
# define PROTOTYPES_H_

#define WINDOW_HEIGHT  600
#define WINDOW_WIDTH   1000
#define BAT_HEIGHT	   80
#define BAT_WIDTH	   10
#define BALL_RADIUS	   30

class 			playerBat
{
	public:
		playerBat(int x, int y);
		sf::RectangleShape getShape();
		void setShape(sf::RectangleShape Shape);
		void move(int x, int y);
		sf::Vector2f getPosition();
	private:
		sf::RectangleShape shapeBat;
};

typedef struct 		s_game_elements
{
	playerBat 		*playerOne;
	playerBat 		*playerTwo;
	sf::CircleShape	*ball;
	sf::Clock 		clock;
	float			ballAngle;
	sf::Sprite 		background;
}					t_game_elements;


void evenementListener(sf::Event event, sf::RenderWindow *window, t_game_elements elements);
void ballMovement(t_game_elements *elements, sf::RenderWindow *window);


#endif /* !PROTOTYPES_H_ */
