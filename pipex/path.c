/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:25:03 by miggonza          #+#    #+#             */
/*   Updated: 2023/09/22 10:25:03 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_matrix(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		;
	while (--i >= 0)
		free(matrix[i]);
	free(matrix);
}

int	ft_find_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (i);
		i++;
	}
	ft_print_error("Path not found");
	return (i);
}

void	ft_split_cmd(char *argv, char **env)
{
	char	**cmd;
	char	*send;

	cmd = ft_split(argv, ' ');
	if (!cmd || !cmd[0])
		ft_print_error("command not found\n");
	send = ft_join_path(cmd[0], env);
	if (execve(send, cmd, env) == -1)
		ft_print_error("Error command not executable?");
}

char	*ft_join_path(char *cmd, char **env)
{
	int		i;
	char	**save;
	char	*join;
	char	*join2;

	i = ft_find_path(env);
	save = ft_split(env[i] + 5, ':');
	i = 0;
	while (save[i])
	{
		join = ft_strjoin(save[i], "/");
		join2 = ft_strjoin(join, cmd);
		free(join);
		if (access(join2, X_OK) == 0)
		{
			//ft_free_matrix(save);
			printf("%s\n", join2);
			return (join2);
		}
		free(join2);
		i++;
	}
	//ft_free_matrix(save);
	ft_print_error("Error command not found");
	return (0);
}
