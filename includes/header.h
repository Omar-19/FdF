#ifndef		HEADER_H

# define	HEADER_H
# define	HEIGHT			1000
# define	WIDTH			1000
# define	BUFF_SIZE		9
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

typedef struct 		s_point
{
	int x;
	int y;
	int z;
	int x0;
	int y0;
	int z0;
	int	col;
	struct 		s_point *top;
	struct 		s_point *left;
	struct 		s_point *next;
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
	int				pix_m_size; // длина массива пикселей
	int				bits_per_pixel; // ???
	int				size_line; // размер линии, связующей вершины
	int				endian; // ???
	int				color1;
	int				color2;
	float			g;
	float			dx;
	float			dy;
	float			dz;
	// int				zmxp;
	// int				zmxn;
	// int				zmn;
}					t_mlx;

typedef struct 		s_line
{
	float x0;
	float y0;
	float x;
	float y;
	float z;
	float z0;
	int i;
	int error;
	int delt;
	int dir_x;
	int dir_y;
}					t_line;

typedef	struct		s_strm
{
	char			*s;
	struct s_strm	*next;
	
}					t_strm;

void				writeMatrix(t_mlx ptr);
void				matrixConversion(t_mlx *ptr);
void				createGridСoordinates(t_mlx *ptr);
void				create_mlxImg(t_mlx *ptr);
void				ft_null(t_mlx *ptr);
int					get_next_line(const int fd, char **line);
int					createImage(t_mlx *ptr);
int					check_ch(char *av, char c);
t_strm				*create_el(char *av);
int					*create_array(char *av, int size);
int					key_press(int keycode, void *param);
void				drawHorizontalLines(t_mlx pr, t_line ptr);
void				drawVerticalLines(t_mlx pr, t_line ptr);
void				paint_lines(t_mlx pr, t_point *t1, t_point *t2);
void				readMap(t_mlx	*ptr, t_file *file, t_strm **head_s, t_strm **tmp);
void				createMap(t_mlx	*ptr, t_file *file, t_strm **head_s, t_strm **tmp);
void				drawGrid(t_mlx *ptr);
void				IndentSize(t_mlx *ptr);
void				iso_one(t_point *tmp);
void    			lst_iso(t_mlx *ptr);
void				lst_map_p(t_mlx *ptr);
void				draw_line(t_mlx pr, t_point *t1, t_point *t2);
void				line_y(t_mlx pr, t_line ptr);
void				line_x(t_mlx pr, t_line ptr);
void				lst_x_sligt(t_mlx *ptr);
// void	draw_line(int *pix, float x0, float y0, float x1, float y1);


#endif

// void	line_y(int *pix, float x0, float y0, float x1, float y1)
// {
// 	float tmp;

// 	tmp = fabsf(x1 - x0) / fabsf(y1 - y0);
// 	float er = 0;
// 	float opt;
// 	if (x0 > x1)
// 		opt = -1;
// 	else
// 		opt = 1;
// 	while (y0 <= y1)
// 	{
// 		if (y0 < HEIGHT && y0 >= 0 && x0 < WIDTH && x0 >= 0)
// 			pix[(int)y0 * WIDTH + (int)x0 + 1] = 0xFF;
// 		er += tmp;
// 		if (er >= 0.5)
// 		{
// 			x0 += opt;
// 			er -= 1;
// 		}
// 		(y0)++;
// 	}
// }

// void	line_x(int *pix, float x0, float y0, float x1, float y1)
// {
// 	float tmp;

// 	tmp = fabsf(y1 - y0) / fabsf(x1 - x0);
// 	float er = 0;
// 	float opt;
// 	if (y0 > y1)
// 		opt = -1;
// 	else
// 		opt = 1;
// 	while (x0 <= x1)
// 	{
// 		if (x0 < HEIGHT && x0 >= 0 && y0 < WIDTH && y0 >= 0)
// 			pix[(int)y0 * WIDTH + (int)x0 + 1] = 0xFF;
// 		er += tmp;
// 		if (er >= 0.5)
// 		{
// 			y0 += opt;
// 			er -= 1;
// 		}
// 		(x0)++;
// 	}
// }
