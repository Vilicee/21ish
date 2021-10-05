/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 10:33:59 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/05 14:49:44 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	i;
	size_t	ii;
	size_t	ret;

	i = 0;
	if (!dest || !src)
		return (-1);
	while (dest[i] != '\0')
		i++;
	ret = 0;
	while (src[ret] != '\0')
		ret++;
	if (len <= i)
		ret = ret + len;
	else
		ret = ret + i;
	ii = 0;
	while (src[ii] != '\0' && i + 1 < len)
	{
		dest[i] = src[ii];
		i++;
		ii++;
	}
	dest[i] = '\0';
	return (ret);
}
