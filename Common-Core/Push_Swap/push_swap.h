/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:52:30 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/10/31 14:27:08 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct s_list
{
	long int		nbr;
	int				index;
	int				position;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_list	*next;
}	t_list;

long int	ft_atoi(char *str);
int			main(int argc, char **argv);
t_list		*ft_lstnew(long int nbr);
int			ft_init_list(char **argv, t_list **list_a);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			ft_check_double(char **str);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_push_a(t_list **lst_a, t_list **lst_b);
void		ft_push_b(t_list **lst_b, t_list **lst_a);
void		t_lstclear(t_list **lst);
void		ft_swap_list(t_list **lst);
void		ft_swap_a(t_list **lst);
void		ft_swap_b(t_list **lst);
void		ft_double_swap(t_list **lst, t_list **lst2);
void		ft_lst_rotate(t_list **lst);
void		ft_lst_rotate_a(t_list **lst);
void		ft_lst_rotate_b(t_list **lst);
void		ft_double_rotate(t_list **lst, t_list **lst2);
void		ft_lstlast(t_list **lst);
void		ft_lst_reverse(t_list **lst);
void		ft_lst_reverse_a(t_list **lst);
void		ft_lst_reverse_b(t_list **lst);
void		ft_lst_double_reverse(t_list **lst, t_list **lst2);
void		ft_lst_prevlast(t_list **lst);
int			ft_lstsize(t_list **lst);
void		ft_index2(t_list **lst);
void		ft_tri_3(t_list **lst);
void		ft_rra_sa(t_list **lst);
void		ft_ra_sa(t_list **lst);
void		ft_ra_recurs(t_list **lst);
int			ft_lstsize2(t_list **lst);
void		ft_mediane_push_b(t_list **lst, t_list **lst2);
void		ft_nbr_3_lst_a(t_list **lst1, t_list **lst2);
void		ft_position(t_list **lst);
void		ft_position2(t_list **lst);
void		ft_target_pos(t_list **lst, t_list **lst1);
void		ft_cost(t_list **lst, t_list **lst1);
void		ft_costa_mouv(t_list **lst, int i);
void		ft_costb_mouv(t_list **lst, int i);
void		ft_exct_mouv(t_list **lst, t_list **lst1, int i, int j);
int			ft_total_cost(t_list **lst);
int			ft_absol_value(int nbr);
int			ft_get_min(t_list **lst);
void		ft_do_mouv(t_list **lst, t_list **lst1);
void		ft_sort(t_list **lst, t_list **lst1);
void		ft_target_pos2(t_list **lst, t_list **lst1);
int			ft_index_min_2(t_list **lst);
void		ft_last_move(t_list **lst);
int			ft_verif(t_list **lst);
void		ft_push_swap(t_list **lst, t_list **lst1, int i);
void		ft_lstclear(t_list **lst);

#endif