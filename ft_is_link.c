/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:20:45 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/05 13:54:28 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*ft_is_link(t_shell *data, char **array, char tilde)
{
	char	current[4096];

	if (data->cd_p == '1')
	{
		getcwd(current, sizeof(current));
		return (ft_strjoin("setenv PWD ", current));
	}
	else
	{
		data->link_flag = 2;
		if (tilde == '1')
			return (ft_strjoin("setenv PWD ", data->check));
		else if (array[1][0] == '/')
			return (ft_strjoin("setenv PWD ", array[1]));
		else
			return (ft_strjoin("setenv PWD ", data->check));
	}
	return (ft_strdup(""));
}
