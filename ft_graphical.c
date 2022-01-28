/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphical.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:43:01 by acoinus           #+#    #+#             */
/*   Updated: 2021/12/09 18:47:57 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_to_win(char c, t_info *f)
{
	if (c == '0')
		mlx_put_image_to_window(f->mlx_p, f->win_p, f->img_0, f->px, f->py);
	if (c == '1')
		mlx_put_image_to_window(f->mlx_p, f->win_p, f->img_1, f->px, f->py);
	if (c == 'C')
		mlx_put_image_to_window(f->mlx_p, f->win_p, f->img_c, f->px, f->py);
	if (c == 'E')
		mlx_put_image_to_window(f->mlx_p, f->win_p, f->img_e, f->px, f->py);
	if (c == 'P')
		mlx_put_image_to_window(f->mlx_p, f->win_p, f->img_p, f->px, f->py);
}

int	init_img(t_info *f, int width, int height)
{
	char	*path_0;
	char	*path_1;
	char	*path_c;
	char	*path_e;
	char	*path_p;

	path_0 = "./img/0.xpm";
	path_1 = "./img/1.xpm";
	path_c = "./img/C.xpm";
	path_e = "./img/E.xpm";
	path_p = "./img/P.xpm";
	f->img_0 = mlx_xpm_file_to_image(f->mlx_p, path_0, &width, &height);
	f->img_1 = mlx_xpm_file_to_image(f->mlx_p, path_1, &width, &height);
	f->img_c = mlx_xpm_file_to_image(f->mlx_p, path_c, &width, &height);
	f->img_e = mlx_xpm_file_to_image(f->mlx_p, path_e, &width, &height);
	f->img_p = mlx_xpm_file_to_image(f->mlx_p, path_p, &width, &height);
	if (f->img_0 == NULL || f->img_1 == NULL || f->img_c == NULL
		|| f->img_e == NULL || f->img_p == NULL)
	{
		ft_error(f, 6);
		return (FAIL);
	}
	return (SUCCESS);
}

int	ft_inwin(t_info *f)
{
	f->y = 0;
	f->py = 0;
	while (f->y < f->line_nb - 1)
	{
		f->x = 0;
		f->px = 0;
		while (f->x < f->char_nb)
		{
			img_to_win(f->map[f->y][f->x], f);
			f->px += 64;
			f->x++;
		}
		f->py += 64;
		f->y++;
	}
	return (SUCCESS);
}

int	graphical_init(t_info *f)
{
	f->mlx_p = mlx_init();
	if (f->mlx_p == NULL)
	{
		ft_error(f, 6);
		ft_close(f);
	}
	if (init_img(f, (int)W, (int)H) == FAIL)
	{
		ft_error(f, 6);
		ft_close(f);
	}
	f->win_p = mlx_new_window(f->mlx_p, (64 * f->char_nb),
			(64 * (f->line_nb - 1)), "so_long");
	if (f->win_p == NULL)
	{
		ft_error(f, 6);
		ft_close(f);
	}
	return (SUCCESS);
}

int	ft_graphical(t_info *f)
{
	if (graphical_init(f) == FAIL)
		return (FAIL);
	if (ft_inwin(f) == FAIL)
		return (FAIL);
	if (ft_key(f) == FAIL)
		return (FAIL);
	mlx_loop(f->mlx_p);
	return (SUCCESS);
}
