/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 08:28:36 by lfabel            #+#    #+#             */
/*   Updated: 2024/09/18 11:06:05 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mandelbrot(t_vars *fract)
{
	double	a;
	double	b;
	double	temp;
	double	real;
	double	imagin;

	a = (fract->x / fract->zoom) + fract->shift_x;
	b = (fract->y / fract->zoom) + fract->shift_y;
	real = 0.0;
	imagin = 0.0;
	fract->iter = 0;
	fract->max_iter = BASE_ITER_MAX * log(fract->zoom);
	while (fract->iter < fract->max_iter
		&& (real * real + imagin * imagin) <= 4.0)
	{
		temp = real * real - imagin * imagin + a;
		imagin = 2 * real * imagin + b;
		real = temp;
		fract->iter++;
	}
	print (fract, fract->x, fract->y, fract->iter);
}
