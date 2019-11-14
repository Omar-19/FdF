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

void	read_map(t_mlx	*ptr, t_file *file, t_strm **head_s, t_strm **tmp)
{
	file->res = get_next_line(file->fd, &(file->str));
	*head_s = creat_el(file->str);
	ptr->size_x = check_ch((*head_s)->s, ' ');
	*tmp = *head_s;
	while (file->res == 1)
	{
		++(ptr->size_y);
		file->res = get_next_line(file->fd, &(file->str));
		(*tmp)->next = creat_el(file->str);
		*tmp = (*tmp)->next;
	}
}

void	create_map(t_mlx	*ptr, t_file *file, t_strm **head_s, t_strm **tmp)
{
	int		i;
	int		**sl;

	i = 0;
	ptr->map_i = (int **)malloc(sizeof(int *) * ptr->size_y);
	*tmp = *head_s;
	sl = ptr->map_i;
	while (i < ptr->size_y)
	{
		sl[i] = create_array((*tmp)->s, ptr->size_x);
		*tmp = (*tmp)->next;
		++i;
	}
}