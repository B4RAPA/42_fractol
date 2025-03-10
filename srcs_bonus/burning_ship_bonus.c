/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:38:29 by lfabel            #+#    #+#             */
/*   Updated: 2024/09/18 13:55:33 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	burning_ship(t_vars *fract)
{
	double	temp;
	double	real;
	double	imagin;
	double	c_real;
	double	c_imagin;

	c_real = (fract->x / fract->zoom) + fract->shift_x;
	c_imagin = (fract->y / fract->zoom) + fract->shift_y;
	real = 0;
	imagin = 0;
	fract->iter = 0;
	fract->max_iter = BASE_ITER_MAX * log(fract->zoom);
	while (fract->iter++ < fract->max_iter
		&& (real * real + imagin * imagin) <= 4.0)
	{
		temp = real * real - imagin * imagin + c_real;
		imagin = fabs(2 * real * imagin) + c_imagin;
		real = temp;
	}
	print(fract, fract->x, fract->y, fract->iter);
}
