/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:55:05 by fyuko             #+#    #+#             */
/*   Updated: 2019/11/28 18:55:07 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

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
	read_map(&ptr, &file, &head_s, &tmp);
	create_map(&ptr, &head_s, &tmp);
	ptr.img_ptr = NULL;
	create_image(&ptr);
	return (0);
}
