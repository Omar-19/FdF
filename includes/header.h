#ifndef		HEADER_H
# define	HEADER_H
# define	HEIGHT		600
# define	WIDTH		800
# define	BUFF_SIZE	9
# include "mlx.h"
# include "math.h"
# include <fcntl.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct		s_file
{
	int				fd;
	char			*str;
	int				len;
	int				res;
}					t_file;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				x;
	int				x0;
	int				y;
	int				y0;
	int				z;
	int				z0;
	int				size_x;
	int				size_y;
	double			error;
	double			delt;
	int				dir_y;
	int				dir_x;
	int				*pix_m;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				**map_i;
}					t_mlx;

typedef	struct		s_strm
{
	char			*s;
	struct s_strm	*next;
	
}					t_strm;


void				ft_null(t_mlx *ptr);
int					get_next_line(const int fd, char **line);
int					ft_write_image(t_mlx *ptr);
int					check_ch(char *av, char c);
t_strm				*creat_el(char *av);
int					*create_array(char *av, int size);
void				paint_lines(t_mlx *ptr);
void				read_map(t_mlx	*ptr, t_file *file, t_strm **head_s, t_strm **tmp);
void				create_map(t_mlx	*ptr, t_file *file, t_strm **head_s, t_strm **tmp);
#endif