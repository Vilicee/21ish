/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 18:26:41 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/05 14:49:44 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_realloc_array(char **array, int i)
{
	int		len;
	char	**temp;

	len = 0;
	while (array[len])
		len++;
	temp = (char **)malloc(sizeof(char *) * (len + i + 1));
	if (temp)
	{
		temp[len + i] = NULL;
		len = 0;
		while (array[len] != NULL)
		{
			temp[len] = ft_strdup(array[len]);
			len++;
		}
	}
	return (temp);
}
