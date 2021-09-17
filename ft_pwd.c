/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:04:51 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/17 17:09:14 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/to_ish.h"

void	ft_pwd(char *str, char **variables)
{
	int	ret;

	ret = ft_search_env("PWD", 0, variables);
	if (ret != -1)
		ft_print_env(ret, variables);
	write(1, "\n", 1);
}
