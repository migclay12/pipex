/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:32:46 by miggonza          #+#    #+#             */
/*   Updated: 2023/11/23 13:04:48 by miggonza         ###   ########.fr       */
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

int	main(int argc, char **argv, char **env)
{
	ft_find_path(env);
	if (argc < 5)
		ft_print_error("Error, less than 5 commands");
	if (argc == 5)
		ft_pipex(argc, argv, env);
	if (argc > 5)
		ft_pipex_bonus(argc, argv, env);
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