/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 08:39:22 by lfabel            #+#    #+#             */
/*   Updated: 2024/09/18 13:17:29 by lfabel           ###   ########.fr       */
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
	if (key_pressed == UP)
		move_arrows(fract, 1);
	if (key_pressed == DOWN)
		move_arrows(fract, 2);
	if (key_pressed == RIGHT)
		move_arrows(fract, 3);
	if (key_pressed == LEFT)
		move_arrows(fract, 4);
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
	if (fract->fractal == 2)
		draw_burning_ship(fract);
	return (0);
}

int	move_arrows(t_vars *fract, int button)
{
	double	move_value;

	move_value = 1.05;
	if (button == 1)
		fract->shift_y = fract->shift_y * move_value;
	else if (button == 2)
		fract->shift_y = fract->shift_y / move_value;
	else if (button == 3)
		fract->shift_x = fract->shift_x / move_value;
	else if (button == 4)
		fract->shift_x = fract->shift_x * move_value;
	if (fract->fractal == 1)
		draw_julia(fract);
	else if (fract->fractal == 0)
		draw_mandel(fract);
	if (fract->fractal == 2)
		draw_burning_ship(fract);
	return (0);
}

void	error(void)
{
	ft_putstr_fd("Choose from: 'mandel','julia' 'num1' 'num2'", 1);
	ft_putstr_fd(", 'burning\n", 1);
	exit (EXIT_FAILURE);
}
