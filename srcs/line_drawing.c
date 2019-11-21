# include "../includes/header.h"

// void	drawHorizontalLines(t_mlx pr, t_line ptr)
// {
// 	// if (ptr.x0 > ptr.x)
// 	// {
// 	// 	ptr.i = ptr.x0;
// 	// 	ptr.x0 = ptr.x;
// 	// 	ptr.x = ptr.i;
// 	// }
// 	// if (ptr.y0 > ptr.y)
// 	// {
// 	// 	ptr.i = ptr.y0;
// 	// 	ptr.y0 = ptr.y;
// 	// 	ptr.y = ptr.i;
// 	// }
// 	ptr.delt = (double)abs(ptr.y - ptr.y0) / (double)abs(ptr.x - ptr.x0);
//     ptr.dir_y = ptr.y - ptr.y0;
//     if (ptr.dir_y > 0)
// 		ptr.dir_y = 1;
//     if (ptr.dir_y < 0) 
// 		ptr.dir_y = -1;
// 	while(ptr.x0 <= ptr.x)
// 	{
// 		pr.pix_m[(ptr.y0 * WIDTH + ptr.x0)] = pr.color1;
//         ptr.error = ptr.error + ptr.delt;
//         if (ptr.error >= 0.5)
// 		{
// 			ptr.y0 = ptr.y0 + ptr.dir_y;
//             ptr.error = ptr.error - 1.0;
// 		}
// 		++(ptr.x0);
// 	}
// }

// void	drawVerticalLines(t_mlx pr, t_line ptr)
// {
// 	// if (ptr.x0 > ptr.x)
// 	// {
// 	// 	ptr.i = ptr.x0;
// 	// 	ptr.x0 = ptr.x;
// 	// 	ptr.x = ptr.i;
// 	// }
// 	// if (ptr.y0 > ptr.y)
// 	// {
// 	// 	ptr.i = ptr.y0;
// 	// 	ptr.y0 = ptr.y;
// 	// 	ptr.y = ptr.i;
// 	// }
// 	ptr.delt = (double)abs(ptr.x - ptr.x0) / (double)abs(ptr.y - ptr.y0);
//     ptr.dir_x = ptr.x - ptr.x0;
//     if (ptr.dir_x > 0)
// 		ptr.dir_x = 1;
//     if (ptr.dir_x < 0) 
// 		ptr.dir_x = -1;
// 	while(ptr.y0 <= ptr.y)
// 	{
// 		pr.pix_m[(ptr.y0 * WIDTH + ptr.x0)] = pr.color1;
//         ptr.error = ptr.error + ptr.delt;
//         if (ptr.error >= 0.5)
// 		{
// 			ptr.x0 = ptr.x0 + ptr.dir_x;
//             ptr.error = ptr.error - 1.0;
// 		}
// 		++(ptr.y0);
// 	}
// }

// void	paint_lines(t_mlx pr, t_point *t1, t_point *t2)
// {
// 	t_line ptr;

// 	// ptr.x = t2->x;
// 	// ptr.y = t2->y;
// 	// ptr.x0 = t1->x;
// 	// ptr.y0 = t1->y;
// 	printf("(%d, %d) -> (%d, %d)\n", ptr.x0, ptr.y0, ptr.x, ptr.y);
// 	ptr.x0 = 424;
// 	ptr.y0 = 641;
// 	ptr.x = 404;
// 	ptr.y = 677;
// 	if (ptr.x0 > ptr.x)
// 	{
// 		ptr.i = ptr.x0;
// 		ptr.x0 = ptr.x;
// 		ptr.x = ptr.i;
// 	}
// 	if (ptr.y0 > ptr.y)
// 	{
// 		ptr.i = ptr.y0;
// 		ptr.y0 = ptr.y;
// 		ptr.y = ptr.i;
// 	}
//     ptr.error = 0;
// 	if (abs(ptr.x - ptr.x0) > abs(ptr.y - ptr.y0))
// 		drawHorizontalLines(pr, ptr);
// 	else
// 		drawVerticalLines(pr, ptr);
// }


void	line_y(t_mlx pr, t_line ptr)
{
	float tmp;
	float er = 0;
	float opt;
	int dl;
	float c2;

	c2 = (ptr.z > ptr.z0) ? (ptr.z0 - pr.zmn) : (ptr.z - pr.zmn);
	tmp = fabsf(ptr.x - ptr.x0) / fabsf(ptr.y - ptr.y0);
	if (ptr.x0 > ptr.x)
		opt = -1;
	else
		opt = 1;
	while (ptr.y0 <= ptr.y)
	{
		if (ptr.y0 < HEIGHT && ptr.y0 >= 0 && ptr.x0 < WIDTH && ptr.x0 >= 0)
			pr.pix_m[(int)ptr.y0 * WIDTH + (int)ptr.x0 + 1] = pr.color1 - (pr.g) * (pr.zmx - ptr.z);
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
	float er = 0;
	float opt;
	int dl;
	float c2;

	c2 = (ptr.z > ptr.z0) ? (ptr.z0 - pr.zmn) : (ptr.z - pr.zmn);
	tmp = fabsf(ptr.y - ptr.y0) / fabsf(ptr.x - ptr.x0);
	if (ptr.y0 > ptr.y)
		opt = -1;
	else
		opt = 1;
	while (ptr.x0 <= ptr.x)
	{
		if (ptr.x0 < HEIGHT && ptr.x0 >= 0 && ptr.y0 < WIDTH && ptr.y0 >= 0)
			pr.pix_m[(int)ptr.y0 * WIDTH + (int)ptr.x0 + 1] = pr.color1 - (pr.g) * (pr.zmx - ptr.z);
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

	ptr.x0 = (float)(t1->x) + 300;
	ptr.x = (float)(t2->x) + 300;
	ptr.y0 = (float)(t1->y) + 300;
	ptr.y = (float)(t2->y) + 300;
	ptr.z = (float)(t2->z);
	// printf();
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