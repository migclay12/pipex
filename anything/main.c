/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:32:46 by miggonza          #+#    #+#             */
/*   Updated: 2023/09/27 13:21:03 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//| is a “pipe”. The | takes the standard output of the command on 
//the left, and pipes it as standard input to the command on the right.
//You can think of this as “command to command” redirection.

// < file1 cmd1 | cmd2 > file2
void	ft_print_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

void	ft_perror(char *str)
{
	perror(str);
	exit(0);
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
//int	status;
//waitpid(-1, &status, 0);
//waitpid(-1, &status, 0);

int	main(int argc, char **argv, char **env)
{
	ft_find_path(env);
	if (argc != 5)
		ft_print_error("ERROR NOT ENOUGH COMMANDS\n");
	wtf(argv, env);
	return (0);
}
	/*
	if (argc < 5)
	{
		ft_printf("ERROR4\n");
		return (0);
	}

	pid_t hola = fork();
	int file;
	if (hola == 0)
	{
		file = open(argv[1], O_RDONLY);
		dup2(file, 0);
		close(file);
		//char *cmd[] = {argv[2], NULL};
		ft_split_cmd(argv[2], env);
		//execve("/bin/cat", cmd, env);
		//execve(rec, cmd, env);
	}
	*/

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

	/*
	execve();
	fork();
	pipe();
	access();
	dup2();
	waitpid();
	dup(); -- NO SE USA
	unlink(); -- BONUS
	*/