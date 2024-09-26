NAME := push_swap

CC := gcc

CFLAGS := -Wall -Wextra -Werror

SRC = ft_absol_value.c \
ft_atoi.c \
ft_check_double.c \
ft_cost.c \
ft_get_min.c \
ft_index2.c \
ft_init_list.c \
ft_last_move.c \
ft_lstadd_back.c \
ft_lstadd_front.c \
ft_lstclear.c \
ft_lstlast.c \
ft_lstnew.c \
ft_lst_prevlast.c \
ft_lst_reverse.c \
ft_lst_rotate.c \
ft_lst_size2.c \
ft_mediane_push_b.c \
ft_nbr_3_lst_a.c \
ft_position2.c \
ft_push.c \
ft_push_swap.c \
ft_sort.c \
ft_swap_list.c \
ft_target_pos.c \
ft_tri_3.c \
ft_tri_3_ft.c \
main.c \

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
