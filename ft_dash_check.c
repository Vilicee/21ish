/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dash_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 17:58:54 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/17 17:02:50 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/to_ish.h"

int	ft_dash_check(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len == 1)
	{
		if (str[0] == '-')
			return (1);
	}
	if (len == 2)
	{
		if (str[0] == '-' && str[1] == '-')
			return (2);
	}
	if (str[0] == '~' && str[1] == '/')
		return (3);
	return (0);
}