/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alice <acoinus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:54:54 by alice             #+#    #+#             */
/*   Updated: 2021/12/01 13:52:49 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr(char *s, char c, t_info *f)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == c)
		{
			f->save = c;
			return (1);
		}
		i++;
	}
	return (0);
}
