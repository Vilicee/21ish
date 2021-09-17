/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_command_path.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 14:12:05 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/17 17:37:19 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/to_ish.h"

char	*ft_verify_rights(struct stat *buf, t_to_ish *data, char *com)
{
	if (buf->st_mode & S_IXUSR)
		return (ft_strdup(com));
	else
	{
		data->exec_fail = '1';
		return (ft_strdup(""));
	}
	return (NULL);
}

char	*ft_verify(char **array, struct stat *buf, char *path, t_to_ish *data)
{
	ft_free_array(array);
	if (buf->st_mode & S_IXUSR)
		return (path);
	else
	{
		data->exec_fail = '1';
		free(path);
		return (ft_strdup(""));
	}
	return (NULL);
}

char	*ft_extract_command_path(char **var, char *wrd, char *com, t_to_ish *dt)
{
	char		*path;
	char		**array;
	struct stat	buf;

	if (lstat(com, &buf) == 0)
		return (ft_verify_rights(&buf, dt, com));
	path = ft_extract_env_value(var, wrd);
	if (path)
	{
		array = ft_strsplit(path, ':');
		if (array)
		{
			while (array[dt->a_index])
			{
				if (path)
					free(path);
				path = ft_strcjoin(array[dt->a_index++], '/', com);
				if (lstat(path, &buf) == 0)
					return (ft_verify(array, &buf, path, dt));
			}
			ft_free_array(array);
		}
		free(path);
	}
	return (ft_strdup(""));
}
