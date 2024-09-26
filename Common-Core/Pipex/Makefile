NAME := pipex

CC := gcc

CFLAGS := -Wall -Wextra -Werror

SRC = main.c \
ft_path.c \
ft_split.c \
ft_strjoin.c \
ft_free_str.c \
ft_child.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
