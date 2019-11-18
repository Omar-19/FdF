# include "../includes/header.h"

void	ft_null(t_mlx *ptr)
{
	ptr->x = 0;
	ptr->y = 0;
	ptr->x = 0;
	ptr->x0 = 0;
	ptr->y0 = 0;
	ptr->z0 = 0;
	ptr->delt = 0;
	ptr->dir_x = 0;
	ptr->dir_y = 0;
	ptr->size_x = 0;
	ptr->size_y = 0;
	ptr->bits_per_pixel = 0;
	ptr->size_line = 40;
	ptr->endian = 0;
	ptr->mlx_ptr = NULL;
	ptr->win_ptr = NULL;
	ptr->img_ptr = NULL;
	ptr->pix_m = NULL;
	ptr->color = PEACHPUFF;
}

int		main(int argc, char **argv)
{
	t_mlx	ptr;
	t_file	file;
	t_strm	*head_s;
	t_strm	*tmp;

	ft_null(&ptr);
	if (argc != 2)
		return (0);
	file.fd = open(argv[1], O_RDONLY);
	readMap(&ptr, &file, &head_s, &tmp);
	createMap(&ptr, &file, &head_s, &tmp);
	for (int i = 0; i < ptr.size_y; i++)
	{
		for (int j = 0; j < ptr.size_x; j++)
		{
			(ptr.map_i[i][j] >= 0) ? (printf(" ")) : 0;
			printf("%d ", ptr.map_i[i][j]);
		}
		printf("\n");
	}
	createImage(&ptr);
	return (0);
}
