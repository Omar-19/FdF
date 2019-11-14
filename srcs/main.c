# include "../includes/header.h"

int	some_key(int key)
{
	if (key == 53)
		exit(1);
	if (key == 69)
		return(1);
	if (key == 78)
		return(-1);
	// printf("key: %d\n", key);
	return (0);
}

int	some_mouse(int key)
{
	// left 1
	// right2
	// scroll up 4
	// scroll down 5
	// printf("key: %d\n", key);
	return (0);
}

void	write_tops(t_mlx *ptr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	// ptr->pix_m = (int *)mlx_get_data_addr(ptr->img_ptr,
	// 	&(ptr->bits_per_pixel), &(ptr->size_line), &(ptr->endian));
	// if (ptr->size_x > ptr->size_y)
	// 	ptr->size_line = (WIDTH - 300) / ptr->size_x;
	// else
	// 	ptr->size_line = (HEIGHT - 300) / ptr->size_y;
	// while(i != ptr->size_y)
	
}

void	paint_horizontal_lines(t_mlx *ptr)
{
	if (ptr->y0 > ptr->y)
	{
		ptr->y0 = ptr->y;
		ptr->y = ptr->y0;
	}
    ptr->error = 0;
	ptr->delt = (double)abs(ptr->y - ptr->y0) / (double)abs(ptr->x - ptr->x0);
    ptr->dir_y = ptr->y - ptr->y0;
    if (ptr->dir_y > 0)
		ptr->dir_y = 1;
    if (ptr->dir_y < 0) 
		ptr->dir_y = -1;
	while(ptr->x0 <= ptr->x)
	{
		ptr->pix_m[ptr->y0 * WIDTH + ptr->x0] = 0xFF0000;
        ptr->error = ptr->error + ptr->delt;
        if (ptr->error >= 0.5)
		{
			ptr->y0 = ptr->y0 + ptr->dir_y;
            ptr->error = ptr->error - 1.0;
		}
		++(ptr->x0);
	}
}

void	paint_vertical_lines(t_mlx *ptr)
{
	if (ptr->x0 > ptr->x)
	{
		ptr->x0 = ptr->x;
		ptr->x = ptr->x0;
	}
    ptr->error = 0;
	ptr->delt = (double)abs(ptr->x - ptr->x0) / (double)abs(ptr->y - ptr->y0);
    ptr->dir_x = ptr->x - ptr->x0;
    if (ptr->dir_x > 0)
		ptr->dir_x = 1;
    if (ptr->dir_x < 0) 
		ptr->dir_x = -1;
	while(ptr->y0 <= ptr->y)
	{
		ptr->pix_m[ptr->y0 * WIDTH + ptr->x0] = 0xFF0000;
        ptr->error = ptr->error + ptr->delt;
        if (ptr->error >= 0.5)
		{
			ptr->x0 = ptr->x0 + ptr->dir_x;
            ptr->error = ptr->error - 1.0;
		}
		++(ptr->y0);
	}
}

void	paint_lines(t_mlx *ptr)
{
	if (abs(ptr->x - ptr->x0) > abs(ptr->y - ptr->y0))
		paint_horizontal_lines(ptr);
	else
		paint_vertical_lines(ptr);
}

int		ft_write_image(t_mlx *ptr)
{
	int i;

	ptr->mlx_ptr = mlx_init();
	ptr->win_ptr =  mlx_new_window(ptr->mlx_ptr, WIDTH, HEIGHT, "FdF");
	ptr->img_ptr = mlx_new_image (ptr->mlx_ptr,  WIDTH, HEIGHT);
	ptr->pix_m = (int *)mlx_get_data_addr(ptr->img_ptr,
		&(ptr->bits_per_pixel), &(ptr->size_line), &(ptr->endian));
	//рисование сетки
	// write_tops(ptr);
	//отрисовкиа линий

	ptr->x0 = 5;
	ptr->x = 500;
	ptr->y0 = 5;
	ptr->y = 5;
	paint_lines(ptr);
	ptr->x0 = 5;
	ptr->x = 5;
	ptr->y0 = 5;
	ptr->y = 500;
	paint_lines(ptr);

	// while(i++ < 800)
	// 	ptr->pix_m[800 * 300 + i] = 0xFF0000;

	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);

	mlx_key_hook(ptr->win_ptr, some_key, (void*)0);
	mlx_mouse_hook(ptr->win_ptr, some_mouse, (void*)0);
	
	mlx_loop(ptr->mlx_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_ptr);
	return (0);
}

void	ft_null(t_mlx *ptr)
{
	ptr->x = 0;
	ptr->y = 0;
	ptr->x = 0;
	ptr->x0 = 0;
	ptr->y0 = 0;
	ptr->z0 = 0;
	ptr->size_x = 0;
	ptr->size_y = 0;
	ptr->bits_per_pixel = 0;
	ptr->size_line = 0;
	ptr->endian = 0;
	ptr->mlx_ptr = NULL;
	ptr->win_ptr = NULL;
	ptr->img_ptr = NULL;
	ptr->pix_m = NULL;
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
	read_map(&ptr, &file, &head_s, &tmp);
	create_map(&ptr, &file, &head_s, &tmp);
	
	for (int i = 0; i < ptr.size_y; i++)
	{
		for (int j = 0; j < ptr.size_x; j++)
			printf("%d ", ptr.map_i[i][j]);
		printf("\n");
	}
	ft_write_image(&ptr);
	return (0);
}
