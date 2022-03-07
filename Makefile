CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra

SRC = $(wildcard ./src/*.c ./utiles/*.c) 

NAME = philo

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

%.o : %.c
	$(CC) -c $(CFLAGS) $(SRC) $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

lauch: re
	@./philo

.PHONY: all clean fclean re