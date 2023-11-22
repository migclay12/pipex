/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:33:09 by miggonza          #+#    #+#             */
/*   Updated: 2023/11/22 19:21:06 by miggonza         ###   ########.fr       */
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

//LEFT == 1
//RIGHT == 0

int		ft_find_path(char **env);
char	*ft_join_path(char *cmd, char **env);
void	ft_split_cmd(char *argv, char **env);

void	ft_print_error(char *str);
void	ft_perror(char *str);

void	ft_read_file(char **argv, char **env, int *fd);
void	ft_write_file(char **argv, char **env, int *fd);

void	ft_write_file_bonus(char **argv, char **env, int *fd, int argc);
void	ft_child_middle(char *argv, char **env, int *fd);

#endif