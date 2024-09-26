NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_print_purcent.c \
ft_printf.c \
ft_put_big_x.c \
ft_put_little_x.c \
ft_put_pointer.c \
ft_putnbr.c \
ft_putstr.c \
ft_unsigned_putnbr.c \

BONUS_SRC =

BONUS_OBJ = $(BONUS_SRC:.c=.o)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $^
	ranlib $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $^

bonus : $(OBJ) $(BONUS_OBJ)
	ar rc $(NAME) $^
	ranlib $(NAME)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
