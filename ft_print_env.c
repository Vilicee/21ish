/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:57:47 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/17 17:09:08 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/to_ish.h"

void	ft_print_env(int i, char **variables)
{
	int	len;

	len = ft_wordlength(variables[i], '=');
	len++;
	while (variables[i][len])
		write(1, &variables[i][len++], 1);
}
