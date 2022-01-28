/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:00:59 by acoinus           #+#    #+#             */
/*   Updated: 2021/12/09 18:49:29 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy_img(t_info *f)
{
	if (f->img_0)
		mlx_destroy_image(f->mlx_p, f->img_0);
	if (f->img_1)
		mlx_destroy_image(f->mlx_p, f->img_1);
	if (f->img_e)
		mlx_destroy_image(f->mlx_p, f->img_e);
	if (f->img_c)
		mlx_destroy_image(f->mlx_p, f->img_c);
	if (f->img_p)
		mlx_destroy_image(f->mlx_p, f->img_p);
}

int	ft_close(t_info *f)
{
	if (f->mlx_p)
	{
		ft_destroy_img(f);
		if (f->win_p)
			mlx_destroy_window(f->mlx_p, f->win_p);
		mlx_destroy_display(f->mlx_p);
		free(f->mlx_p);
	}
	if (f)
		ft_free_map(f);
	printf(RESET"\n");
	exit (0);
	return (FAIL);
}
