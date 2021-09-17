/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:24:50 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/08 15:33:42 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	ft_which_quote(char *str, int squote, int dquote, int bquote)
{
	int	i;

	i = ft_check_start(str);
	while (str[i])
	{
		if (str[i] == DQUOTE && str[i - 1] != '\\')
			dquote++;
		if (str[i] == SQU0TE && str[i - 1] != '\\')
			squote++;
		if (str[i] == BQUOTE && str[i - 1] != '\\')
			bquote++;
		i++;
	}
	if (dquote % 2 != 0)
		return (2);
	if (squote % 2 != 0)
		return (1);
	if (bquote % 2 != 0)
		return (3);
	return (0);
}
