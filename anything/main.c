/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:32:46 by miggonza          #+#    #+#             */
/*   Updated: 2023/11/22 19:28:21 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//unlink(); -- BONUS

void	ft_print_error(char *str)
{
	ft_putstr_fd(str, 2);
	write(2, "\n", 1);
	exit(1);
}

void	ft_perror(char *str)
{
	perror(str);
	exit(1);
}

void	wtf(char **argv, char **env)
{
	int	fd[2];
	int	status;

	if (pipe(fd) < 0)
		ft_print_error("ERRRRROR");
	ft_read_file(argv, env, fd);
	ft_write_file(argv, env, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);
}

void	wtf_bonus(int argc, char **argv, char **env)
{
	int	fd[2];
	int	status;
	int	num_cmd;
	int	i;

	num_cmd = argc - 3;
	if (pipe(fd) < 0)
		ft_print_error("ERRRRROR");
	i = 3;
	ft_read_file(argv, env, fd);
	while (i < argc - 2)
	{
		ft_child_middle(argv[i], env, fd);
		i++;
	}
	ft_write_file_bonus(argv, env, fd, argc - 2);
	close(fd[0]);
	close(fd[1]);
	while (num_cmd >= 0)
	{
		waitpid(-1, &status, 0);
		num_cmd--;
	}
}

int	main(int argc, char **argv, char **env)
{
	ft_find_path(env);
	if (argc < 5)
		ft_print_error("ERROR NOT ENOUGH COMMANDS\n");
	if (argc == 5)
		wtf(argv, env);
	if (argc > 5)
		wtf_bonus(argc, argv, env);
	return (0);
}

	/*
	pid_t hola = fork();
	int file;
	if (hola == 0)
	{
		file = open("file1", O_RDONLY);
		dup2(file, 0);
		close(file);
		char *cmd[] = {"cat", "-e", NULL};
		//execve("/bin/cat", cmd, env);
		execve(rec, cmd, env);
	}
	*/