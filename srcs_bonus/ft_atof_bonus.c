/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:37:32 by lfabel            #+#    #+#             */
/*   Updated: 2024/09/18 13:26:15 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	ft_atof(const char *str)
{
	t_var	var;

	var.i = 0;
	var.num = 0.0;
	var.exponent = 0;
	var.negative = 0;
	if (str[var.i] == '-')
		var.negative = ++var.i;
	while (str[var.i] && ft_input(str[var.i]) == 1)
		var.num = var.num * 10.0 + (str[var.i++] - '0');
	if (str[var.i] == '.')
	{
		var.i++;
		while (str[var.i] && ft_input(str[var.i]) == 1)
		{
			var.num = var.num * 10.0 + (str[var.i++] - '0');
			var.exponent--;
		}
	}
	while (var.exponent++ < 0)
		var.num /= 10;
	if (var.negative)
		var.num = -var.num;
	return (var.num);
}

int	ft_input(int c)
{
	if (!(c >= 48 && c <= 57))
	{
		if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		{
			ft_putstr_fd("Arguments are no numbers", 2);
			exit (EXIT_FAILURE);
		}
		else if (c != '.')
		{
			ft_putstr_fd("Arguments are no numbers", 2);
			exit (EXIT_FAILURE);
		}
		return (0);
	}
	return (1);
}
