/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:33:11 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/05 14:49:44 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strcjoin(char const *s1, char c, char const *s2)
{
	char	*fresh;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	fresh = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!fresh)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		fresh[i] = s1[i];
		i++;
	}
	fresh[i++] = c;
	while (*s2 != '\0')
	{
		fresh[i] = *s2;
		i++;
		s2++;
	}
	fresh[i] = '\0';
	return (fresh);
}
