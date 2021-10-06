/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linelength.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 08:48:07 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/05 14:49:44 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_linelength(const char *str, char c)
{
	size_t	count;

	count = 0;
	if (!str)
		return (-1);
	if (*str != c)
	{
		while (*str != c && *str)
		{
			str++;
			count++;
		}
		return (count);
	}
	if (*str == c)
		count++;
	return (count);
}
