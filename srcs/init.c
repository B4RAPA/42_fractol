/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 08:39:46 by lfabel            #+#    #+#             */
/*   Updated: 2024/09/18 12:20:22 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init(t_vars *fract)
{
	fract->fractal = 0;
	fract->iter = 0;
	fract->shift_x = -2;
	fract->shift_y = -2;
	fract->zoom = 300;
	fract->zoom_lvl = 1.42;
	fract->x = 0;
	fract->y = 0;
}

void	init_julia(t_vars *fract, char **argv)
{
	fract->a_julia = ft_atof(argv[2]);
	fract->b_julia = ft_atof(argv[3]);
}

void	init_mlx(t_vars *fract)
{
	fract->mlx = mlx_init();
	fract->win = mlx_new_window(fract->mlx, WIDTH, HEIGHT, "Fract-ol");
	fract->img = NULL;
	fract->img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
	fract->image_pointer = mlx_get_data_addr(fract->img,
			&fract->bits_per_pixel,
			&fract->line_size, &fract->endian);
}
