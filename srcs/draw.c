# include "../includes/header.h"

void drawGrid(t_mlx *ptr)
{
	ptr->j = 0;
	ptr->y0 = ptr->indent_y;
	ptr->y = ptr->y0;
	while(ptr->j < ptr->size_y)
	{
		if (ptr->y0 >= HEIGHT)
			continue;
		ptr->x0 = ptr->indent_x;
		ptr->i = 0;
		while(ptr->i < ptr->size_x)
		{
			if (ptr->x0 >= WIDTH)
				continue;
			(ptr->pix_m)[WIDTH * ptr->y0 + ptr->x0] = ptr->color;
			(ptr->i != 0) ? (paint_lines(*ptr, 0)) : 0;
			(ptr->j != 0) ? (paint_lines(*ptr, -1)) : 0;
			ptr->x = ptr->x0;
			ptr->x0 += ptr->size_line;
			++(ptr->i);
		}
		ptr->y = ptr->y0;
		ptr->y0 += ptr->size_line;
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

	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
	
	mlx_loop(ptr->mlx_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_ptr);
	return (0);
}