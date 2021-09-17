/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_not_found.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 12:34:17 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/17 17:02:31 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/to_ish.h"

void	ft_command_not_found(char *command, t_to_ish *data)
{
	int	len;

	if (command)
	{
		len = ft_strlen(command);
		if (len == 1 && command[0] == '\\')
			ft_putstr("21ish: command not found: \" or \'\n");
		else if (data->exec_fail == '1')
			ft_printf("21ish: permission denied: %s\n", command);
		else
			ft_printf("21ish: command not found: %s\n", command);
	}
	else
		ft_putstr("malloc has failed, not enough memory on system\n");
}
