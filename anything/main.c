/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:32:46 by miggonza          #+#    #+#             */
/*   Updated: 2023/11/15 12:51:43 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//unlink(); -- BONUS

void	ft_print_error(char *str)
{
	ft_putstr_fd(str, 2);
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

void	wtf2(int argc, char **argv, char **env)
{
	int	fd[2];
	int	status;
	int num_cmd;

	num_cmd = argc - 3;
	if (pipe(fd) < 0)
		ft_print_error("ERRRRROR");
	ft_read_file(argv, env, fd);
	ft_write_file(argv, env, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);
}


int	main(int argc, char **argv, char **env)
{
	ft_find_path(env);
	if (argc < 5)
		ft_print_error("ERROR NOT ENOUGH COMMANDS\n");
	if (argc == 5)
		wtf(argv, env);
	if (argc > 5)
		wtf2(argc, argv, env);
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