/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphical2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:35:18 by acoinus           #+#    #+#             */
/*   Updated: 2021/12/09 18:48:40 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_play_suite(t_info *f, int to_y, int to_x)
{
	if (f->map[f->pos_y][f->pos_x] == 'E')
	{
		mlx_put_image_to_window(f->mlx_p, f->win_p,
			f->img_e, f->pos_x * 64, f->pos_y * 64);
		f->pos_y = to_y;
		f->pos_x = to_x;
		return ;
	}
	mlx_put_image_to_window(f->mlx_p, f->win_p,
		f->img_0, f->pos_x * 64, f->pos_y * 64);
	f->map[f->pos_y][f->pos_x] = '0';
	f->pos_y = to_y;
	f->pos_x = to_x;
	return ;
}

int	ft_play(t_info *f, int to_y, int to_x)
{
	f->py = to_y * 64;
	f->px = to_x * 64;
	if (f->map[to_y][to_x] == '1')
		return (FAIL);
	f->i++;
	ft_putnbr_fd(f->i, 1);
	write(1, "\r", 1);
	if (f->map[to_y][to_x] == 'E')
		if (f->c == 0)
			ft_close(f);
	mlx_put_image_to_window(f->mlx_p, f->win_p, f->img_p, f->px, f->py);
	if (f->map[to_y][to_x] == 'C')
		f->c--;
	else if (f->map[f->pos_y][f->pos_x] == 'E')
	{
		mlx_put_image_to_window(f->mlx_p, f->win_p, f->img_e,
			f->pos_x * 64, f->pos_y * 64);
		f->pos_y = to_y;
		f->pos_x = to_x;
		return (SUCCESS);
	}
	ft_play_suite(f, to_y, to_x);
	return (SUCCESS);
}

int	deal_key(int key, t_info *f)
{
	if (key == 119)
		ft_play(f, (f->pos_y - 1), f->pos_x);
	if (key == 97)
		ft_play(f, f->pos_y, (f->pos_x - 1));
	if (key == 115)
		ft_play(f, (f->pos_y + 1), f->pos_x);
	if (key == 100)
		ft_play(f, f->pos_y, f->pos_x + 1);
	if (key == 65307)
	{
		ft_close(f);
		return (SUCCESS);
	}
	return (FAIL);
}

int	ft_key(t_info *f)
{
	f->i = 0;
	printf(GREEN"Compteur de deplacement : \n");
	mlx_key_hook(f->win_p, deal_key, f);
	mlx_hook(f->win_p, 17, 1L << 17, ft_close, f);
	return (SUCCESS);
}
