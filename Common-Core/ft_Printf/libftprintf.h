#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <stdio.h>
#include <stdarg.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_strlen(char *str);
void	ft_putnbr(int nb);
int		ft_putnbr_len(int nb);
int		ft_print_nb(int nb);
void	ft_unsigned_putnbr(unsigned int nb);
int		ft_unsigned_putnbr_len(unsigned int nb);
int		ft_print_unsigned_nb(unsigned int nb);
void	ft_put_big_x(unsigned int nb);
int		ft_hexa_len(unsigned int nb);
int	ft_hexa_len_long(unsigned long long int nb);
int		ft_print_big_x(unsigned int nb);
void	ft_put_little_x(unsigned int nb);
int		ft_print_little_x(unsigned int nb);
void	ft_put_pointer(unsigned long long int);
int		ft_print_pointer(unsigned long long int);
int	ft_print_purcent(void);
int		ft_printf(const char*, ...);
int    	ft_format(va_list arg, unsigned char c);

#endif