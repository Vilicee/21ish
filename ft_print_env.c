/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:57:47 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/05 13:55:47 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_print_env(int i, char **variables)
{
	int	len;

	len = ft_wordlength(variables[i], '=');
	len++;
	while (variables[i][len])
		write(1, &variables[i][len++], 1);
}
