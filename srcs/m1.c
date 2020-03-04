/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m1.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:54:59 by fyuko             #+#    #+#             */
/*   Updated: 2019/11/28 18:55:00 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	create_mlx_img(t_mlx *ptr)
{
	if (ptr->img_ptr)
		mlx_destroy_image(ptr->mlx_ptr, ptr->img_ptr);
	ptr->img_ptr = mlx_new_image(ptr->mlx_ptr, WIDTH, HEIGHT);
	ptr->pix_m = (int *)mlx_get_data_addr(ptr->img_ptr,
		&(ptr->bits_per_pixel), &(ptr->pix_m_size), &(ptr->endian));
	lst_iso(ptr);
	if (abs(*(ptr->z_max)) > abs(*(ptr->z_min)))
		ptr->g = (float)255 / (float)(abs(*(ptr->z_max)) * ptr->size_line);
	else
	{
		if (abs(*(ptr->z_min)) == 0)
			ptr->g = 0;
		else
			ptr->g = (float)255 / (float)(abs(*(ptr->z_min)) * ptr->size_line);
	}
	lst_map_p(ptr);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
}

int		create_image(t_mlx *ptr)
{
	ptr->dx = 0;
	ptr->dy = 0;
	ptr->dz = 0;
	ptr->mlx_ptr = mlx_init();
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, WIDTH, HEIGHT, "FdF project");
	create_mlx_img(ptr);
	mlx_hook(ptr->win_ptr, 2, 0, key_press, ptr);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
	mlx_loop(ptr->mlx_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_ptr);
	return (0);
}
