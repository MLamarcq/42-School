/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:48:47 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/12/29 13:14:45 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;

void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_atoi(const char *nptr);
void	ft_bzero(void *str, int len);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_substr(char const *s, int start, int len);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr(int nb);
int		ft_putnbr_len(int nb);
int		ft_print_nb(int nb);
void	ft_unsigned_putnbr(unsigned int nb);
int		ft_unsigned_putnbr_len(unsigned int nb);
int		ft_print_unsigned_nb(unsigned int nb);
void	ft_put_big_x(unsigned int nb);
int		ft_hexa_len(unsigned int nb);
int		ft_hexa_len_long(unsigned long long int nb);
int		ft_print_big_x(unsigned int nb);
void	ft_put_little_x(unsigned int nb);
int		ft_print_little_x(unsigned int nb);
void	ft_put_pointer(unsigned long long int);
int		ft_print_pointer(unsigned long long int);
int		ft_print_purcent(void);
int		ft_printf(const char*, ...);
int    	ft_format(va_list arg, unsigned char c);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_strlen(const char *str);

#endif