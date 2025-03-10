/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 08:25:03 by lfabel            #+#    #+#             */
/*   Updated: 2024/09/18 13:44:30 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
// # include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include "libft/libft.h"

# define ESC 65307
# define UP	65362
# define DOWN 65364
# define RIGHT 65363
# define LEFT 65361
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define HEIGHT 700
# define WIDTH 700
# define BASE_ITER_MAX 8.76

typedef struct fract
{
	void	*mlx;
	void	*win;
	void	*img;
	int		fractal;
	double	zoom;
	double	shift_x;
	double	shift_y;
	void	*image_pointer;
	int		x;
	int		y;
	int		color;
	int		iter;
	double	a_julia;
	double	b_julia;
	int		line_size;
	int		bits_per_pixel;
	int		endian;
	int		max_iter;
	double	zoom_lvl;
}				t_vars;

// typedef struct vars
// {
// 	double	result;
// 	double	negativ;
// 	double	divisor;
// 	bool	infraction;	
// 	double	intpart;
// }				t_variables;

typedef struct var
{
	double	num;
	int		exponent;
	int		i;
	int		negative;
}				t_var;				

void	draw_mandel(t_vars *fract);
void	draw_julia(t_vars *fract);
void	draw_burning_ship(t_vars *fract);
void	print(t_vars *fract, int x, int y, int iter);
int		color_map(int iter);

void	mandelbrot(t_vars *fract);
void	julia(t_vars *fract);
void	burning_ship(t_vars *fract);

void	init(t_vars *fract);
void	init_julia(t_vars *fract, char **argv);
void	init_mlx(t_vars *fract);

int		read_mouse(int button, int mouse_x, int mouse_y, t_vars *fract);
int		read_keys(int key_pressed, t_vars *fract);
int		exit_programm(t_vars *fract);
int		move_arrows(t_vars *fract, int button);

int		ft_strcmp(char *s1, char *s2);
double	ft_atof(const char *str);
void	error(void);
int		ft_input(int c);

#endif