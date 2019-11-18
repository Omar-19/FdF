# include "../includes/header.h"

void	drawHorizontalLines(t_mlx ptr)
{
	ptr.delt = (double)abs(ptr.y - ptr.y0) / (double)abs(ptr.x - ptr.x0);
    ptr.dir_y = ptr.y - ptr.y0;
    if (ptr.dir_y > 0)
		ptr.dir_y = 1;
    if (ptr.dir_y < 0) 
		ptr.dir_y = -1;
	while(ptr.x0 <= ptr.x)
	{
		ptr.pix_m[ptr.y0 * WIDTH + ptr.x0] = ptr.color;
        ptr.error = ptr.error + ptr.delt;
        if (ptr.error >= 0.5)
		{
			ptr.y0 = ptr.y0 + ptr.dir_y;
            ptr.error = ptr.error - 1.0;
		}
		++(ptr.x0);
	}
}

void	drawVerticalLines(t_mlx ptr)
{
	ptr.delt = (double)abs(ptr.x - ptr.x0) / (double)abs(ptr.y - ptr.y0);
    ptr.dir_x = ptr.x - ptr.x0;
    if (ptr.dir_x > 0)
		ptr.dir_x = 1;
    if (ptr.dir_x < 0) 
		ptr.dir_x = -1;
	while(ptr.y0 <= ptr.y)
	{
		ptr.pix_m[ptr.y0 * WIDTH + ptr.x0] = ptr.color;
        ptr.error = ptr.error + ptr.delt;
        if (ptr.error >= 0.5)
		{
			ptr.x0 = ptr.x0 + ptr.dir_x;
            ptr.error = ptr.error - 1.0;
		}
		++(ptr.y0);
	}
}

void	paint_lines(t_mlx ptr, int i)
{
	(i == -1) ? (ptr.x = ptr.x0) : 0;
	(i == 0) ? (ptr.y = ptr.y0) : 0;
	if (ptr.x0 > ptr.x)
	{
		ptr.i = ptr.x0;
		ptr.x0 = ptr.x;
		ptr.x = ptr.i;
	}
	if (ptr.y0 > ptr.y)
	{
		ptr.i = ptr.y0;
		ptr.y0 = ptr.y;
		ptr.y = ptr.i;
	}

    ptr.error = 0;
	if (abs(ptr.x - ptr.x0) > abs(ptr.y - ptr.y0))
		drawHorizontalLines(ptr);
	else
		drawVerticalLines(ptr);
}