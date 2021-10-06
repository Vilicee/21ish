/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 11:55:59 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/06 15:41:27 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char	*ft_read_input(int ret, char *buf, char *str)
{
	char	*temp;

	temp = NULL;
	while (ret)
	{
		if (!temp)
			temp = ft_strdup(buf);
		else
		{
			free(temp);
			temp = ft_strdup(str);
		}
		ret = read(0, buf, BUFF_SIZE);
		buf[ret] = '\0';
		if (str)
			free(str);
		str = ft_strjoin(temp, buf);
		if (buf[ret - 1] == '\n')
			break ;
	}
	if (temp)
		free(temp);
	return (str);
}

/*
** Called from: ft_parse_input (from main)
** BUFF_SIZE is set to 256 (maybe stupid QUESTION why?)
** We read to buf from standard input. If buf[0] == '\0' it means we didnt
** get anything (eof?) and we return NULL.
** We read BUFF_SIZE amount of input to char buf[]. We put terminating
** null character to buf[] and check if second to last character is
** newline or not. If yes, we ft_strdup the input (QUESTION why? we could
** just return char buf? or is it hard because it is char[] not char *)
** and return the string (CHANGE we could just return (ft_strdup(buf));
** and get rid of char *str).
** If the second last character is not newline, we read more input in
** ft_read_input (above) and return that.
*/

char	*ft_save_input(void)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*str;

	str = NULL;
	ret = read(0, buf, BUFF_SIZE);
	if (buf[0] == '\0')
		return (NULL);
	buf[ret] = '\0';
	if (buf[ret - 1] == '\n')
	{
		str = ft_strdup(buf);
		return (str);
	}
	return (ft_read_input(ret, buf, str));
}
