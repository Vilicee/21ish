/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 16:06:53 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/05 14:49:44 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordcount(const char *str, char c)
{
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (i > 0)
		{
			if (str[i] == c && str[i - 1] != c)
				count++;
		}
		i++;
		if (str[i] == '\0' && str[i - 1] != c)
			count++;
	}
	return (count);
}
