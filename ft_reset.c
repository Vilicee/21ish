/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 18:33:16 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/05 13:56:27 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_reset(t_shell *data)
{
	data->i = 0;
	while (data->words[data->i] != NULL)
		free(data->words[data->i++]);
	free(data->words);
	data->i = 0;
}
