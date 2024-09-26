/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:57:22 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/12/13 14:57:22 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_file(t_proc *proc, char **argv)
{
	proc->infile = open(argv[1], O_RDWR);
	if (proc->infile == -1)
	{
		perror(argv[1]);
		close(proc->infile);
		exit(1);
	}
	proc->outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (proc->outfile == -1)
	{
		perror(argv[4]);
		close(proc->infile);
		close(proc->outfile);
		exit(1);
	}
	proc->option1 = ft_split(argv[2], ' ');
	proc->option2 = ft_split(argv[3], ' ');
}

void	ft_close(t_proc *proc)
{
	if (!proc->cmd_path)
	{
		close(proc->infile);
		close(proc->outfile);
		ft_free(proc->cmd_path, NULL);
		ft_free(NULL, proc->option1);
		ft_free(NULL, proc->option2);
		exit(127);
	}
}

void	ft_child_1(t_proc *proc, char **argv, char **envp)
{
	if (pipe(proc->fd) == -1)
		exit(1);
	proc->id1 = fork();
	if (proc->id1 == 0)
	{
		dup2(proc->infile, STDIN_FILENO);
		dup2(proc->fd[1], STDOUT_FILENO);
		close(proc->fd[0]);
		close(proc->fd[1]);
		if (ft_strncmp(argv[2], "/usr/bin", 8) == 0)
			proc->cmd_path = if_path(proc, argv);
		else
			proc->cmd_path = ft_use_path(proc, envp, argv, proc->option1[0]);
		ft_close(proc);
		close(proc->infile);
		close(proc->outfile);
		execve(proc->cmd_path, proc->option1, envp);
		ft_free(proc->cmd_path, NULL);
		ft_free(NULL, proc->option1);
		ft_free(NULL, proc->option2);
		exit (127);
	}
}

void	ft_child_2(t_proc *proc, char **argv, char **envp)
{
	proc->id2 = fork();
	if (proc->id2 == 0)
	{
		if (proc->outfile == -1)
			exit(1);
		dup2(proc->fd[0], STDIN_FILENO);
		dup2(proc->outfile, STDOUT_FILENO);
		close(proc->fd[0]);
		close(proc->fd[1]);
		if (ft_strncmp(argv[3], "/usr/bin", 8) == 0)
			proc->cmd_path = if_path(proc, argv);
		else
			proc->cmd_path = ft_use_path(proc, envp, argv, proc->option2[0]);
		ft_close(proc);
		close(proc->infile);
		close(proc->outfile);
		execve(proc->cmd_path, proc->option2, envp);
		ft_free(proc->cmd_path, NULL);
		ft_free(NULL, proc->option1);
		ft_free(NULL, proc->option2);
		exit (127);
	}
}

void	ft_dad(t_proc *proc)
{
	ft_free(NULL, proc->option1);
	ft_free(NULL, proc->option2);
	close(proc->fd[0]);
	close(proc->fd[1]);
	close(proc->infile);
	close(proc->outfile);
	waitpid(proc->id1, NULL, 0);
	waitpid(proc->id2, NULL, 0);
}
