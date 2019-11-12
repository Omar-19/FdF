#ifndef		HEADER_H
# define	HEADER_H
# define	HEIGHT		600
# define	WIDTH		800
# define	BUFF_SIZE	9
# include "mlx.h"
# include "math.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct		s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		x;
	int		y;
	int		z;
	int		size_x;
	int		size_y;
	int		*pix_m;
}					t_mlx;

int					get_next_line(const int fd, char **line);
#endif