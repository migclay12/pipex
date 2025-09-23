/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:32:46 by miggonza          #+#    #+#             */
/*   Updated: 2025/09/24 01:44:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_print_error(char *str)
{
	ft_putstr_fd("pipex: ", 2);
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
	if (argc < 5)
		ft_print_error("insufficient arguments. Usage: ./pipex file1 cmd1 cmd2 file2");
	if (argc == 5)
		ft_pipex(argc, argv, env);
	if (argc > 5)
	{
		if (!ft_strncmp("here_doc", argv[1], 9))
		{
			if (argc != 6)
				ft_print_error("Wrong number of commands");
			ft_here_doc(argc, argv, env);
			unlink("here_doc");
		}
		else
			ft_pipex_bonus(argc, argv, env);
	}
	return (0);
}
