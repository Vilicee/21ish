/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_echo_flag.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:29:39 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/16 14:13:23 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static int	ft_find_start(char *str)
{
	int	i;

	i = 4;
	if (ft_is_quote(str[0]) == 1)
		i = 6;
	while (str[i])
	{
		if (ft_isspace(str[i]) == 0)
			return (i);
		i++;
	}
	return (0);
}

int	ft_check_echo_flag(char *str, int ret)
{
	int	i;

	i = ft_find_start(str);
	if (str[i] == '\0')
		return (2);
	while (str[i])
	{
		if (str[i] != ' ')
		{
			if (str[i] == '-' && str[i + 1] == 'n')
			{
				i++;
				while (str[i] == 'n')
					i++;
				if (str[i] != '\n' && str[i] != '\0')
					return (1);
				else
					return (2);
			}
			else
				return (0);
		}
		i++;
	}
	return (ret);
}
