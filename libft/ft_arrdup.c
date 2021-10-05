/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 14:50:55 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/05 14:49:44 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_arrdup(char **array)
{
	char		**copy;
	int			i;
	int			len;

	i = 0;
	len = 0;
	while (array[len])
		len++;
	copy = (char **)malloc(sizeof(char *) * (len + 1));
	if (copy)
	{
		while (array[i])
		{
			copy[i] = ft_strdup(array[i]);
			i++;
		}
		copy[i] = NULL;
	}
	return (copy);
}
