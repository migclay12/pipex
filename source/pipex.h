/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:33:09 by miggonza          #+#    #+#             */
/*   Updated: 2025/09/24 01:44:24 by marvin           ###   ########.fr       */
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

/*
 * Pipex - A Unix pipe implementation in C
 * This program simulates the behavior of shell pipes (|)
 * Usage: ./pipex file1 cmd1 cmd2 file2
 *        ./pipex here_doc LIMITER cmd1 cmd2 file2
 */

/* Main pipex functions */
void	ft_pipex(int argc, char **argv, char **env);           /* Basic pipex: file1 cmd1 cmd2 file2 */
void	ft_pipex_bonus(int argc, char **argv, char **env);     /* Multiple pipes support */

/* Path handling functions */
int		ft_find_path(char **env);                            /* Find PATH in environment */
char	*ft_join_path(char *cmd, char **env);                 /* Build full path for command */
void	ft_execve(char *argv, char **env);                    /* Execute command with path */

/* Error handling functions */
void	ft_print_error(char *str);                             /* Print custom error message */
void	ft_perror(char *str);                                 /* Print system error message */

/* Child process functions */
void	ft_child_input(char **argv, char **env, int *fd);      /* First child - reads from input file */
void	ft_child_output(char **argv, char **env, int *fd, int argc); /* Last child - writes to output file */

/* Bonus functions */
void	ft_child_middle(char *argv, char **env, int *fd);     /* Middle children for multiple pipes */
void	ft_here_doc(int argc, char **argv, char **env);        /* Handle here_doc functionality */
void	ft_child_doc(char **argv, char **env, int *fd);        /* Child for here_doc input */

#endif