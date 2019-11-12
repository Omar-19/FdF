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
	int				y;
	int				z;
	int				size_x;
	int				size_y;
	int				*pix_m;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_mlx;

typedef	struct		s_strm
{
	char			*s;
	struct s_strm	*next;
	
}					t_strm;


void				ft_null(t_mlx *ptr);
int					get_next_line(const int fd, char **line);
int					ft_write_image(t_mlx *ptr, char **av);
#endif