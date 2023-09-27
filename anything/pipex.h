/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:33:09 by miggonza          #+#    #+#             */
/*   Updated: 2023/09/26 14:01:37 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>

int		ft_find_path(char **env);
char	*ft_join_path(char *cmd, char **env);
void	ft_split_cmd(char *argv, char **env);

void	ft_print_error(char *str);
void	ft_perror(char *str);

void	ft_read_file(char **argv, char **env, int *fd);
void	ft_write_file(char **argv, char **env, int *fd);

#endif