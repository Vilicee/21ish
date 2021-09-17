/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:55:47 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/17 17:09:53 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/to_ish.h"

static int	ft_which_env(char *variable, char *word)
{
	char	**temp;
	int		ret;

	temp = ft_strsplit(variable, '=');
	ret = ft_strcmp(temp[0], word);
	ft_free_array(temp);
	return (ret);
}

int	ft_search_env(char *temp, int i, char **variables)
{
	int		ii;
	char	*word;

	ii = 0;
	word = ft_get_next_word(temp, i);
	while (word[ii])
	{
		word[ii] = ft_toupper(word[ii]);
		ii++;
	}
	ii = 0;
	while (variables[ii])
	{
		if (ft_which_env(variables[ii], word) == 0)
		{
			free(word);
			return (ii);
		}
		ii++;
	}
	free(word);
	return (-1);
}
