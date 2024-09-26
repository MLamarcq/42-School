/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:58:52 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/12/15 10:10:35 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_proc	proc;

	if (argc == 5)
	{
		init_file(&proc, argv);
		proc.cmd = 2;
		ft_child_1(&proc, argv, envp);
		++proc.cmd;
		ft_child_2(&proc, argv, envp);
		ft_dad(&proc);
	}
	else if (argc < 5)
		write(2, "you need more arg !\n", 21);
	else if (argc > 5)
		write(2, "there are too much args !\n", 27);
	return (0);
}
