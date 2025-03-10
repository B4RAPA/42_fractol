/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 08:39:22 by lfabel            #+#    #+#             */
/*   Updated: 2024/09/18 12:23:16 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	exit_programm(t_vars *fract)
{
	if (fract->img)
		mlx_destroy_image(fract->mlx, fract->img);
	mlx_destroy_window(fract->mlx, fract->win);
	free(fract->mlx);
	free(fract);
	exit (1);
	return (0);
}

int	read_keys(int key_pressed, t_vars *fract)
{
	if (key_pressed == ESC)
		exit_programm(fract);
	return (0);
}

int	read_mouse(int button, int mouse_x, int mouse_y, t_vars *fract)
{
	if (button == 5)
	{
		fract->shift_x = (mouse_x / fract->zoom + fract->shift_x)
			- (mouse_x / (fract->zoom * fract->zoom_lvl));
		fract->shift_y = (mouse_y / fract->zoom + fract->shift_y)
			- (mouse_y / (fract->zoom * fract->zoom_lvl));
		fract->zoom *= fract->zoom_lvl;
	}
	else if (button == 4)
	{
		fract->shift_x = (mouse_x / fract->zoom + fract->shift_x)
			- (mouse_x / (fract->zoom / fract->zoom_lvl));
		fract->shift_y = (mouse_y / fract->zoom + fract->shift_y)
			- (mouse_y / (fract->zoom / fract->zoom_lvl));
		fract->zoom /= fract->zoom_lvl;
	}
	if (fract->fractal == 1)
		draw_julia(fract);
	else if (fract->fractal == 0)
		draw_mandel(fract);
	return (0);
}

void	error(void)
{
	ft_putstr_fd("Choose from: 'mandel','julia' 'num1' 'num 2'", 1);
	exit(EXIT_FAILURE);
}
