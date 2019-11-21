#include "../includes/header.h"

void	iso_one(t_point *tmp)
{
	int x0;
	int y0;

	x0 = tmp->x;
	y0 = tmp->y;
	tmp->x = (float)x0 * cos(0.5) - (float)y0 * sin(0.5);
	tmp->y = (float)x0 * sin(0.5) + (float)y0 * cos(0.5);
	// tmp->x = (float)(x0 - y0) * cos(0.523599);
	// tmp->y = (float)(x0 + y0) * sin(0.523599) - (float)tmp->z;
}

void    lst_iso(t_mlx *ptr)
{
	t_point *tmp;

	tmp = ptr->map;
    while (tmp)
    {
    	iso_one(tmp);
		tmp= tmp->next;
    }
}

void	lst_map_p(t_mlx *ptr)
{
	int i;
	t_point *tmp;

	tmp = ptr->map;
	i = 0;
    while (tmp)
    {
    	if (tmp->left)
		{
			ptr->color1 = RED;
			draw_line(*ptr, tmp, tmp->left);
		}
		if (tmp->top)
		{
			ptr->color1 = 0x00FF00;
			draw_line(*ptr, tmp, tmp->top);
		}
		tmp = tmp->next;
		++i;
    }
}

void	lst_x_sligt(t_mlx *ptr)
{
	float	x;
	float	y;
	float	z;
	int		i;
	t_point *tmp;

	tmp = ptr->map;
	i = 0;
    while (tmp)
    {
		tmp->x = tmp->x0;
		tmp->y = (tmp->y0) * cos(ptr->dx) + (tmp->z0) * sin(ptr->dx);
		tmp->z = -(tmp->y0) * sin(ptr->dx) + (tmp->z0) * cos(ptr->dx);

		x = tmp->x;
		z = tmp->z;
		tmp->x = x * cos(ptr->dy) + z * sin(ptr->dy);
		tmp->z = -x * sin(ptr->dy) + z * cos(ptr->dy);

		x = tmp->x;
		y = tmp->y;
		tmp->x = x * cos(ptr->dz) - y * sin(ptr->dz);
		tmp->y = x * sin(ptr->dz) + y * cos(ptr->dz);
		tmp = tmp->next;
    }
}