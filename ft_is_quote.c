/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:44:34 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/05 13:54:37 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_is_quote(char c)
{
	if (c)
	{
		if (c == DQUOTE || c == BQUOTE || c == SQU0TE)
			return (1);
	}
	return (0);
}
