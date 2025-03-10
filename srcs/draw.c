/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 08:22:33 by lfabel            #+#    #+#             */
/*   Updated: 2024/09/18 11:06:40 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_mandel(t_vars *fract)
{
	fract->x = 0;
	while (fract->x++ < WIDTH)
	{
		fract->y = 0;
		while (fract->y++ < HEIGHT)
			mandelbrot(fract);
	}
}

void	draw_julia(t_vars *fract)
{
	fract->x = 0;
	while (fract->x++ < WIDTH)
	{
		fract->y = 0;
		while (fract->y++ < HEIGHT)
			julia(fract);
	}
}

void	print(t_vars *fract, int x, int y, int iter)
{
	int	offset;

	if (fract->img == NULL)
	{
		fract->img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
		if (fract->img == NULL)
			return ;
		fract->image_pointer = mlx_get_data_addr(fract->img,
				&fract->bits_per_pixel,
				&fract->line_size, &fract->endian);
		if (fract->image_pointer == NULL)
			return ;
	}
	if (x < WIDTH && y < HEIGHT)
	{
		offset = (y * fract->line_size) + (x * (fract->bits_per_pixel / 8));
		*(int *)(fract->image_pointer + offset) = color_map(iter);
	}
	if (x == WIDTH && y == HEIGHT)
	{
		mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
		mlx_destroy_image(fract->mlx, fract->img);
		fract->img = NULL;
	}
}

int	color_map(int iter)
{
	int	r;
	int	g;
	int	b;

	r = (iter * 9) % 256;
	g = (iter * 9 * 2) % 256;
	b = (iter * 9 * 3) % 256;
	return ((r << 16) | (g << 8) | b);
}
