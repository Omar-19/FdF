# include "../includes/header.h"

void	IndentSize(t_mlx *ptr)
{
	ptr->indent_x = 0;
	ptr->indent_y = 0;
	// ptr->indent_x = (WIDTH - (ptr->size_x - 1) * ptr->size_line) / 2;
	// ptr->indent_y = (HEIGHT - (ptr->size_y - 1) * ptr->size_line) / 2;
}

void	ft_null(t_mlx *ptr)
{
	ptr->indent_x = 0;
	ptr->indent_y = 0;
	ptr->delt = 0;
	ptr->dir_x = 0;
	ptr->dir_y = 0;
	ptr->size_x = 0;
	ptr->size_y = 0;
	ptr->bits_per_pixel = 0;
	ptr->size_line = 30;
	ptr->endian = 0;
	ptr->mlx_ptr = NULL;
	ptr->win_ptr = NULL;
	ptr->img_ptr = NULL;
	ptr->pix_m = NULL;
	ptr->color = PEACHPUFF;
}

void	create_mlxImg(t_mlx *ptr)
{
	IndentSize(ptr);
	ptr->img_ptr = mlx_new_image (ptr->mlx_ptr,  WIDTH, HEIGHT);
	ptr->pix_m = (int *)mlx_get_data_addr(ptr->img_ptr,
		&(ptr->bits_per_pixel), &(ptr->pix_m_size), &(ptr->endian));
}

void	matrixConversion(t_mlx *ptr)
{
	// поворот на 30 градусов
	// ptr->x = (x - y) * cos(0.46373398);
	// ptr->y = -ptr->z + (x + y) * sin(0.46373398);
	ptr->j = 0;
	while(ptr->j < ptr->size_y)
	{
		ptr->i = 0;
		while(ptr->i < ptr->size_x)
		{
			// x = (x - y) * cos(0.46373398);
			// y = -ptr->z + (x + y) * sin(0.46373398);
			*(*(ptr->map_x + ptr->j) + ptr->i) = 
				(*(*(ptr->map_x + ptr->j) + ptr->i) - 
					*(*(ptr->map_y + ptr->j) + ptr->i)) * cos(1.0);
			//-(*(*(ptr->map_z + ptr->j) + ptr->i)
			*(*(ptr->map_y + ptr->j) + ptr->i) = (*(*(ptr->map_x + ptr->j) + ptr->i) + 
					*(*(ptr->map_y + ptr->j) + ptr->i)) * sin(1.0);
			++(ptr->i);
		}
		++(ptr->j);
	}
}

void	createGridСoordinates(t_mlx *ptr)
{
	IndentSize(ptr);
	ptr->j = 0;
	ptr->y0 = ptr->indent_y;
	while(ptr->j < ptr->size_y)
	{
		ptr->x0 = ptr->indent_x;
		ptr->i = 0;
		while(ptr->i < ptr->size_x)
		{
			// ptr->z = *(*(ptr->map_z + ptr->j) + ptr->i);
			*(*(ptr->map_x + ptr->j) + ptr->i) = ptr->x0;
			*(*(ptr->map_y + ptr->j) + ptr->i) = ptr->y0;
			ptr->x0 += ptr->size_line;
			++(ptr->i);
		}
		ptr->y0 += ptr->size_line;
		++(ptr->j);
	}
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
	createGridСoordinates(&ptr);

	printf("MATRIX X:\n");
	for (int i = 0; i < ptr.size_y; i++)
	{
		for (int j = 0; j < ptr.size_x; j++)
		{
			(ptr.map_x[i][j] >= 0) ? (printf(" ")) : 0;
			printf("%d ", ptr.map_x[i][j]);
		}
		printf("\n");
	}

	printf("MATRIX Y:\n");
	for (int i = 0; i < ptr.size_y; i++)
	{
		for (int j = 0; j < ptr.size_x; j++)
		{
			(ptr.map_y[i][j] >= 0) ? (printf(" ")) : 0;
			printf("%d ", ptr.map_y[i][j]);
		}
		printf("\n");
	}

	printf("MATRIX Z:\n");
	for (int i = 0; i < ptr.size_y; i++)
	{
		for (int j = 0; j < ptr.size_x; j++)
		{
			(ptr.map_z[i][j] >= 0) ? (printf(" ")) : 0;
			printf("%d ", ptr.map_z[i][j]);
		}
		printf("\n");
	}
	createImage(&ptr);
	return (0);
}
