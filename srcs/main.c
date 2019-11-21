# include "../includes/header.h"


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

int		createImage(t_mlx *ptr)
{
	int i;
	void *a;

	ptr->mlx_ptr = mlx_init();
	ptr->win_ptr =  mlx_new_window(ptr->mlx_ptr, WIDTH, HEIGHT, "FdF project");
	create_mlxImg(ptr);
	lst_map_p(ptr);
	// обработка клавиатуры
	mlx_hook(ptr->win_ptr, 2, 0, key_press, ptr);
	// create_mlxImg(ptr);
	// drawGrid_1(ptr);
	// draw_line(ptr->pix_m, 50, 50, 500, 150);
	// draw_line(ptr->pix_m, 50, 150, 500, 50);
	// draw_line(ptr->pix_m, 50, 50, 150, 500);
	// draw_line(ptr->pix_m, 150, 50, 50, 500);
	// draw_line(ptr->pix_m, 424, 641, 504, 677);
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

	// ptr.dx = 0;
	// ptr.dy = 0;
	// ptr.dz = 0;
	if (argc != 2)
		return (0);
	ptr.color1 = RED;
	file.fd = open(argv[1], O_RDONLY);
	readMap(&ptr, &file, &head_s, &tmp);
	createMap(&ptr, &file, &head_s, &tmp);
	// t_point *k;
	// k = ptr.map;
	// while (k)
	// {
	// 	printf("x %d y %d z %d\n", k->x, k->y, k->z);
	// 	k = k->next;
	// }
	
	createImage(&ptr);
	// printf("x = %d\n", (*(ptr.map + 1))->left->x);
	return (0);
}
