/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_nb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alice <acoinus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:39:58 by alice             #+#    #+#             */
/*   Updated: 2021/12/09 17:59:37 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_i(t_info *f, int i)
{
	if (i == -1)
	{
		ft_error(f, 3);
		return (FAIL);
	}
	return (SUCCESS);
}

int	ft_line_nb_suite(t_info *f)
{
	if (f->char_nb <= 0)
	{
		ft_error(f, 7);
		return (FAIL);
	}
	f->map = malloc(sizeof(char *) * (f->line_nb + 1));
	if (!f->map)
	{
		ft_error(f, 5);
		return (FAIL);
	}
	return (SUCCESS);
}

int	ft_line_nb(t_info *f)
{
	char	*line;
	int		i;

	i = get_next_line(&line, f);
	if (get_i(f, i) == FAIL)
		return (FAIL);
	if (i == 1)
		f->line_nb++;
	free(line);
	while (i == 1)
	{
		i = get_next_line(&line, f);
		if (get_i(f, i) == FAIL)
			return (FAIL);
		f->line_nb++;
		if (i == 0 && line[0] != '\0')
			f->line_nb++;
		free(line);
	}
	if (ft_line_nb_suite(f) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
