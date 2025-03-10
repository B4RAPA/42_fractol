/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 08:33:26 by lfabel            #+#    #+#             */
/*   Updated: 2024/09/18 13:53:01 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	julia(t_vars *fract)
{
	double	temp;
	double	real;
	double	imagin;

	real = (fract->x / fract->zoom) + fract->shift_x;
	imagin = (fract->y / fract->zoom) + fract->shift_y;
	fract->iter = 0;
	fract->max_iter = BASE_ITER_MAX * log(fract->zoom);
	while (fract->iter++ < fract->max_iter
		&& (real * real + imagin * imagin) <= 4.0)
	{
		temp = real * real - imagin * imagin + fract->a_julia;
		imagin = 2 * real * imagin + fract->b_julia;
		real = temp;
	}
	print (fract, fract->x, fract->y, fract->iter);
}
