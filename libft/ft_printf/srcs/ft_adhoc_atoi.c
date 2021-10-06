/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adhoc_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:39:36 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/05 14:46:05 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_adhoc_atoi(const char *str, t_data *data)
{
	int	res;

	res = 0;
	while (str[data->i] >= 48 && str[data->i] <= 57)
	{
		res = (res * 10) + str[data->i] - 48;
		data->i++;
		data->waste++;
	}
	return (res);
}
