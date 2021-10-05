/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:40:54 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/05 16:27:10 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/to_ish.h"

static void	ft_reset_variables(t_to_ish *data)
{
	data->quote = ' ';
	data->exec_fail = '0';
	data->a_index = 0;
	data->cd_p = '0';
	data->cd_l = '0';
	data->ii = 0;
	data->index = 0;
	data->e_skip = 4;
	data->ret = 0;
	data->env = NULL;
	data->cd_path = NULL;
	data->array = NULL;
	data->temp = NULL;
	data->check = NULL;
	data->new_word = NULL;
	data->old = NULL;
	data->new = NULL;
	data->cd_array = NULL;
	data->cd_temp = NULL;
}

/*
** 
**
*/

static int	ft_check_for_errors(char *buf)
{
	int		i;
	char	c;

	i = 0;
	if (!buf)
		exit (-1);
	while (buf[i] != '\0')
	{
		if (ft_is_quote(buf[i]) == 1)
		{
			c = buf[i++];
			while (buf[i] != '\0' && buf[i] != c)
				i++;
		}
		if (buf[i] == ';' && buf[i + 1] == ';')
		{
			ft_putstr("21ish: parse error near `;;'\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

static char	**ft_parser(t_to_ish *data)
{
	char	**ret;
	char	*temp;
	int		check;

	check = ft_check_semic(data->buf, 0, 0);
	if (check == -1)
		return (NULL);
	temp = ft_strtrim(data->buf);
	if (!temp)
		return (NULL);
	if (check == 1)
		ret = ft_strsplit(temp, ';');
	else if (check == 0)
		ret = ft_strsplit(temp, '\0');
	else
		ret = NULL;
	free(temp);
	return (ret);
}

static int	ft_not_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

/*
**
** Called from: main
**
**
**
**
**
*/

int	ft_shell(t_to_ish *data)
{
	if (ft_check_for_errors(data->buf) == -1)
		return (-1);
	data->words = ft_parser(data);
	if (data->words)
	{
		while (data->words[data->i] != NULL)
		{
			if (ft_not_empty(data->words[data->i]) == 0)
			{
				ft_which_command(data->words[data->i], data, NULL, NULL);
				ft_reset_variables(data);
			}
			data->i++;
		}
	}
	if (data->words)
		ft_free_array(data->words);
	data->i = 0;
	return (-1);
}
