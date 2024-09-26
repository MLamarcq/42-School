/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:58:12 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/07/21 10:58:12 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

unsigned int	ft_strlen(const char *str);
char			*ft_strchr(const char *str, int c);
char			*ft_strjoin(char *str1, char *str2);
char			*ft_strdup(char *str);
void			ft_keep_line(char *str, char *temp);
char			*get_next_line(int fd);

#endif