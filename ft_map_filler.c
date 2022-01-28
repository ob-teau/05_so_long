/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_filler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alice <acoinus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:02:21 by alice             #+#    #+#             */
/*   Updated: 2021/12/09 11:29:46 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_filler(t_info *f)
{
	char	*line;

	close(f->fd);
	f->fd = open(f->s_ber, O_RDONLY);
	while (f->y < f->line_nb)
	{
		get_next_line(&line, f);
		f->map[f->y] = ft_strdup(line);
		free(line);
		if (!f->map[f->y])
		{
			ft_error(f, 5);
			return (FAIL);
		}
		f->y++;
	}
	return (SUCCESS);
}
