/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 18:33:16 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/17 17:09:33 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/to_ish.h"

void	ft_reset(t_to_ish *data)
{
	data->i = 0;
	while (data->words[data->i] != NULL)
		free(data->words[data->i++]);
	free(data->words);
	data->i = 0;
}
