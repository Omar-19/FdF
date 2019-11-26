# include "../includes/header.h"

int		check_ch(char *av, char c)
{
	int i;
	int p;

	i = 0;
	p = 0;
	while (av[i])
	{
		if (av[i] != ' ' &&  av[i] != '\n' && av[i] != '\t')
		{
			while (av[i] != ' ' && av[i] != '\n' && av[i] != '\t' && av[i] != '\0')
				++i;
			if (av[i] == '\0')
				--i;
			p++;
		}
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
		if (file->res == 0)
		{
			free((file->str));
			break;
		}
		(*tmp)->next = create_el(file->str);
		*tmp = (*tmp)->next;
	}
}

t_point	*return_l(t_point *head, int i)
{
	while (i-- > 0)
		head = head->next;
	return (head);
}

void	links_map(t_mlx	*ptr)
{
	int	i;
	t_point *l;
	t_point	*b;
	t_point	*tmp;

	i = 0;
	tmp = ptr->map;
	while (tmp)
	{
		if (i < ptr->size_x)
			b = NULL;
		else
			b = return_l(ptr->map, i - ptr->size_x);
		if (!i || !((i) % ptr->size_x))
		{
			// printf("i = %d\n", i);
			l = NULL;
		}
		else
		{
			// printf("ilef = %d\n", i);
			l = return_l(ptr->map, i - 1);
			// printf("ilef = %p\n", l);
			// printf("x = %d\n", l->z);
		}
		tmp->top = b;
		tmp->left = l; 
		tmp = tmp->next;
		i++;
	}	
}

t_point	*creat_el(int x, int y, int z, int col)
{
	t_point *tmp;

	tmp = (t_point*)malloc(sizeof(t_point));
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	tmp->x0 = x;
	tmp->y0 = y;
	tmp->z0 = z;
	tmp->col = (z) ? 1 : 0;
	tmp->num_col = col;
	return (tmp);
}

int		hex_ch(char c)
{
	if (c == 'A')
		return (10);
	if (c == 'B')
		return (11);
	if (c == 'C')
		return (12);
	if (c == 'D')
		return (13);
	if (c == 'E')
		return (14);
	if (c == 'F')
		return (15);
	return (c - '0');
}

int		col_r(char **str)
{
	char	*tmp;
	int		k;
	int		res;

	tmp = *str;
	k = 0;
	while (*tmp != ' ' && *tmp != '\0')
	{
		if (*tmp == ',' && ++k)
			break;
		++tmp;
	}
	if (k == 0)
	{
		(*tmp == ' ') ? ++tmp : 0;
		(*tmp == ' ') ? ++tmp : 0;
		*str = tmp;
		return (0);
	}	
	tmp = tmp + 3;
	res = hex_ch(tmp[0]) * pow(16, 5) + hex_ch(tmp[1]) * pow(16, 4);
	res += hex_ch(tmp[2]) * pow(16, 3) + hex_ch(tmp[3]) * pow(16, 2);
	res += hex_ch(tmp[4]) * pow(16, 1) + hex_ch(tmp[3]);
	tmp = tmp + 6;
	(*tmp == ' ') ? ++tmp : 0;
	(*tmp == ' ') ? ++tmp : 0;
	*str = tmp;
	return (res);
}
void	createMap(t_mlx	*ptr, t_file *file, t_strm **head_s, t_strm **tmp)
{
	int		i;
	int		*l;
	int		k;
	int		j;
	char	*str;
	t_point *r;

	k = 0;
	i = 0;
	j = 0;
	*tmp = *head_s;
	while (*tmp)
	{
		str = (*tmp)->s;
		i = 0;
		while (i < ptr->size_x)
		{
			if (j++ == 0)
			{
				ptr->map = creat_el(40 * i, (40 * k) / ptr->size_x, ft_atoi((*tmp)->s), col_r(&((*tmp)->s)));
				ptr->z_max = &(ptr->map->z0);
				ptr->z_min = &(ptr->map->z0);
				r = (ptr->map);
			}
			else
			{
				r->next = creat_el(40 * i, (40 * k) / ptr->size_x, ft_atoi((*tmp)->s), col_r(&((*tmp)->s)));
				r = r->next;
				(r->z0 > *(ptr->z_max)) ? (ptr->z_max = &(r->z0)) : 0;
				(r->z0 < *(ptr->z_min)) ? (ptr->z_min = &(r->z0)) : 0;
			}
			i++;
		}
		k += ptr->size_x;
		(*tmp) = (*tmp)->next;
		free(str);
	}
	links_map(ptr);
	printf("z_min = %d    z_max = %d\n", *ptr->z_min, *ptr->z_max);
}
