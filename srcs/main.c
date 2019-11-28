#include "../includes/header.h"

void	create_mlx_img(t_mlx *ptr)
{
	if (ptr->img_ptr)
		mlx_destroy_image(ptr->mlx_ptr, ptr->img_ptr);
	ptr->img_ptr = mlx_new_image(ptr->mlx_ptr, WIDTH, HEIGHT);
	ptr->pix_m = (int *)mlx_get_data_addr(ptr->img_ptr,
		&(ptr->bits_per_pixel), &(ptr->pix_m_size), &(ptr->endian));
	lst_iso(ptr);
	if (abs(*(ptr->z_max)) > abs(*(ptr->z_min)))
		ptr->g = (float)255 / (float)(abs(*(ptr->z_max)) * ptr->size_line);
	else
	{
		if (abs(*(ptr->z_min)) == 0)
			ptr->g = 0;
		else
			ptr->g = (float)255 / (float)(abs(*(ptr->z_min)) * ptr->size_line);
	}
	lst_map_p(ptr);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
}

int		create_image(t_mlx *ptr)
{
	int		i;
	void	*a;

	ptr->dx = 0;
	ptr->dy = 0;
	ptr->dz = 0;
	ptr->mlx_ptr = mlx_init();
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, WIDTH, HEIGHT, "FdF project");
	create_mlx_img(ptr);
	mlx_hook(ptr->win_ptr, 2, 0, key_press, ptr);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
	mlx_loop(ptr->mlx_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_ptr);
	return (0);
}

void	help_map(int *i)
{
	i[0] = 0;
	i[1] = 0;
	i[2] = 1;
}

void	help_map1(t_point *tmp)
{
	tmp->x0 = 0;
	tmp->y0 = 0;
}

void	resize_map(t_mlx *ptr, int l)
{
	t_point	*tmp;
	int		i[3];

	help_map(i);
	tmp = ptr->map;
	ptr->size_line += l;
	if (ptr->size_line < 0)
	{
		ptr->size_line = 0;
		i[2] = 0;
	}
	while (tmp)
	{
		(i[0] % ptr->size_x == 0) ? (++i[1]) : 0;
		if (i[2])
		{
			tmp->x0 = tmp->x0 + l * (i[0] % ptr->size_x);
			tmp->y0 = tmp->y0 + l * i[1];
		}
		if (!i[2])
			help_map1(tmp);
		tmp = tmp->next;
		++i[0];
	}
}

void	del_map(t_point **map)
{
	t_point *tmp;
	t_point *next;

	tmp = *map;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	*map = NULL;
}

int		main(int argc, char **argv)
{
	t_mlx	ptr;
	t_file	file;
	t_strm	*head_s;
	t_strm	*tmp;

	ft_bzero((void *)(&ptr), sizeof(t_mlx));
	ptr.size_line = 40;
	if (argc != 2)
		return (0);
	ptr.color1 = RED;
	file.fd = open(argv[1], O_RDONLY);
	readMap(&ptr, &file, &head_s, &tmp);
	createMap(&ptr, &file, &head_s, &tmp);
	ptr.img_ptr = NULL;
	create_image(&ptr);
	return (0);
}
