# include "../includes/header.h"

int	key_press(int key, void *param)
{
	t_mlx *ptr;

	ptr = (t_mlx *)param;
	if (key == NUM_PAD_ESC)
		exit(1);
	else if (key == NUM_PAD_0 || key == NUM_PAD_1 || key == NUM_PAD_2 ||
			key == NUM_PAD_3 || key == NUM_PAD_4 || key == NUM_PAD_5 ||
			key == NUM_PAD_6 || key == NUM_PAD_7 || key == NUM_PAD_8 ||
													key == NUM_PAD_9)
	{
		int i;
		// ptr->x0 = 5;
		// ptr->x = 500;
		// ptr->y0 = 5;
		// ptr->y = 5;
		// paint_lines(ptr);
		// ptr->x0 = 5;
		// ptr->x = 5;
		// ptr->y0 = 5;
		// ptr->y = 500;
		// paint_lines(ptr);
	}
	if (key == NUM_PAD_PLUS)
	{
		matrixConversion(ptr);
		// ptr->indent_x -= ZOOM/2;
		// (ptr->indent_x < 0) ? (ptr->indent_x = 0) : 0;
		// ptr->indent_y -= ZOOM/2;
		// (ptr->indent_y < 0) ? (ptr->indent_y = 0) : 0;
		// ptr->size_line += ZOOM;
	}
	if (key == NUM_PAD_MINUS)
	{
		drawGrid(ptr);
		// ptr->indent_x += ZOOM/2;
		// (ptr->indent_x > WIDTH/2) ? (ptr->indent_x = WIDTH/2) : 0;
		// ptr->indent_y += ZOOM/2;
		// (ptr->indent_y > HEIGHT/2) ? (ptr->indent_x = HEIGHT/2) : 0;
		// ptr->size_line -= ZOOM;
		// (ptr->size_line < 0) ? (ptr->size_line = 0) : 0;
	}
	(ptr->size_line < 0) ? (ptr->size_line = 0) : 0;
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_ptr);
	create_mlxImg(ptr);
	drawGrid(ptr);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
	return (0);
}