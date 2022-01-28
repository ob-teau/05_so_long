/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:04:34 by acoinus           #+#    #+#             */
/*   Updated: 2021/12/09 18:51:20 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_n(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strcut(char *str)
{
	char	*cut_to_n;
	int		i;

	cut_to_n = malloc(sizeof(char) * (ft_strn(str) + 1));
	if (cut_to_n == NULL)
		return (NULL);
	i = 0;
	if (str)
	{
		while (str[i] && str[i] != '\n')
		{
			cut_to_n[i] = str[i];
			i++;
		}
	}
	cut_to_n[i] = '\0';
	return (cut_to_n);
}

char	*ft_saver(char *str)
{
	int	i;
	int	j;

	if (!str)
		return (NULL);
	i = ft_strn(str);
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	if (str && str[i])
		i++;
	j = 0;
	while (str && str[i])
	{
		str[j] = str[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

void	gnl_suite(char **line, char **str, t_info *f)
{
	int	save;

	save = 0;
	*line = ft_strcut(str[f->fd]);
	if (f->char_nb == 0)
		f->char_nb = ft_strlen(*line);
	if (f->char_nb > 0 && f->r == 1)
	{
		save = ft_strlen(*line);
		if (f->char_nb != save)
			f->char_nb = -1;
	}
	str[f->fd] = ft_saver(str[f->fd]);
	return ;
}

int	get_next_line(char **line, t_info *f)
{
	static char	*str[1024];
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;

	if (f->fd < 0 || BUFFER_SIZE <= 0 || !line || read(f->fd, buf, 0) < 0)
		return (-1);
	f->r = 1;
	if (ft_check_n(str[f->fd]) == 0)
		f->r = read(f->fd, buf, BUFFER_SIZE);
	while (ft_check_n(str[f->fd]) == 0 && f->r != 0)
	{
		if (f->r == -1)
			return (-1);
		buf[f->r] = '\0';
		tmp = str[f->fd];
		str[f->fd] = ft_strjoin(tmp, buf);
		free(tmp);
		if (ft_check_n(str[f->fd]) == 0)
			f->r = read(f->fd, buf, BUFFER_SIZE);
	}
	gnl_suite(line, str, f);
	if (f->r == 0)
		return (0);
	return (1);
}
