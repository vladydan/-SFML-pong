NAME	= pong

SRCS	= src/main.cpp \
	  src/evenement.cpp \
	  src/balleMovement.cpp \
	src/Classes/playerBat.cpp

OBJS	= $(SRCS:.cpp=.o)

CFLAGS	+= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -I include/

all: $(NAME)

$(NAME):
	clang++ -o $(NAME) $(SRCS) $(CFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
