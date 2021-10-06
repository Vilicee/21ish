/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dspecifiers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:42:18 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/05 14:44:06 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_dspecifiers(const char *format, t_dprintf *data)
{
	if (format[data->i] == 'c')
		return (0);
	if (format[data->i] == 's')
		return (0);
	if (format[data->i] == 'p')
		return (0);
	if (format[data->i] == 'd')
		return (0);
	if (format[data->i] == 'i')
		return (0);
	if (format[data->i] == 'o')
		return (0);
	if (format[data->i] == 'u')
		return (0);
	if (format[data->i] == 'x')
		return (0);
	if (format[data->i] == 'X')
		return (0);
	if (format[data->i] == 'f')
		return (0);
	if (format[data->i] == '%')
		return (0);
	return (-1);
}
