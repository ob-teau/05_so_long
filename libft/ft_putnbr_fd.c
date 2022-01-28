/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <acoinus@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 22:09:20 by user42            #+#    #+#             */
/*   Updated: 2021/06/24 15:42:44 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	a;

	a = n;
	if (n < 0)
	{
		a = (a * -1);
		ft_putchar_fd('-', fd);
	}
	if (a >= 0 && a <= 9)
		ft_putchar_fd(a + 48, fd);
	if (a > 9)
	{
		ft_putnbr_fd(a / 10, fd);
		ft_putchar_fd(a % 10 + 48, fd);
	}
}
