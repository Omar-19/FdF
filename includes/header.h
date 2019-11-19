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
	struct 		s_point *top;
	struct 		s_point *left;
}					t_point;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				size_x;
	int				size_y;
	int				*pix_m;
	t_point			**map;
	int				pix_m_size; // длина массива пикселей
	int				bits_per_pixel; // ???
	int				size_line; // размер линии, связующей вершины
	int				endian; // ???
}					t_mlx;

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
void				paint_lines(t_mlx ptr, int i);
void				drawHorizontalLines(t_mlx ptr);
void				drawVerticalLines(t_mlx ptr);
void				readMap(t_mlx	*ptr, t_file *file, t_strm **head_s, t_strm **tmp);
void				createMap(t_mlx	*ptr, t_file *file, t_strm **head_s, t_strm **tmp);
void				drawGrid(t_mlx *ptr);
void				IndentSize(t_mlx *ptr);

#endif