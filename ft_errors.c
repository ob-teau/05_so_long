/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 15:12:49 by acoinus           #+#    #+#             */
/*   Updated: 2021/12/09 18:26:56 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_details(t_info *f)
{
	if (f->err1 > 0)
		ft_putstr_fd(", no surrounding walls", 2);
	if (f->c < 1)
		ft_putstr_fd(", no collectibles", 2);
	if (f->e < 1)
		ft_putstr_fd(", no exit", 2);
	if (f->p != 1)
		ft_putstr_fd(", map must have one player", 2);
}

void	ft_error(t_info *f, int er_type)
{
	if (er_type == 1)
		ft_putstr_fd("Error\n./wrong file path or extension [file.ber]\n", 2);
	if (er_type == 2)
		ft_putstr_fd("Error\n./file required, no directory [file.ber]\n", 2);
	if (er_type == 3)
		ft_putstr_fd("Error\n./error with file descriptor\n", 2);
	if (er_type == 4)
	{
		ft_putstr_fd("Error\n./error in map making", 2);
		ft_error_details(f);
		write(1, ".\n", 2);
	}
	if (er_type == 5)
		ft_putstr_fd("Error\n./malloc error\n", 2);
	if (er_type == 6)
		ft_putstr_fd("Error\n./error with mlx\n", 2);
	if (er_type == 7)
		ft_putstr_fd("Error\n./error in map making, no rectangular map\n", 2);
	close(f->fd);
}
