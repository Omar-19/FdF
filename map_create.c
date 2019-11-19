# include "includes/header.h"

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
	return (p);
}

t_strm	*create_el(char *av)
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

void	readMap(t_mlx *ptr, t_file *file, t_strm **head_s, t_strm **tmp)
{
	file->res = get_next_line(file->fd, &(file->str));
	*head_s = create_el(file->str);
	ptr->size_x = check_ch((*head_s)->s, ' ');
	*tmp = *head_s;
	while (file->res == 1)
	{
		++(ptr->size_y);
		file->res = get_next_line(file->fd, &(file->str));
		// printf("%s\n", file->str);
		(*tmp)->next = create_el(file->str);
		*tmp = (*tmp)->next;
	}
}

void	links_map(t_mlx	*ptr)
{
	int	i;
	t_point *l;
	t_point	*b;
	int k;

	i = 0;
	k = 0;
	while (i < ptr->size_x * ptr->size_y)
	{
		if (i < ptr->size_x)
			b = NULL;
		else
			b = *(ptr->map + i - ptr->size_x);
		if (!i || !((i) % ptr->size_x))
		{
			// printf("i = %d\n", i);
			l = NULL;
		}
		else
		{
			// printf("ilef = %d\n", i);
			l = *(ptr->map + i - 1);
			// printf("ilef = %p\n", l);
			// printf("x = %d\n", l->z);
		}
		(*(ptr->map + i))->top = b;
		(*(ptr->map + i))->left = l;
		// if (i == 1)
		// 	printf(" %p \n", ((ptr->map)[i]).left);
		i++;
		// (i % 10) ? k += ptr->size_x : 0;
	}
	
}

t_point	*creat_el(int x, int y, int z)
{
	t_point *tmp;

	tmp = (t_point*)malloc(sizeof(t_point));
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	return (tmp);
}

void	createMap(t_mlx	*ptr, t_file *file, t_strm **head_s, t_strm **tmp)
{
	int		i;
	int		j;
	int		*l;
	int		k;

	k = 0;
	i = 0;
	j = 0;
	ptr->map = (t_point**)malloc(sizeof(t_point*) * ptr->size_y * ptr->size_x);
	*tmp = *head_s;
	while (*tmp)
	{
		l = create_array((*tmp)->s, ptr->size_x);
		i = 0;
		while (i < ptr->size_x)
		{
			// (ptr->map[i + k]).x = 40 * i;
			// (ptr->map[i + k]).y = (40 * k) / ptr->size_x;
			// (ptr->map[i + k]).z = l[i];
			*(ptr->map + i + k) = creat_el(40 * i, (40 * k) / ptr->size_x, l[i]);
			// printf("%d ", (ptr->map[i + k]).z);
			i++;
		}
		// printf("\n");
		k += ptr->size_x;
		(*tmp) = (*tmp)->next;
	}
	links_map(ptr);
}