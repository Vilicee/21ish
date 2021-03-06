/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:41:04 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/05 13:54:45 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_mini_echo(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == '\0')
		{
			if (ft_is_quote(str[i]) == 1)
				c = str[i++];
		}
		if (str[i] == c)
			i++;
		i = ft_write(str, i, c);
	}
}
