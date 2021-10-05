/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:59:48 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/05 11:38:31 by ehelmine         ###   ########.fr       */
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

/*
** Called from: main
** We check if data->buf is pointing somewhere, if yes, then free
** CHANGE maybe we should put it to point to null (ft_memdel?)
** We check if data->variables exist (CHANGE data->variables could be named
** env_variables?) and if they are not, we set data->buf NULL
** If data->variables exist, we get content to data->buf from ft_save_input.
*/

static void	ft_parse_input(t_to_ish *data)
{
	if (data->buf)
		free(data->buf);
	if (!data->variables)
		data->buf = NULL;
	else
		data->buf = ft_save_input();
}

/*
** Called from: main
** We have our input and we check if we have matching number of quotes 
** in ft_check_quotation. 
**	If it returns -1: there is not matching number,
** 		so we strdup our input to temp, we free data->buf, we go read until
** 		we get matching quote and new input is in temp now. We duplicate it to
** 		data->buf again, and then we free temp (CHANGE all frees -> memdel?)
** 		if stdup in the beginning didn't happen, we exit -1. If after checking
** 		for the matching quote we didn't get anything to data->buf (or malloc
** 		failed) we exit -1 too.
** If it returns 1: we just go back to main
*/

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

/*
** 1. First we get environment variables in ft_copy_env
** 2. We initialize our t_to_ish data struct variables in ft_initialize
** 3. Enter while loop CHANGE (putstr -> write call) and write to output 21sh>
** 4. Check if we get SIGINT (ctrl+c), and if yes, we go to ft_ignore
** 5. We parse input in ft_parse_input (CHANGE could be ft_get_input or
** ft_read_input, we are not really parsing anything yet, just reading it in)
** 6. Check what we have in data.buf and if it is not null:
** 		6.1. We check input in ft_check_input (CHANGE some other name,
 		because now this function only checks for matching quotes and nothing
		else, so more detailed name would be good)
**		6.2. We check what ft_check_buf returns, and if return value is 0
**			6.2.1 We call ft_shell
** 7. If data.buf was null in 6., we do else-condition: write one newline 
** 8. We go back to 3. and go around again.
*/

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
			if (ft_check_buf(data.buf, 0) == 0)
				ft_shell(&data);
		}
		else
			write(1, "\n", 1);
	}
	return (0);
}
