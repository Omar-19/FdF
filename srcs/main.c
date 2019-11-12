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

int		ft_write_image(t_mlx *ptr, char **av)
{
	int i;

	ptr->mlx_ptr = mlx_init();
	ptr->win_ptr =  mlx_new_window(ptr->mlx_ptr, WIDTH, HEIGHT, "42");

	ptr->img_ptr = mlx_new_image (ptr->mlx_ptr,  WIDTH, HEIGHT);
	
	ptr->pix_m = (int *)mlx_get_data_addr(ptr->img_ptr, &(ptr->bits_per_pixel), &(ptr->size_line), &(ptr->endian));
	i = 0;
	while(i++ < 800)
		ptr->pix_m[800 * 300 + i] = 0xFF0000;

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

int		check_ch(char *av, char c)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	while (av[i])
	{
		if (av[i] == ' ')
			++p;
		++i;
	}
	return (i);
}

t_strm	*creat_el(char *av)
{
	t_strm *tmp;

	if (!(tmp = (t_strm*)malloc(sizeof(t_strm))))
		exit(0);
	tmp->s = av;
	tmp->next = NULL;
	return (tmp);
}

int		*create_array(char *av, int size)
{
	int		*res;
	int		i;
	char	*sp;

	if (!(res = malloc(sizeof(int) * size)))
		exit(0);
	res[0] = ft_atoi(av);
	sp = ft_strchr(av, ' ');
	i = 1;
	while (i < size)
	{
		if (sp == NULL)
			break;
		res[i] = ft_atoi(sp + 1);
		sp = ft_strchr(sp + 1, ' ');
		i++;
	}
	return (res);
}

int		main(int argc, char **argv)
{
	t_mlx	ptr;
	t_file	file;
	t_strm	*head_s;
	t_strm	*tmp;

	ft_null(&ptr);
	// ft_write_image(&ptr, argv);
	if (argc != 2)
		return (0);
	file.fd = open(argv[1], O_RDONLY);
	file.res = get_next_line(file.fd, &(file.str));
	head_s = creat_el(file.str);
	ptr.size_x = check_ch(head_s->s, ' ');
	tmp = head_s;
	while (file.res == 1)
	{
		++ptr.size_y;
		file.res = get_next_line(file.fd, &(file.str));
		tmp->next = creat_el(file.str);
		tmp = tmp->next;
	}
	// tmp = head_s;
	// while(tmp)
	// {
	// 	printf("%s\n", tmp->s);
	// 	tmp = tmp->next;
	// }
	ptr.map_i = (int **)malloc(sizeof(int *) * ptr.size_y);
	int i = 0;
	tmp = head_s;
	int		**sl;

	sl = ptr.map_i;
	while (i < ptr.size_y)
	{
		sl[i] = create_array(tmp->s, ptr.size_x);
		tmp = tmp->next;
		++i;
	}
	for (int i = 0; i < ptr.size_y; i++)
	{
		for (int j = 0; j < ptr.size_x; j++)
			printf("%d ", ptr.map_i[i][j]);
		printf("\n");
	}
	return (0);
}
