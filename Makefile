NAME = get_next_line

SRC = \
main.c \
get_next_line.c \
get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror 

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re