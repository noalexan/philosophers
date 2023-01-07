CC = gcc
CFLAGS = -Werror -Wextra -Wall

SRC =	main.c args.c protected.c routine.c thread.c time.c

OBJ = $(SRC:.c=.o)

NAME = philo

.c.o:
	$(CC) $(CFLAGS) -c $(<) -o $(<:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
