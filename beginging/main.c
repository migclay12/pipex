/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:32:46 by miggonza          #+#    #+#             */
/*   Updated: 2023/09/22 13:13:12 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//| is a “pipe”. The | takes the standard output of the command on 
//the left, and pipes it as standard input to the command on the right.
//You can think of this as “command to command” redirection.

// < file1 cmd1 | cmd2 > file2
void	ft_print_error(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

int	main(int argc, char **argv, char **env)
{
	
	if (argc > 6)
		ft_print_error("Error main");
	
	//int i = 0;
	//i = ft_find_path(env);

	//char *rec;
	//rec = ft_join_path(argv[2], env);

	

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

	pid_t h = fork();
	int f;
	if (h == 0)
	{
		f = open(argv[1], O_RDONLY);
		dup2(f, 0);
		close(f);
		ft_split_cmd(argv[3], env);
	}

	return (0);
}
	/*
	if (argc < 5)
	{
		ft_printf("ERROR4\n");
		return (0);
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