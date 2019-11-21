# include "../includes/header.h"

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
	// free((file->str));
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
		// printf("%s\n", file->str);
		(*tmp)->next = create_el(file->str);
		// free((file->str));
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

t_point	*creat_el(int x, int y, int z)
{
	t_point *tmp;

	tmp = (t_point*)malloc(sizeof(t_point));
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	tmp->x0 = x;
	tmp->y0 = y;
	tmp->z0 = z;
	return (tmp);
}

void	createMap(t_mlx	*ptr, t_file *file, t_strm **head_s, t_strm **tmp)
{
	int		i;
	int		*l;
	int		k;
	int		j;
	t_point *r;

	k = 0;
	i = 0;
	j = 0;
	*tmp = *head_s;
	// ptr->map = r;
	while (*tmp)
	{
		l = create_array((*tmp)->s, ptr->size_x);
		i = 0;
		while (i < ptr->size_x)
		{
			if (j++ == 0)
			{
				ptr->map = creat_el(40 * i, (40 * k) / ptr->size_x, l[i]);
				r = (ptr->map);
			}
			else
			{
				r->next = creat_el(40 * i, (40 * k) / ptr->size_x, l[i]);
				r = r->next;
			}
			i++;
		}
		k += ptr->size_x;
		(*tmp) = (*tmp)->next;
	}
	links_map(ptr);
}