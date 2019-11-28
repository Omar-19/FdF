#include "../includes/header.h"

void	hel_func2(int *r, int *g, int *b, int col)
{
	*r = col / (256 * 256);
	col = col % (256 * 256);
	*g = col / 256;
	*b = col % 256;
}

int		c(t_mlx pr, int col, int i)
{
	int r;
	int g;
	int b;

	hel_func2(&r, &g, &b, col);
	i = (int)(pr.g * (float)i * pr.size_line);
	while (i-- > 0)
	{
		if (r && !b)
		{
			--r;
			++g;
		}
		else if (g && !r)
		{
			--g;
			++b;
		}
		else
		{
			--b;
			++r;
		}
	}
	return (r * 256 * 256 + g * 256 + b);
}

int		col_min(t_mlx pr, float z)
{
	float	n;
	int		r;
	int		g;
	int		b;

	r = 0;
	g = 255;
	b = 0;
	n = fabs(z) * pr.size_line * pr.g;
	if (z > 0)
		while ((int)(n--))
		{
			--g;
			++r;
		}
	else
		while ((int)(n--))
		{
			--g;
			++b;
		}
	return (r * 256 * 256 + g * 256 + b);
}

void	help_func(float *a, int *b)
{
	*a = 0;
	*b = 0;
}

void	line_y(t_mlx pr, t_line ptr)
{
	float	teo[3];
	int		i[2];

	help_func(&teo[1], &i[0]);
	teo[0] = fabsf(ptr.x - ptr.x0) / fabsf(ptr.y - ptr.y0);
	if (ptr.z > ptr.z0)
		i[1] = col_min(pr, ptr.z);
	else
		i[1] = col_min(pr, ptr.z0);
	if (ptr.x0 > ptr.x)
		teo[2] = -1;
	else
		teo[2] = 1;
	while (ptr.y0 <= ptr.y)
	{
		if (ptr.y0 < HEIGHT && ptr.y0 >= 0 && ptr.x0 < WIDTH && ptr.x0 >= 0)
			pr.pix_m[(int)ptr.y0 * WIDTH + (int)ptr.x0] = c(pr, i[1], i[0]++);
		teo[1] += teo[0];
		if (teo[1] >= 0.5)
		{
			ptr.x0 += teo[2];
			teo[1] -= 1;
		}
		(ptr.y0)++;
	}
}

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
