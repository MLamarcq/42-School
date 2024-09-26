/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:58:11 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/12/15 15:07:47 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned int	i;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (s1[i] && (s1[i] == s2[i]) && i < (n - 1))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*ft_findpath(char **str)
{
	int		i;
	char	*dest;

	i = 0;
	while (str[i])
	{	
		if (ft_strncmp(str[i], "PATH=", 5) == 0)
		{
			dest = str[i];
			return (dest);
		}
		i++;
	}
	return (NULL);
}

char	*ft_build_path(t_proc *proc, char *str, char *cmd)
{
	char	*tmp;
	char	**src;
	int		i;

	if (!str || !cmd)
		return (write(2, "command not found\n", 19), NULL);
	i = 0;
	src = ft_split(str, ':');
	while (src[i])
	{
		tmp = src[i];
		src[i] = ft_strjoin(src[i], "/");
		ft_free(tmp, NULL);
		i++;
	}
	i = -1;
	while (src[++i])
	{
		proc->cmd_path = ft_strjoin(src[i], cmd);
		if (access(proc->cmd_path, F_OK | X_OK) == 0)
			return (ft_free(NULL, src), proc->cmd_path);
		ft_free(proc->cmd_path, NULL);
	}
	write(2, "command not found\n", 19);
	return (ft_free(NULL, src), NULL);
}

char	*if_path(t_proc *proc, char **argv)
{
	char	**str;
	
	str = ft_split(argv[proc->cmd], ' ');
	if (access(str[0], F_OK | X_OK) == 0)
	{
		proc->cmd_path = str[0];
		return (proc->cmd_path);
	}
	return (NULL);
}

char	*ft_use_path(t_proc *proc, char **envp, char **argv, char *cmd)
{
	// char	**str;
	// str = ft_split(argv[proc->cmd], ' ');
	// if (access(str[0], F_OK | X_OK) == 0)
	// {
	// 	proc->cmd_path = str[0];
	// 	return (proc->cmd_path);
	// }
	(void)argv;
	proc->cmd_path = ft_build_path(proc, ft_findpath(envp), cmd);
	if (proc->cmd_path == NULL)
	{
		ft_free(proc->cmd_path, NULL);
		//ft_free(NULL, str);
		return (NULL);
	}
	return (proc->cmd_path);
}
