/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:55:12 by acoinus           #+#    #+#             */
/*   Updated: 2021/12/09 16:07:09 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(t_info *f)
{
	int	i;

	i = -1;
	free(f->s_ber);
	if (f->map)
	{
		while (f->map[++i] && i < f->line_nb - 1)
			if (f->map[i])
				free(f->map[i]);
		if (f->map[i])
			free(f->map[i]);
		free(f->map);
	}
	return ;
}

int	main(int argc, char *argv[])
{
	t_info	f;

	if (argc < 2)
	{
		ft_putstr_fd("Error\n./Too few arguments.\n", 2);
		return (FAIL);
	}
	f = (t_info){0};
	f.s_ber = ft_strdup(argv[1]);
	if (so_long(&f) == FAIL)
	{
		ft_free_map(&f);
		return (FAIL);
	}
	ft_free_map(&f);
	printf("main SUCCESS\n");
	return (SUCCESS);
}
