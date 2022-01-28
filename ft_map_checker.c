/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alice <acoinus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:26:01 by alice             #+#    #+#             */
/*   Updated: 2021/12/09 18:23:19 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(t_info *f)
{
	if ((f->x == 0 || f->x == f->char_nb - 1) && f->map[f->y][f->x] != '1')
	{
		f->err1++;
		return (FAIL);
	}
	return (SUCCESS);
}

int	map_checker_suite(t_info *f)
{
	while (++f->x < f->char_nb)
	{
		if (check_walls(f) == FAIL)
			return (FAIL);
		if (f->x > 0 && f->x < f->char_nb - 1)
		{
			if (ft_strchr(COMP, f->map[f->y][f->x], f) == FAIL)
				return (FAIL);
			if (f->save == 'C')
				f->c++;
			if (f->save == 'E')
				f->e++;
			if (f->save == 'P')
			{
				f->p++;
				f->pos_x = f->x;
				f->pos_y = f->y;
			}
			if (f->save == 'N')
				f->n++;
		}
	}
	return (SUCCESS);
}

int	map_checker(t_info *f)
{
	f->y = 0;
	f->x = 0;
	while (f->y == 0 && f->map[f->y][f->x] != '\0')
	{
		if (f->map[f->y][f->x] != '1')
		{
			f->err1++;
			return (FAIL);
		}
		f->x++;
	}
	while (++f->y < f->line_nb - 1)
	{
		f->x = -1;
		if (map_checker_suite(f) == FAIL)
			return (FAIL);
	}
	if (f->c < 1 || f->e < 1 || f->p != 1)
		return (FAIL);
	return (SUCCESS);
}
