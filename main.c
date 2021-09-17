/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:59:48 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/17 17:00:15 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/to_ish.h"

static void	ft_initialize(t_to_ish *data)
{
	data->buf = NULL;
	data->temp = NULL;
	data->new_word = NULL;
	data->words = NULL;
	data->old = NULL;
	data->new = NULL;
	data->check = NULL;
	data->env = NULL;
	data->cd_temp = NULL;
	data->cd_array = NULL;
	data->i = 0;
	data->ii = 0;
	data->ret = 0;
	data->index = 0;
	data->a_index = 0;
	data->flag = 0;
	data->e_i = 0;
	data->e_skip = 4;
	data->exec_fail = '0';
	data->quote = ' ';
	data->cd_p = '0';
	data->cd_l = '0';
	data->link_flag = 0;
	data->cd_path = NULL;
	data->array = NULL;
}

static void	ft_reset(t_to_ish *data)
{
	data->temp = NULL;
	data->new_word = NULL;
	data->old = NULL;
	data->new = NULL;
	data->words = NULL;
	data->check = NULL;
	data->env = NULL;
	data->cd_path = NULL;
	data->array = NULL;
	data->cd_temp = NULL;
	data->cd_array = NULL;
	data->flag = 0;
	data->e_i = 0;
	data->ii = 0;
	data->index = 0;
	data->a_index = 0;
	data->exec_fail = '0';
	data->e_skip = 4;
	data->ret = 0;
	data->cd_p = '0';
	data->cd_l = '0';
	data->quote = ' ';
}

static void	ft_parse_input(t_to_ish *data)
{
	if (data->buf)
		free(data->buf);
	if (!data->variables)
		data->buf = NULL;
	else
		data->buf = ft_save_input();
}

static void	ft_check_input(t_to_ish *data)
{
	char	*temp;

	if (ft_check_quotation(data->buf, 0, 0, 'a') == -1)
	{
		temp = ft_strdup(data->buf);
		if (temp)
		{
			free(data->buf);
			temp = ft_read_until_matching_quote(temp);
			data->buf = ft_strdup(temp);
			if (temp)
				free(temp);
		}
		else
			exit (-1);
		if (!data->buf)
			exit (-1);
	}
}

int	main(void)
{
	t_to_ish	data;

	data.variables = ft_copy_env();
	ft_initialize(&data);
	while (1)
	{
		ft_putstr("21ish> ");
		signal(SIGINT, ft_ignore);
		ft_parse_input(&data);
		if (data.buf != NULL)
		{
			ft_check_input(&data);
			if (ft_check_buf(data.buf, 0, 0) == 0)
				ft_shell(&data);
		}
		else
			write(1, "\n", 1);
	}
	return (0);
}