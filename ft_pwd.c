/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:04:51 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/15 14:18:45 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_pwd(char *str, char **variables)
{
	int	ret;

	ret = ft_search_env("PWD", 0, variables);
	if (ret != -1)
		ft_print_env(ret, variables);
	write(1, "\n", 1);
}
