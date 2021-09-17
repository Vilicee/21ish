/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_quotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 16:39:19 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/17 17:02:05 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/to_ish.h"

int	ft_check_quotation(char *str, int i, int ret, char c)
{
	i = ft_check_start(str);
	while (str[i])
	{
		if (ft_is_quote(str[i]) == 1 && str[i - 1] != '\\')
		{
			ret = -1;
			c = str[i];
			i++;
			while (str[i] != '\0' && str[i] != c)
			{
				i++;
				if (str[i] == c && str[i - 1] == '\\' && str[i + 1] == ' ')
					i++;
			}
			if (str[i] == '\0')
				return (-1);
			else
				ret = 0;
		}
		else if (str[i] != '\n')
			ret = 0;
		i++;
	}
	return (ret);
}
