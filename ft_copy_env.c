/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:32:25 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/05 13:44:12 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	**ft_copy_env(void)
{
	extern char	**environ;
	char		**copy;
	int			i;
	int			len;

	i = 0;
	len = ft_arrlen(environ);
	copy = (char **)malloc(sizeof(char *) * (len + 1));
	if (copy)
	{
		while (environ[i])
		{
			if (ft_strnequ(environ[i], "SHELL", 5) == 1)
				copy[i] = ft_strdup("SHELL=21sh");
			else
				copy[i] = ft_strdup(environ[i]);
			i++;
		}
		copy[i] = NULL;
	}
	return (copy);
}
