/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dhexadecimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:54:20 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/05 14:37:17 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	ft_dhexadecimal(t_dprintf *data, unsigned long long n)
{
	char				*base;
	int					res;
	unsigned long long	base_n;

	base_n = data->base;
	if (data->x == 1)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= base_n)
		ft_dhexadecimal(data, n / base_n);
	res = n % base_n;
	data->ret++;
	write(data->fd, &base[res], 1);
}
