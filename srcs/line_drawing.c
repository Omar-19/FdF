# include "../includes/header.h"

void	line_y(t_mlx pr, t_line ptr)
{
	float tmp;

	tmp = fabsf(ptr.x - ptr.x0) / fabsf(ptr.y - ptr.y0);
	float er = 0;
	float opt;
	if (ptr.x0 > ptr.x)
		opt = -1;
	else
		opt = 1;
	while (ptr.y0 <= ptr.y)
	{
		if (ptr.y0 < HEIGHT && ptr.y0 >= 0 && ptr.x0 < WIDTH && ptr.x0 >= 0)
			pr.pix_m[(int)ptr.y0 * WIDTH + (int)ptr.x0 + 1] = pr.color1;
		er += tmp;
		if (er >= 0.5)
		{
			ptr.x0 += opt;
			er -= 1;
		}
		(ptr.y0)++;
	}
}

void	line_x(t_mlx pr, t_line ptr)
{
	float tmp;

	tmp = fabsf(ptr.y - ptr.y0) / fabsf(ptr.x - ptr.x0);
	float er = 0;
	float opt;
	if (ptr.y0 > ptr.y)
		opt = -1;
	else
		opt = 1;
	while (ptr.x0 <= ptr.x)
	{
		if (ptr.x0 < HEIGHT && ptr.x0 >= 0 && ptr.y0 < WIDTH && ptr.y0 >= 0)
			pr.pix_m[(int)ptr.y0 * WIDTH + (int)ptr.x0 + 1] = pr.color1;
		er += tmp;
		if (er >= 0.5)
		{
			ptr.y0 += opt;
			er -= 1;
		}
		(ptr.x0)++;
	}
}

void	draw_line(t_mlx pr, t_point *t1, t_point *t2)
{
	float tmp;
	t_line ptr;

	ptr.x0 = (float)(t1->x);
	ptr.x = (float)(t2->x);
	ptr.y0 = (float)(t1->y);
	ptr.y = (float)(t2->y);
	if ((ptr.x0 > WIDTH || ptr.x > WIDTH) || (ptr.x0 < 0 || ptr.x < 0)
		|| (ptr.y0 > HEIGHT || ptr.y > HEIGHT) || (ptr.y0 < 0 || ptr.y < 0))
		return ;
	if ((fabsf(ptr.y - ptr.y0) / fabsf(ptr.x - ptr.x0) < 1 && ptr.x0 > ptr.x)
		|| (fabsf(ptr.y - ptr.y0) / fabsf(ptr.x - ptr.x0) >= 1 && ptr.y0 > ptr.y))
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