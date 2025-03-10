/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 08:50:18 by lfabel            #+#    #+#             */
/*   Updated: 2024/09/18 13:53:49 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	check_input(char **argv, int argc)
{
	if (argc != 2 && argc != 4)
	{
		ft_putstr_fd("incorrect amount of arguments\n", 1);
		if (!argv[1])
		{
			error();
		}
	}
	if (ft_strcmp(argv[1], "julia") != 0
		&& ft_strcmp(argv[1], "mandel") != 0
		&& ft_strcmp(argv[1], "burning") != 0)
		error();
	if (ft_strcmp(argv[1], "julia") == 0 && argc != 4)
		error();
	if (ft_strcmp(argv[1], "mandel") == 0 && argc != 2)
		error();
	if (ft_strcmp(argv[1], "burning") == 0 && argc != 2)
		error();
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	*fract;

	if (check_input(argv, argc) == -1)
		return (0);
	fract = malloc(sizeof(t_vars));
	if (!fract)
		return (-1);
	init_mlx(fract);
	init(fract);
	if (argc == 4)
		init_julia(fract, argv);
	mlx_mouse_hook(fract->win, read_mouse, fract);
	mlx_key_hook(fract->win, read_keys, fract);
	mlx_hook(fract->win, 17, 0, exit_programm, fract);
	if (ft_strcmp(argv[1], "julia") == 0)
		draw_julia(fract);
	else if (ft_strcmp(argv[1], "mandel") == 0)
		draw_mandel(fract);
	else if (ft_strcmp(argv[1], "burning") == 0)
	{
		fract->fractal = 2;
		draw_burning_ship(fract);
	}
	mlx_loop(fract->mlx);
	return (0);
}
