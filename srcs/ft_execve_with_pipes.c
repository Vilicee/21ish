/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve_with_pipes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:57:52 by ehelmine          #+#    #+#             */
/*   Updated: 2021/10/06 15:48:35 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** Array[0] has executable with path (/bin/ls -> ls)
*/

int	ft_execute_with_pipes(char **array, char *org_str, char **var, pid_t child)
{
//	int		process;
//	pid_t	pid;
	char	**pipe_arr;
//	int		fd[2];

	pipe_arr = NULL;
	pipe_arr = ft_strsplit(org_str, '|');
	ft_print_array(pipe_arr);
	ft_printf("arr[0] %s var[0] %s child %i\n", array[0], var[0], (int)child);
	ft_free_array(pipe_arr);
	return (1);
}