NAME := so_long.a
SOFT_NAME := so_long
LIBFT := Libft/libft.a
MLX := mlx/mlx.a

CC := gcc

CFLAGS := -Wall -Wextra -Werror -g3 -L ./mlx -lmlx -lXext -lX11 -lm -lz

SRC = ft_check_way.c \
ft_error.c \
ft_file.c \
ft_free_str.c \
ft_image.c \
ft_initmap.c \
ft_key.c \
ft_map.c \
ft_move.c \
ft_move_map.c \
ft_rectangle.c \
ft_wall.c \
ft_way.c \
ft_xpm.c \
get_next_line.c \
get_next_line_utils.c \
main.c \


BONUS_OBJ = $(BONUS_SRC:.c=.o)

OBJ := $(SRC:.c=.o)

all: ${LIBFT} $(NAME) $(SOFT_NAME)

${LIBFT} :
	${MAKE} all -C Libft
	${MAKE} all -C mlx
	cp ${LIBFT} ${NAME}


$(NAME): $(OBJ)
	rm -f $(SOFT_NAME)
	ar rc $(NAME) $^
	ranlib $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $^

$(SOFT_NAME):
	$(CC) $(NAME) $(CFLAGS) $^ -o $(SOFT_NAME)

bonus : $(OBJ) $(BONUS_OBJ)
	ar rc $(NAME) $^
	ranlib $(NAME)

clean:
	${MAKE} clean -C Libft
	${MAKE} clean -C mlx
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	${MAKE} fclean -C Libft
	rm -f $(NAME)
	rm -f $(SOFT_NAME)

re: fclean all

.PHONY: all bonus clean fclean re




