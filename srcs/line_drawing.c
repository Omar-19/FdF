# include "../includes/header.h"

int		ft_col(int col, int i)
{
	int r;
	int g;
	int b;

	r = 255;
	g = 0;
	b = 0;
	while (i > 0)
	{
		if (r && !b)
		{
			// printf("-------\n");
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
		--i;
		// (r) ? ((--r) && (++g)) : 0;
		// (g < 255) ? (++g) : (++b);
	}
	// 254 256 256 = 16 646 144
	// 16 646 400
	col = r * 256 * 256 + g * 256 + b;
	// printf("col = %d\n", col);
	// 16711680 = 255 * 256 * 256
	// 65280 = 255 * 256
	// 255
	// printf("col = %d\n", col);
	return(col);
}

void	line_y(t_mlx pr, t_line ptr)
{
	float tmp;
	float er = 0;
	float opt;
	int dl;
	int i;

	pr.color1 = RED;
	i = 1;
	tmp = fabsf(ptr.x - ptr.x0) / fabsf(ptr.y - ptr.y0);
	if (ptr.x0 > ptr.x)
		opt = -1;
	else
		opt = 1;
	while (ptr.y0 <= ptr.y)
	{
		// printf("col = %d i = %d\n", (pr.color1 + i * 2), i);
		if (ptr.y0 < HEIGHT && ptr.y0 >= 0 && ptr.x0 < WIDTH && ptr.x0 >= 0)
			pr.pix_m[(int)ptr.y0 * WIDTH + (int)ptr.x0] = ft_col(pr.color1, i++);// * 2;// + (i++) * pr.g;
		er += tmp;
		++i;
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
	float er = 0;
	float opt;
	int dl;
	int i;

	pr.color1 = RED;
	i = 0;
	tmp = fabsf(ptr.y - ptr.y0) / fabsf(ptr.x - ptr.x0);
	if (ptr.y0 > ptr.y)
		opt = -1;
	else
		opt = 1;
	while (ptr.x0 <= ptr.x)
	{
		if (ptr.x0 < HEIGHT && ptr.x0 >= 0 && ptr.y0 < WIDTH && ptr.y0 >= 0)
			pr.pix_m[(int)ptr.y0 * WIDTH + (int)ptr.x0] = ft_col(pr.color1, i++);// + (i++) * pr.g;
		er += tmp;
		if (er >= 0.5)
		{
			ptr.y0 += opt;
			er -= 1;
		}
		(ptr.x0)++;
		++i;
	}
}

void	draw_line(t_mlx pr, t_point *t1, t_point *t2)
{
	float tmp;
	t_line ptr;

	ptr.x0 = (float)(t1->x) + WIDTH/2;
	ptr.x = (float)(t2->x) + WIDTH/2;
	ptr.y0 = (float)(t1->y) + HEIGHT/2;
	ptr.y = (float)(t2->y) + HEIGHT/2;
	ptr.z = (float)(t2->z);
	// printf();
	// if ((ptr.x0 > WIDTH || ptr.x > WIDTH) || (ptr.x0 < 0 || ptr.x < 0)
	// 	|| (ptr.y0 > HEIGHT || ptr.y > HEIGHT) || (ptr.y0 < 0 || ptr.y < 0))
	// 	return ;
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
