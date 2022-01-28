/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:57:44 by acoinus           #+#    #+#             */
/*   Updated: 2021/12/09 16:09:33 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "minilibx_linux/mlx.h"

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define GREY "\033[1;37m"
# define RESET "\033[0m"
# define COMP "10CEP"
# define SUCCESS 1
# define FAIL 0

/*
********************************** LIBFT ***********************************
*/
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(char *s);
int		ft_strlen(char *s);
int		ft_strchr(char *s, char c, t_info *f);

/*
*********************************** GNL ************************************
*/
int		get_next_line(char **line, t_info *f);
char	*ft_saver(char *str);
char	*ft_strcut(char *str);
int		ft_check_n(char *str);
void	gnl_suite(char **line, char **str, t_info *f);
int		ft_strn(char *s);
char	*ft_strjoin(char *s1, char *s2);

/*
 ******************************* SO_LONG MAIN FT *****************************
 */

int		main(int argc, char *argv[]);
int		so_long(t_info *f);
void	ft_free_map(t_info *f);
int		ft_map_filler(t_info *f);
int		ft_line_nb(t_info *f);

/*
 ********************************** CHECK FT *********************************
 */

int		check_ber(char *s, char *ber);
int		check_open(t_info *f);
int		read_and_check(t_info *f);
int		map_checker(t_info *f);
int		ft_check_c(char *s, char c);

/*
 ********************************* GRAPHICAL *********************************
 */

int		ft_graphical(t_info *f);
int		ft_inwin(t_info *f);
int		init_img(t_info *f, int width, int height);
void	img_to_win(char c, t_info *f);
int		graphical_init(t_info *f);
int		ft_key(t_info *f);
int		deal_key(int key, t_info *f);
int		ft_close(t_info *f);
int		ft_play(t_info *f, int to_x, int to_y);
//int		deal_mouse(int mouse, t_mlx *m);

/*
 *********************************** ERRORS **********************************
 */

void	ft_error(t_info *f, int er_type);

#endif
