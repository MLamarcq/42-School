/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:10:50 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/12/15 10:10:50 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_proc
{
	pid_t	id1;
	pid_t	id2;
	int		fd[2];
	char	*cmd_path;
	int		infile;
	int		outfile;
	int		cmd;
	char	**option1;
	char	**option2;
}	t_proc;

// main.c
int				main(int argc, char **argv, char **envp);

// ft_path.c
int				ft_strncmp(const char *str1, const char *str2, size_t n);
char			*ft_findpath(char **str);
char			*ft_build_path(t_proc *proc, char *str, char *cmd);
char			*ft_use_path(t_proc *proc, char **envp, char **argv, char *cmd);
char			*if_path(t_proc *proc, char **argv);

// ft_split.c
char			**ft_split(char const *s, char c);

// ft_strjoin.c
char			*ft_strjoin(char *s1, char *s2);
int				ft_strlen(char *str);

//ft_child.c
void			init_file(t_proc *proc, char **argv);
void			ft_close(t_proc *proc);
void			ft_child_1(t_proc *proc, char **argv, char **envp);
void			ft_child_2(t_proc *proc, char **argv, char **envp);
void			ft_dad(t_proc *proc);

//ft_free_str.c
void			ft_free(char *str, char **strs);
#endif