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

int	       main(int ac, char **av)
{
	t_mlx	ptr;
	int i = 0;
	// int j;

	if (ac != 2)
		return (0);
	av++;
	ptr.mlx_ptr = mlx_init();
	ptr.win_ptr =  mlx_new_window(ptr.mlx_ptr, WIDTH, HEIGHT, "42");

	ptr.img_ptr = mlx_new_image (ptr.mlx_ptr,  WIDTH, HEIGHT);
	
	ptr.pix_m = (int *)mlx_get_data_addr(ptr.img_ptr, &ptr.x, &ptr.y, &ptr.z);

	i = 0;
	while(i++ < 500)
		ptr.pix_m[i] = 0xFF0000;

	mlx_put_image_to_window(ptr.mlx_ptr, ptr.win_ptr, ptr.img_ptr, 0, 0);
	
	mlx_key_hook(ptr.win_ptr, some_key, (void*)0);
	mlx_mouse_hook(ptr.win_ptr, some_mouse, (void*)0);
	
	mlx_loop(ptr.mlx_ptr);
	mlx_destroy_image(ptr.mlx_ptr, ptr.img_ptr);
	return (0);
}
