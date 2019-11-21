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
    int i;
    int j;

	j = 0;
	i = 0;
	// lst_x_sligt(ptr);
    while (i < ptr->size_y * ptr->size_x)
    {
    	iso_one(*(ptr->map + i));
		++i;
    }
}

void	lst_map_p(t_mlx *ptr)
{
	int i;

	i = 0;
    while (i < ptr->size_y * ptr->size_x)
    {
    	if ((*(ptr->map + i))->left)
		{
			ptr->color1 = RED;
			draw_line(*ptr, *(ptr->map + i), (*(ptr->map + i))->left);
		}
		if ((*(ptr->map + i))->top)
		{
			ptr->color1 = 0x00FF00;
			draw_line(*ptr, *(ptr->map + i), (*(ptr->map + i))->top);
		}
		++i;
    }
}

void	lst_x_sligt(t_mlx *ptr)
{
	float	x;
	float	y;
	float	z;
	int		i;

	i = 0;
    while (i < ptr->size_y * ptr->size_x)
    {
		(*(ptr->map + i))->x = (*(ptr->map + i))->x0;
		(*(ptr->map + i))->y = ((*(ptr->map + i))->y0) * cos(ptr->dx) + ((*(ptr->map + i))->z0) * sin(ptr->dx);
		(*(ptr->map + i))->z = -((*(ptr->map + i))->y0) * sin(ptr->dx) + ((*(ptr->map + i))->z0) * cos(ptr->dx);

		x = (*(ptr->map + i))->x;
		z = (*(ptr->map + i))->z;
		(*(ptr->map + i))->x = x * cos(ptr->dy) + z * sin(ptr->dy);
		(*(ptr->map + i))->z = -x * sin(ptr->dy) + z * cos(ptr->dy);

		x = (*(ptr->map + i))->x;
		y = (*(ptr->map + i))->y;
		(*(ptr->map + i))->x = x * cos(ptr->dz) - y * sin(ptr->dz);
		(*(ptr->map + i))->y = x * sin(ptr->dz) + y * cos(ptr->dz);
		++i;
    }
}