/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:47:54 by acoinus           #+#    #+#             */
/*   Updated: 2021/12/09 18:40:38 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

# define BUFFER_SIZE 1024
# define W 64
# define H 64

typedef struct s_info
{
	int		line_nb;
	int		char_nb;
	int		fd;
	int		r;
	int		x;
	int		px;
	int		y;
	int		py;
	int		err1;
	int		i;
	int		e;
	int		c;
	int		p;
	int		n;
	int		pos_x;
	int		pos_y;
	char	save;
	char	*s_ber;
	char	**map;
	void	*mlx_p;
	void	*win_p;
	void	*img_0;
	void	*img_1;
	void	*img_c;
	void	*img_e;
	void	*img_p;
}			t_info;

/******************************* LIBFT ******************************* */

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_strchr(char *s, char c, t_info *f);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
void	ft_putnbr_fd(int n, int fd);

/******************************* GNL *********************************/

int		get_next_line(char **line, t_info *f);
void	gnl_suite(char **line, char **str, t_info *f);
char	*ft_saver(char *str);
char	*ft_strcut(char *str);
int		ft_check_n(char *str);
int		ft_strn(char *s);

#endif
