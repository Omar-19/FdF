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
	// ptr->zmxp += d;
	// ptr->zmxn += d;
	// (ptr->zmn) ? (ptr->zmn += d) : 0;
	// if (abs(ptr->zmxp) > abs(ptr->zmxn))
	// 	ptr->g = fabsf(fabsf((float)YELLOW - (float)RED)/ fabsf((float)ptr->zmxp - (float)ptr->zmn));
	// else if (abs(ptr->zmxp) < abs(ptr->zmxn))
	// 	ptr->g = fabsf(fabsf((float)YELLOW - (float)RED)/ fabsf((float)ptr->zmn - (float)ptr->zmxp));
}

int	key_press(int key, void *param)
{
	t_mlx *ptr;

	ptr = (t_mlx *)param;
	// printf("key = %d\n", key);
	if (key == NUM_PAD_ESC)
		exit(1);
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
	}
	if (key == NUM_PAD_PLUS)
	{
		// ptr->size_line += 10;
		resize_map(ptr, 1);
        // mlx_destroy_image(ptr->mlx_ptr, ptr->img_ptr);
        create_mlxImg(ptr);
        // lst_map_p(ptr);
        // mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
        // lst_map_p(ptr);
		// ptr->indent_x -= ZOOM/2;
		// (ptr->indent_x < 0) ? (ptr->indent_x = 0) : 0;
		// ptr->indent_y -= ZOOM/2;
		// (ptr->indent_y < 0) ? (ptr->indent_y = 0) : 0;
		// ptr->size_line += ZOOM;
	}
	if (key == NUM_PAD_MINUS)
	{
		// ptr->size_line -= 10;
		resize_map(ptr, -1);
		create_mlxImg(ptr);
		// mlx_destroy_image(ptr->mlx_ptr, ptr->img_ptr);
        // create_mlxImg(ptr);
		// ptr->indent_x += ZOOM/2;
		// (ptr->indent_x > WIDTH/2) ? (ptr->indent_x = WIDTH/2) : 0;
		// ptr->indent_y += ZOOM/2;
		// (ptr->indent_y > HEIGHT/2) ? (ptr->indent_x = HEIGHT/2) : 0;
		// ptr->size_line -= ZOOM;
		// (ptr->size_line < 0) ? (ptr->size_line = 0) : 0;
	}
	// if ()
	// (ptr->size_line < 0) ? (ptr->size_line = 0) : 0;
	return (0);
}
