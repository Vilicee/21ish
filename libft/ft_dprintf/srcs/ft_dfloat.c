/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dfloat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 11:52:46 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/05 14:35:07 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static void	ft_pre_handlers(t_dprintf *data)
{
	if (data->just_dot == 1 && data->hash == 1)
	{
		write(data->fd, ".", 1);
		data->ret++;
	}
	if (data->save_dot == 1 && data->str_len == 0 && data->hash == 1)
	{
		write(data->fd, ".", 1);
		data->ret++;
	}
	if (data->precision > 0)
	{
		write(data->fd, ".", 1);
		data->ret++;
	}
}

static void	ft_print_float(t_dprintf *data)
{
	if (data->minus == 0)
		ft_dformat_float(data);
	if (data->minus == 1 && data->neg == 1)
	{
		write(data->fd, "-", 1);
		data->ret++;
		data->neg = 0;
		if (data->xtra > 0)
			data->xtra--;
	}
	ft_put_uns_ll_fd(data->int_part, data->fd);
	data->ret = data->ret + ft_uns_longlong_len(data->int_part);
	ft_pre_handlers(data);
	write(data->fd, data->deci, data->precision);
	data->ret = data->ret + data->precision;
	ft_memdel((void *)&data->deci);
	if (data->minus == 1)
		ft_dformat_float(data);
}

static void	ft_save_float(t_dprintf *data)
{
	if (data->cap_l == 1)
		data->f_n = va_arg(data->copy, long double);
	else if (data->cap_l == 0)
		data->f_n = va_arg(data->copy, double);
	if (data->f_n < 0)
	{
		data->f_n = data->f_n * -1;
		data->neg = 1;
	}
	if (1 / data->f_n < 0)
		data->neg = 1;
	if (data->save_dot == 1)
		data->precision = data->str_len;
	else if (data->just_dot == 1)
		data->precision = 0;
	else
		data->precision = 6;
}

static void	ft_convert_to_int(t_dprintf *data)
{
	int	precision;

	precision = data->precision;
	if (data->precision < 22)
		precision = 22;
	data->deci = (char *)malloc(sizeof(char) * (precision + 1));
	data->int_part = (unsigned long)data->f_n;
	data->f_n = data->f_n - (unsigned long)data->f_n;
	while (precision > data->count)
	{
		data->deci[data->count] = (unsigned long)(data->f_n * 10) % 10 + 48;
		data->f_n = data->f_n * 10;
		data->f_n = data->f_n - (unsigned long)data->f_n;
		data->count++;
	}
	data->deci[data->count] = '\0';
	ft_drounding(data);
	if (data->roundup == '1')
		data->int_part = data->int_part + 1;
	data->len = ft_uns_longlong_len(data->int_part);
	if (data->precision == 0)
		data->len = data->len;
	else
		data->len = data->len + data->precision + 1;
}

void	ft_dfloat(t_dprintf *data)
{
	ft_dreset_n(data);
	ft_save_float(data);
	data->f = 1;
	ft_convert_to_int(data);
	data->inf = ft_isinf(data->f_n);
	data->nan = ft_isnan(data->f_n);
	ft_dhandle_float_flags(data);
	if (data->inf == 1 || data->nan == 1)
	{
		ft_dhandle_nan_inf(data);
		return ;
	}
	ft_print_float(data);
	data->waste++;
	ft_dreset_n(data);
}
