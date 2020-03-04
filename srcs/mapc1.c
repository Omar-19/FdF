/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapc1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:55:19 by fyuko             #+#    #+#             */
/*   Updated: 2019/11/28 18:55:23 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

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

void	help_map_create(char *tmp, int *res)
{
	*res = hex_ch(tmp[0]) * pow(16, 5) + hex_ch(tmp[1]) * pow(16, 4);
	*res += hex_ch(tmp[2]) * pow(16, 3) + hex_ch(tmp[3]) * pow(16, 2);
	*res += hex_ch(tmp[4]) * pow(16, 1) + hex_ch(tmp[3]);
}

int		col_r(char **str)
{
	char	*tmp;
	int		k[2];

	tmp = *str;
	k[0] = 0;
	while (*tmp != ' ' && *tmp != '\0')
	{
		if (*tmp == ',' && ++k[0])
			break ;
		++tmp;
	}
	if (k[0] == 0)
	{
		(*tmp == ' ') ? ++tmp : 0;
		(*tmp == ' ') ? ++tmp : 0;
		*str = tmp;
		return (0);
	}
	tmp = tmp + 3;
	help_map_create(tmp, &k[1]);
	tmp = tmp + 6;
	(*tmp == ' ') ? ++tmp : 0;
	(*tmp == ' ') ? ++tmp : 0;
	*str = tmp;
	return (k[1]);
}

void	help_cr_map(t_mlx *ptr, t_strm **tmp, int *i, t_point **r)
{
	if (i[1]++ == 0)
	{
		ptr->map = creat_el(40 * i[0], (40 * i[2]) / ptr->size_x,
			ft_atoi((*tmp)->s), col_r(&((*tmp)->s)));
		ptr->z_max = &(ptr->map->z0);
		ptr->z_min = &(ptr->map->z0);
		*r = (ptr->map);
	}
	else
	{
		(*r)->next = creat_el(40 * i[0], (40 * i[2]) / ptr->size_x,
			ft_atoi((*tmp)->s), col_r(&((*tmp)->s)));
		*r = (*r)->next;
		((*r)->z0 > *(ptr->z_max)) ? (ptr->z_max = &((*r)->z0)) : 0;
		((*r)->z0 < *(ptr->z_min)) ? (ptr->z_min = &((*r)->z0)) : 0;
	}
}

void	create_map(t_mlx *ptr, t_strm **head_s, t_strm **tmp)
{
	int		i[3];
	char	*str;
	t_point *r;

	i[2] = 0;
	i[0] = 0;
	i[1] = 0;
	*tmp = *head_s;
	r = NULL;
	while (*tmp)
	{
		str = (*tmp)->s;
		i[0] = 0;
		while (i[0] < ptr->size_x)
		{
			help_cr_map(ptr, tmp, i, &r);
			i[0]++;
		}
		i[2] += ptr->size_x;
		(*tmp) = (*tmp)->next;
		free(str);
	}
	links_map(ptr);
}
