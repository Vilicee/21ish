/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:59:48 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/05 14:01:07 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	ft_initialize(t_shell *data)
{
	data->e_skip = 4;
	data->exec_fail = '0';
	data->quote = ' ';
	data->cd_p = '0';
	data->cd_l = '0';
	data->tilde = '0';
}

static void	ft_read_input(t_shell *data)
{
	if (data->buf)
		free(data->buf);
	if (!data->variables)
		data->buf = NULL;
	else
		data->buf = ft_save_input();
}

static void	ft_verify_quotation(t_shell *data)
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
	t_shell	data;

	ft_memset(&data, 0, sizeof(data));
	data.variables = ft_copy_env();
	ft_initialize(&data);
	while (1)
	{
		ft_putstr("minishell> ");
		signal(SIGINT, ft_ignore);
		ft_read_input(&data);
		if (data.buf != NULL)
		{
			ft_verify_quotation(&data);
			if (ft_check_buf(data.buf, 0, 0) == 0)
				ft_shell(&data);
		}
		else
			write(1, "\n", 1);
	}
	return (0);
}
