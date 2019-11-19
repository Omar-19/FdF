# include "includes/header.h"


void	writeMatrix(t_mlx ptr)
{
	// printf("MATRIX X:\n");
	// for (int i = 0; i < ptr.size_x * ptr.size_y; i++)
	// {
	// 	printf("%d ", (ptr.map[i]).x);
	// 	if (i && !((i + 1) % ptr.size_x))
	// 		printf("\n");
	// }
	// printf("\n");
	// printf("MATRIX Y:\n");
	// for (int i = 0; i < ptr.size_x * ptr.size_y; i++)
	// {
	// 	printf("%d ", (ptr.map[i]).y);
	// 	if (i && !((i + 1) % ptr.size_x))
	// 		printf("\n");
	// }
	// printf("\n");
	// printf("MATRIX Z:\n");
	// for (int i = 0; i < ptr.size_x * ptr.size_y; i++)
	// {
	// 	printf("%d ", (ptr.map[i]).z);
	// 	if (i && !((i + 1) % ptr.size_x))
	// 		printf("\n");
	// }
	// printf("\n");
}

void	create_mlxImg(t_mlx *ptr)
{
	ptr->img_ptr = mlx_new_image (ptr->mlx_ptr,  WIDTH, HEIGHT);
	ptr->pix_m = (int *)mlx_get_data_addr(ptr->img_ptr,
		&(ptr->bits_per_pixel), &(ptr->pix_m_size), &(ptr->endian));
}

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
	}
	if (key == NUM_PAD_PLUS)
	{
		// ptr->indent_x -= ZOOM/2;
		// (ptr->indent_x < 0) ? (ptr->indent_x = 0) : 0;
		// ptr->indent_y -= ZOOM/2;
		// (ptr->indent_y < 0) ? (ptr->indent_y = 0) : 0;
		// ptr->size_line += ZOOM;
	}
	if (key == NUM_PAD_MINUS)
	{
		// ptr->indent_x += ZOOM/2;
		// (ptr->indent_x > WIDTH/2) ? (ptr->indent_x = WIDTH/2) : 0;
		// ptr->indent_y += ZOOM/2;
		// (ptr->indent_y > HEIGHT/2) ? (ptr->indent_x = HEIGHT/2) : 0;
		// ptr->size_line -= ZOOM;
		// (ptr->size_line < 0) ? (ptr->size_line = 0) : 0;
	}
	(ptr->size_line < 0) ? (ptr->size_line = 0) : 0;
	return (0);
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

int		main(int argc, char **argv)
{
	t_mlx	ptr;
	t_file	file;
	t_strm	*head_s;
	t_strm	*tmp;

	if (argc != 2)
		return (0);
	file.fd = open(argv[1], O_RDONLY);
	readMap(&ptr, &file, &head_s, &tmp);
	createMap(&ptr, &file, &head_s, &tmp);
	// writeMatrix(ptr);
	// createImage(&ptr);
	printf("x = %d\n", (*(ptr.map + 1))->left->x);
	return (0);
}
