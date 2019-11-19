# include "../includes/header.h"

void drawGrid(t_mlx *ptr)
{
	int cl;

	ptr->j = 0;
	while(ptr->j < ptr->size_y)
	{
		// if (ptr->y0 >= HEIGHT)
		// 	continue;
		ptr->i = 0;
		while(ptr->i < ptr->size_x)
		{
			ptr->x0 = *(*(ptr->map_x + ptr->j) + ptr->i);
			ptr->y0 = *(*(ptr->map_y + ptr->j) + ptr->i);
			// if (ptr->x0 >= WIDTH)
			// 	continue;
			// ptr->z = *(*(ptr->map_z + ptr->j) + ptr->i);
			ptr->color  = (ptr->i / 3) ? PURPLE : 0xFF0000;
			// ptr->color = (ptr->i == 1 && ptr->j == 0) ? TEAL: PURPLE;
			(ptr->pix_m)[WIDTH * ptr->y0 + ptr->x0] = ptr->color;
			//h
			if (ptr->i != 0)
			{
				ptr->x = *(*(ptr->map_x + ptr->j) + ptr->i - 1);
				ptr->y = *(*(ptr->map_y + ptr->j) + ptr->i - 1);
				// printf("hor %d %d %d %d\n", ptr->x0, ptr->y0, ptr->x, ptr->y);
				paint_lines(*ptr, 0); 
			}
			//v
			if (ptr->j != 0)
			{
				ptr->x = *(*(ptr->map_x + ptr->j - 1) + ptr->i);
				ptr->y = *(*(ptr->map_y + ptr->j - 1) + ptr->i);
				// printf("hor %d %d %d %d\n", ptr->x0, ptr->y0, ptr->x, ptr->y);
				paint_lines(*ptr, -1);
			}
			// ptr->x = ptr->x0;
			// ptr->x0 += ptr->size_line;
			++(ptr->i);
		}
		// ptr->y = ptr->y0;
		// ptr->y0 += ptr->size_line;
		++(ptr->j);
	}
}

int		createImage(t_mlx *ptr)
{
	int i;
	void *a;

	ptr->mlx_ptr = mlx_init();
	ptr->win_ptr =  mlx_new_window(ptr->mlx_ptr, WIDTH, HEIGHT, "FdF project");
	create_mlxImg(ptr);
	
	// обработка клавиатуры
	mlx_hook(ptr->win_ptr, 2, 0, key_press, ptr);
	// create_mlxImg(ptr);
	// drawGrid_1(ptr);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
	
	mlx_loop(ptr->mlx_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_ptr);
	return (0);
}