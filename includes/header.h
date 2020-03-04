/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:54:03 by fyuko             #+#    #+#             */
/*   Updated: 2019/11/28 18:54:04 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define HEIGHT	1000
# define WIDTH 1000
# define BUFF_SIZE 9
# include "mlx.h"
# include "math.h"
# include <fcntl.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include "color.h"
# include "keys.h"

typedef struct		s_file
{
	int				fd;
	char			*str;
	int				len;
	int				res;
}					t_file;

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				x0;
	int				y0;
	int				z0;
	int				col;
	int				num_col;
	struct s_point	*top;
	struct s_point	*left;
	struct s_point	*next;
}					t_point;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				size_x;
	int				size_y;
	int				*pix_m;
	t_point			*map;
	int				pix_m_size;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				color1;
	int				color2;
	float			g;
	float			dx;
	float			dy;
	float			dz;
	int				*z_max;
	int				*z_min;
}					t_mlx;

typedef struct		s_line
{
	float			x0;
	float			y0;
	float			x;
	float			y;
	float			z;
	float			z0;
	int				i;
	int				error;
	int				delt;
	int				dir_x;
	int				dir_y;
}					t_line;

typedef	struct		s_strm
{
	char			*s;
	struct s_strm	*next;
}					t_strm;

void				create_mlx_img(t_mlx *ptr);
void				ft_null(t_mlx *ptr);
int					get_next_line(const int fd, char **line);
int					create_image(t_mlx *ptr);
int					check_ch(char *av);
t_strm				*create_el(char *av);
int					*create_array(char *av, int size);
int					key_press(int keycode, void *param);
void				paint_lines(t_mlx pr, t_point *t1, t_point *t2);
void				read_map(t_mlx	*ptr, t_file *file,
	t_strm **head_s, t_strm **tmp);
void				create_map(t_mlx *ptr, t_strm **head_s, t_strm **tmp);
void				iso_one(t_point *tmp);
void				lst_iso(t_mlx *ptr);
void				lst_map_p(t_mlx *ptr);
void				draw_line(t_mlx pr, t_point *t1, t_point *t2);
void				line_y(t_mlx pr, t_line ptr);
void				line_x(t_mlx pr, t_line ptr);
void				lst_x_sligt(t_mlx *ptr);
void				resize_map(t_mlx *ptr, int l);
int					col_min(t_mlx pr, float z);
t_point				*creat_el(int x, int y, int z, int col);
void				links_map(t_mlx *ptr);
void				hel_func2(int *r, int *g, int *b, int col);
int					c(t_mlx pr, int col, int i);
void				help_func(float *a, int *b);
t_point				*return_l(t_point *head, int i);

#endif
