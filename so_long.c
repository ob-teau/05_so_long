/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:12:48 by acoinus           #+#    #+#             */
/*   Updated: 2021/12/02 13:34:19 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_and_check(t_info *f)
{
	if (ft_line_nb(f) == FAIL)
		return (FAIL);
	if (f->char_nb > 0)
		if (ft_map_filler(f) == FAIL)
			return (FAIL);
	if (f->char_nb <= 0)
	{
		ft_error(f, 4);
		return (FAIL);
	}
	return (SUCCESS);
}

int	check_open(t_info *f)
{
	f->fd = open(f->s_ber, O_DIRECTORY);
	if (f->fd > 0)
	{
		ft_error(f, 2);
		return (FAIL);
	}
	f->fd = open(f->s_ber, O_RDONLY);
	if (f->fd < 0)
	{
		ft_error(f, 3);
		return (FAIL);
	}
	if (f->fd > 0)
		if (read_and_check(f) == FAIL)
			return (FAIL);
	close(f->fd);
	return (SUCCESS);
}

int	check_ber(char *s, char *ber)
{
	int	ber_len;
	int	s_len;

	ber_len = 4;
	s_len = 0;
	if (!s)
		return (FAIL);
	while (s[s_len])
		s_len++;
	while (ber_len >= 0)
	{
		if (s[s_len] == ber[ber_len])
		{
			s_len--;
			ber_len--;
		}
		else
			break ;
	}
	if (ber_len == -1 && (s[s_len] && s[s_len] != '.' && s[s_len] != '/'))
		return (SUCCESS);
	return (FAIL);
}

int	so_long(t_info *f)
{
	if (check_ber(f->s_ber, ".ber") == FAIL)
	{
		ft_error(f, 1);
		return (FAIL);
	}
	if (check_open(f) == FAIL)
		return (FAIL);
	if (map_checker(f) == FAIL)
	{
		ft_error(f, 4);
		return (FAIL);
	}
	if (ft_graphical(f) == FAIL)
	{
		return (FAIL);
	}
	return (SUCCESS);
}
