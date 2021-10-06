/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:16:38 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/06 15:45:20 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_almost_white_space(char c)
{
	if (c == '\t' || c == ' ' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

static int	ft_skip_flag(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '-')
	{
		i++;
		if (str[i] == '-')
		{
			i++;
			while (str[i] == 'n')
				i++;
			break ;
		}
	}
	return (i);
}

static int	ft_echo_len(char *str, int i, int flag, t_shell *data)
{
	int	len;
	int	arg;

	len = 0;
	arg = 0;
	if (flag == 1)
		i = ft_skip_flag(str);
	while (str[i])
	{
		if ((ft_almost_white_space(str[i]) == 1) && arg == 0)
			i++;
		else
		{
			if (data->e_i == 0)
				data->e_i = i;
			arg = 1;
			i++;
			len++;
		}
	}
	return (len);
}

static void	ft_echo_parser_loop(t_shell *dt, char *str, char c, char *temp)
{
	while (str[dt->e_i])
	{
		if (ft_almost_white_space(str[dt->e_i]) == 1)
		{
			dt->e_i++;
			if (temp[dt->index - 1] != ' ')
				temp[dt->index++] = ' ';
		}
		else if (ft_is_quote(str[dt->e_i]) == 1 && str[dt->e_i - 1] != '\\')
		{
			c = str[dt->e_i];
			temp[dt->index++] = str[dt->e_i++];
			while (str[dt->e_i])
			{
				if (str[dt->e_i] == c && str[dt->e_i - 1] != '\\')
					break ;
				else
					temp[dt->index++] = str[dt->e_i++];
			}
			temp[dt->index++] = str[dt->e_i++];
		}
		else
			temp[dt->index++] = str[dt->e_i++];
	}
	temp[dt->index] = '\0';
}

char	*ft_echo_parser(char *str, int i, int len, t_shell *data)
{
	char	*temp;

	len = ft_echo_len(str, i, data->flag, data);
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (temp)
		ft_echo_parser_loop(data, str, '\0', temp);
	data->e_i = 0;
	return (temp);
}