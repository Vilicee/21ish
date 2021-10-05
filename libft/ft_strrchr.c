/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:32:51 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/05 14:49:44 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ptr;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	ptr = ((char *)str);
	while (str[i] != '\0')
	{
		ptr++;
		i++;
	}
	while (i >= 0)
	{
		if (str[i] == c)
			return (ptr);
		if (c == '\0' && str[i + 1] == '\0')
		{
			ptr++;
			return (ptr);
		}
		ptr--;
		i--;
	}
	return (NULL);
}
