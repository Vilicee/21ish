/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 13:53:37 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/05 13:42:48 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_check_dot(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len == 1)
		if (str[0] == '.')
			return (1);
	if (len == 2)
		if (str[0] == '.' && str[1] == '.')
			return (2);
	if (len > 2)
		if (str[0] == '.' && str[1] == '.' && str[2] == '/')
			return (3);
	return (0);
}
