/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:20:59 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/12/08 13:20:59 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "mlx/mlx.h"
# include "Libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>

#define BUFFER_SIZE 1

typedef struct s_shape
{
    int		i;
	int		j;
	int		c;
	int		p;
	int		e;
	char	**final;
	int		fd;
	char	*tmp;
	int		y;
	int		x;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		size;
	void	*O;
	void	*L;
	void	*P;
	void	*E;
	void	*C;
	void	*M;
	int		move;
} t_shape;


//get_next_line.c
char			*get_next_line(int fd);

//get_next_line_utils.c
//int				ft_strlen(const char *str);
char			*ft_strchr(const char *str, int c);
char			*ft_strjoin(char *str1, char *str2);
char			*ft_strdup(char *str);
void			ft_keep_line(char *str, char *temp);

//ft_initmap.c
int				ft_nbr_of_line(t_shape *shp, char *file);
char			**ft_initmap(t_shape *shp, char *file);

//ft_rectangle.c
int				ft_rect_shp(t_shape *shp);
int				ft_rect_shp_2(t_shape *shp);
int				ft_size_verif(t_shape *shp);

//ft_wall.c
int				ft_first_line(t_shape *shp, char *file, char c);
int				ft_middle(t_shape *shp, char c);
int				ft_last_line(t_shape *shp, char c);
int				ft_wall(t_shape *shp, char *file, char c);

//ft_map.c
int				ft_map(t_shape *shp, char c, char p, char e);
void			ft_init_items(t_shape *shp);
int				ft_check_map(t_shape *shp, char c, char p, char e);
//int				ft_error_map(t_shape *shp, char c, char p, char e);

int				ft_find_line(t_shape *shp, char c);
int				ft_transform_line(t_shape *shp, char p);
int				ft_transform_map(t_shape *shp, char p);
int				ft_transform_map_2(t_shape *shp, char p);

//ft_way.c
void			ft_change(t_shape *shp, char p, int x, int y);
int				ft_transform_bis(t_shape *shp, char p);
int				ft_verif(t_shape *shp, char p);

//ft_check_way.c
void			ft_check_p(t_shape *shp, char e);
int				ft_check_e(t_shape *shp, char p, char e);
int				ft_check_full(t_shape *shp, char p, char e);

//ft_error.c
int				ft_error_shape(t_shape *shp, char *file);
int				ft_error_map(t_shape *shp);
int				ft_check_item(t_shape *shp);
int				ft_check_error(t_shape *shp, char *file);

//ft_file.c
int				ft_file( char *file);
int				ft_file_error(char *file);

//ft_free_str.c
void			ft_free_str(char **str);
int			ft_free_all(t_shape *shp);

//ft_xpm.c
void			ft_init_xpm(t_shape *shp);
int				ft_xpm_to_image(t_shape *shp);
void			ft_destroy_image_xpm(t_shape *shp);
int				ft_xpm(t_shape *shp);

//ft_image.c
void			ft_put_image(t_shape *shp);
void			ft_image_put(t_shape *shp, int i, int j);

//ft_key.c
int				ft_key_release(int key, t_shape *shp);
int				ft_key_press(int key, t_shape *shp);
void			ft_config(t_shape *shp, char *file);

//ft_change_map.c
int				ft_change_map(t_shape *shp, char dir);
int				ft_map_move(t_shape *shp, char dir, int y, int x);

//ft_move.c
int    			ft_move_up(t_shape *shp, int y, int x);
int   			ft_move_down(t_shape *shp, int y, int x);
int    			ft_move_left(t_shape *shp, int y, int x);
int    			ft_move_right(t_shape *shp, int y, int x);

//ft_move_map.c
int				ft_move_map(t_shape *shp, char dir);

//main.c
int				main(int argc, char **argv);

#endif