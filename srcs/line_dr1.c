/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_dr1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:54:36 by fyuko             #+#    #+#             */
/*   Updated: 2019/11/28 18:54:38 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	line_x(t_mlx pr, t_line ptr)
{
	float	teo[3];
	int		i[2];

	help_func(&teo[1], &i[0]);
	teo[0] = fabsf(ptr.y - ptr.y0) / fabsf(ptr.x - ptr.x0);
	if (ptr.y0 > ptr.y)
		teo[2] = -1;
	else
		teo[2] = 1;
	if (ptr.z > ptr.z0)
		i[1] = col_min(pr, ptr.z);
	else
		i[1] = col_min(pr, ptr.z0);
	while (ptr.x0 <= ptr.x)
	{
		if (ptr.x0 < HEIGHT && ptr.x0 >= 0 && ptr.y0 < WIDTH && ptr.y0 >= 0)
			pr.pix_m[(int)ptr.y0 * WIDTH + (int)ptr.x0] = c(pr, i[1], i[0]);
		teo[1] += teo[0];
		if (teo[1] >= 0.5)
		{
			ptr.y0 += teo[2];
			teo[1] -= 1;
		}
		(ptr.x0)++;
	}
}

void	draw_line(t_mlx pr, t_point *t1, t_point *t2)
{
	float	tmp;
	t_line	ptr;

	ptr.x0 = (float)(t1->x) + WIDTH / 2;
	ptr.x = (float)(t2->x) + WIDTH / 2;
	ptr.y0 = (float)(t1->y) + HEIGHT / 2;
	ptr.y = (float)(t2->y) + HEIGHT / 2;
	ptr.z = (float)(t2->z0);
	ptr.z0 = (float)(t1->z0);
	if ((fabsf(ptr.y - ptr.y0) / fabsf(ptr.x - ptr.x0) < 1 && ptr.x0 > ptr.x)
		|| (fabsf(ptr.y - ptr.y0) / fabsf(ptr.x - ptr.x0)
			>= 1 && ptr.y0 > ptr.y))
	{
		tmp = ptr.x0;
		ptr.x0 = ptr.x;
		ptr.x = tmp;
		tmp = ptr.y0;
		ptr.y0 = ptr.y;
		ptr.y = tmp;
	}
	if (fabsf(ptr.y - ptr.y0) / fabsf(ptr.x - ptr.x0) < 1)
		line_x(pr, ptr);
	else
		line_y(pr, ptr);
}

void	links_map(t_mlx *ptr)
{
	int		i;
	t_point	*l;
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
			l = NULL;
		else
			l = return_l(ptr->map, i - 1);
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
