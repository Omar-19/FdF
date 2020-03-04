/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:55:12 by fyuko             #+#    #+#             */
/*   Updated: 2019/11/28 18:55:13 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		check_ch(char *av)
{
	int i;
	int p;

	i = 0;
	p = 0;
	while (av[i])
	{
		if (av[i] != ' ' && av[i] != '\n' && av[i] != '\t')
		{
			while (av[i] != ' ' && av[i] != '\n' &&
				av[i] != '\t' && av[i] != '\0')
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
			break ;
		res[i] = ft_atoi(sp + 1);
		sp = ft_strchr(sp + 1, ' ');
		i++;
	}
	return (res);
}

void	read_map(t_mlx *ptr, t_file *file, t_strm **head_s, t_strm **tmp)
{
	if (!(file->res = get_next_line(file->fd, &(file->str))))
		exit(0);
	*head_s = create_el(file->str);
	ptr->size_x = check_ch((*head_s)->s);
	*tmp = *head_s;
	while (file->res == 1)
	{
		++(ptr->size_y);
		file->res = get_next_line(file->fd, &(file->str));
		if (file->res == 0)
		{
			free((file->str));
			break ;
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
