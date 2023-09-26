/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:37:32 by miggonza          #+#    #+#             */
/*   Updated: 2023/09/26 13:55:50 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_read_file(char **argv, char **env, int *fd)
{
	pid_t	hola;
	int		file;

	hola = fork();
	if (hola == 0)
	{
		file = open(argv[1], O_RDONLY);
		close(fd[0]);
		dup2(file, 0);
		dup2(fd[1], 1);
		ft_split_cmd(argv[2], env);
	}
}

void	ft_write_file(char **argv, char **env, int *fd)
{
	pid_t	hola;
	int		file;

	hola = fork();
	if (hola == 0)
	{
		file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
		close(fd[1]);
		dup2(file, 1);
		dup2(fd[0], 0);
		ft_split_cmd(argv[3], env);
	}
}

//if (hola < 0)
	//	ft_perror("fork ");
//if (file < 0)
	//	ft_perror(argv[1]);
//if (file < 0)
		//	ft_perror(argv[4]);