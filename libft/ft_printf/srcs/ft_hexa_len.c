/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 11:55:14 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/05 14:47:18 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_len(t_data *data, unsigned long long n)
{
	int					count;
	unsigned long long	base;

	count = 0;
	base = data->base;
	while (n >= base)
	{
		n = n / base;
		count++;
	}
	count++;
	return (count);
}
