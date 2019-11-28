# include "../includes/header.h"

void grad(t_mlx *ptr, int d)
{
	t_point *tmp;

	tmp = ptr->map;
	while (tmp)
	{
		(tmp->col) ? (tmp->z0 += d) : 0;
		tmp = tmp->next; 
	}
}

void sdvig(t_mlx *ptr, int d, int k)
{
	t_point *tmp;

	tmp = ptr->map;
	while (tmp)
	{
		(k == 1) ? tmp->x0 += d : 0;
		(k == 2) ? tmp->y0 += d : 0;
		tmp = tmp->next;
	}
}

//w 13
//s 1
//a 0
//d 2
int	key_press(int key, void *param)
{
	t_mlx *ptr;

	ptr = (t_mlx *)param;
	// printf("key = %d\n", key);
	if (key == NUM_PAD_ESC)
	{
		mlx_destroy_image(ptr->mlx_ptr, ptr->img_ptr);
		// free(ptr);
		exit(1);
	}
	else if (key == NUM_PAD_0 || key == NUM_PAD_2 ||
			key == NUM_PAD_4 || key == NUM_PAD_5 ||
			key == NUM_PAD_6 || key == NUM_PAD_7 || key == NUM_PAD_8 ||
													key == NUM_PAD_9)
	{
		(key == NUM_PAD_0) ? grad(ptr, -10) : 0;
		(key == NUM_PAD_5) ? grad(ptr, 10) : 0;
		(key == NUM_PAD_4) ? ptr->dy -= 0.2 : 0;
		(key == NUM_PAD_6) ? ptr->dy += 0.2 : 0;
		(key == NUM_PAD_2) ? ptr->dx -= 0.2 : 0;
		(key == NUM_PAD_8) ? ptr->dx += 0.2 : 0;
		(key == NUM_PAD_7) ? ptr->dz -= 0.2 : 0;
		(key == NUM_PAD_9) ? ptr->dz += 0.2 : 0;
		create_mlxImg(ptr);
		// printf("z_min = %d    z_max = %d\n", *ptr->z_min, *ptr->z_max);
	}
	if (key == NUM_PAD_PLUS)
	{
		resize_map(ptr, 1);
        create_mlxImg(ptr);
	}
	if (key == NUM_PAD_MINUS)
	{
		resize_map(ptr, -1);
		create_mlxImg(ptr);
	}
	if (key == 13)
		sdvig(ptr, -10, 2);
	if (key == 1)
		sdvig(ptr, 10, 2);
	if (key == 0)
		sdvig(ptr, -10, 1);
	if (key == 2)
		sdvig(ptr, 10, 1);
	create_mlxImg(ptr);
	return (0);
}
