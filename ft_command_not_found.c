/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_not_found.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 12:34:17 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/05 13:43:43 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_command_not_found(char *command, t_shell *data)
{
	int	len;

	if (command)
	{
		len = ft_strlen(command);
		if (len == 1 && command[0] == '\\')
			ft_putstr("minishell: command not found:\n");
		else if (data->exec_fail == '1')
			ft_printf("minishell: permission denied: %s\n", command);
		else
			ft_printf("minishell: command not found: %s\n", command);
	}
	else
		ft_putstr("malloc has failed, not enough memory on system\n");
}
