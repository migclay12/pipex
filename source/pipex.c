/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:50:27 by miggonza          #+#    #+#             */
/*   Updated: 2023/11/23 12:41:29 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipex(int argc, char **argv, char **env)
{
	int	fd[2];
	int	status;

	if (pipe(fd) < 0)
		ft_print_error("Error");
	ft_child_input(argv, env, fd);
	ft_child_output(argv, env, fd, argc - 2);
	close(fd[0]);
	close(fd[1]);
	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);
}

void	ft_pipex_bonus(int argc, char **argv, char **env)
{
	int	fd[2];
	int	status;
	int	num_cmd;
	int	i;

	num_cmd = argc - 3;
	if (pipe(fd) < 0)
		ft_print_error("Error");
	i = 3;
	ft_child_input(argv, env, fd);
	while (i < argc - 2)
	{
		ft_child_middle(argv[i], env, fd);
		i++;
	}
	ft_child_output(argv, env, fd, argc - 2);
	close(fd[0]);
	close(fd[1]);
	while (num_cmd >= 0)
	{
		waitpid(-1, &status, 0);
		num_cmd--;
	}
}
