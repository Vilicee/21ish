/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 14:21:15 by wvaara            #+#    #+#             */
/*   Updated: 2021/05/17 12:38:49 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isupper(char c)
{
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}