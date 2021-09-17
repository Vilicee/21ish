/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dollar_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 12:53:13 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/17 17:02:56 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/to_ish.h"

int	ft_dollar_check(char *str, int i, char quote)
{
	if (str[i] == '$')
	{
		if (quote != 'a')
		{
			if (str[i + 1] == quote)
				return (0);
		}
		if ((ft_isspace(str[i + 1]) == 0) && str[i + 1] != '\0')
			return (1);
		else
			return (0);
	}
	return (0);
}
