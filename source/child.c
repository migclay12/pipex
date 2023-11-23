/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:37:32 by miggonza          #+#    #+#             */
/*   Updated: 2023/11/23 12:54:19 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_input(char **argv, char **env, int *fd)
{
	pid_t	f;
	int		file;

	f = fork();
	if (f < 0)
		ft_perror("fork");
	if (f == 0)
	{
		file = open(argv[1], O_RDONLY);
		if (file < 0)
			ft_perror(argv[1]);
		close(fd[0]);
		dup2(file, 0);
		dup2(fd[1], 1);
		ft_execve(argv[2], env);
	}
}

void	ft_child_output(char **argv, char **env, int *fd, int argc)
{
	pid_t	f;
	int		file;

	f = fork();
	if (f < 0)
		ft_perror("fork");
	if (f == 0)
	{
		file = open(argv[argc + 1], O_WRONLY | O_CREAT | O_TRUNC);
		if (file < 0)
			ft_perror(argv[argc + 1]);
		close(fd[1]);
		dup2(file, 1);
		dup2(fd[0], 0);
		ft_execve(argv[argc], env);
	}
}

void	ft_child_middle(char *argv, char **env, int *fd)
{
	pid_t	f;
	int		save;

	save = fd[0];
	close(fd[1]);
	pipe(fd);
	f = fork();
	if (f < 0)
		ft_perror("fork");
	if (f == 0)
	{
		close(fd[0]);
		dup2(save, 0);
		dup2(fd[1], 1);
		ft_execve(argv, env);
	}
}

/*
void	ft_child_output(char **argv, char **env, int *fd)
{
	pid_t	f;
	int		file;

	f = fork();
	if (f < 0)
		ft_perror("fork");
	if (f == 0)
	{
		file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
		if (file < 0)
			ft_perror(argv[4]);
		close(fd[1]);
		dup2(file, 1);
		dup2(fd[0], 0);
		ft_execve(argv[3], env);
	}
}
*/