/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:32:46 by miggonza          #+#    #+#             */
/*   Updated: 2023/09/20 13:50:04 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char **argv, char **env)
{
	/*
	execve();
	fork();
	pipe();
	access();
	dup2();
	dup(); -- NO SE USA
	unlink(); -- BONUS
	*/
	pid_t hola = fork();
	int file;
	if (hola == 0)
	{
		file = open("file1", O_RDONLY);
		dup2(file, 0);
		close(file);
		char *cmd[] = {"cat", "-e", NULL};
		execve("/bin/cat", cmd, env);
	}
	
	//con access se usa para nuscar si una direccion es correcta
	//entonces en env tengo que buscar el PATH y en el path hacer
	//un split por los ":" y pillar la direccion y luego hacer un
	//join con el comando mandado para ver si existe, si existte
	//se lo mando al execcve y sino sigo probando con los siguientes
	//y si no existe mando fallo

	//el fork se usa para crear dos ramas y uso la rama 0 pq la otra no se
	//que número aleatorio tengo y uso esa rama, pq si se ejecuta 
	//execve finaliza el programa asiq ir creando forks
	return (0);
}