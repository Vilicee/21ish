/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 12:04:32 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/05 13:43:29 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_check_start(char *str)
{
	if (str[0] == '\\' && (ft_is_quote(str[1]) == 1))
		return (2);
	return (0);
}
