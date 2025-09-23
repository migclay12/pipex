/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:50:27 by miggonza          #+#    #+#             */
/*   Updated: 2023/11/29 11:00:01 by miggonza         ###   ########.fr       */
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

void	ft_pipex_doc(int argc, char **argv, char **env)
{
	int	fd[2];
	int	status;

	if (pipe(fd) < 0)
		ft_print_error("Error");
	ft_child_doc(argv, env, fd);
	ft_child_output(argv, env, fd, argc - 2);
	close(fd[0]);
	close(fd[1]);
	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);
}

void	ft_here_doc(int argc, char **argv, char **env)
{
	int		file;
	char	*buf;

	file = open("here_doc", O_CREAT | O_WRONLY | O_TRUNC, 00666);
	if (file < 0)
		ft_perror("here_doc");
	while (1)
	{
		write(1, "here_doc> ", 10);
		buf = get_next_line(0);
		if (!ft_strncmp(argv[2], buf, ft_strlen(buf) - 1))
			break ;
		write(file, buf, ft_strlen(buf));
		free(buf);
	}
	free(buf);
	close(file);
	ft_pipex_doc(argc, argv, env);
}
