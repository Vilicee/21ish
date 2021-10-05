/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 13:20:19 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/20 16:05:33 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/to_ish.h"

static int	ft_execute(char **array, char *command, char **var, pid_t child)
{
	int		process;
	pid_t	pid;

	if (child == 0)
	{
		if (execve(command, array, var) == -1)
		{
			if (array)
				ft_free_array(array);
			if (command)
				free(command);
			return (-1);
		}
	}
	else
	{
		pid = waitpid(child, &process, 0);
		while (pid > 0)
			pid = waitpid(child, &process, 0);
	}
	if (array)
		ft_free_array(array);
	if (command)
		free(command);
	return (0);
}

int	ft_execve(char *str, t_to_ish *data, char *command)
{
	char	**array;
	char	*temp;
	pid_t	child;

	if (command)
		data->temp = ft_extract_command_path(data->variables, "PATH",
				command, data);
	if (ft_strcmp(data->temp, "") == 0 || data->temp == NULL)
	{
		if (data->temp)
			free(data->temp);
		return (-1);
	}
	temp = ft_command_parser(str, 0, 0);
	array = ft_strsplit(temp, ' ');
	free(temp);
	data->arr_temp = ft_arrdup(array);
	ft_free_array(array);
	array = ft_arr_trim(data->arr_temp);
	ft_free_array(data->arr_temp);
	free(array[0]);
	array[0] = ft_strdup(data->temp);
	ft_printf("datatemp: |%s| command |%s| temp |%s| str |%s|\n", data->temp, command, temp, str);
	child = fork();
	if (ft_strchr(str, '|') != NULL)
	{
//		free(data->temp);
		ft_execute_with_pipes(array, str, data->variables, child);
	}
	return (ft_execute(array, data->temp, data->variables, child));
}
