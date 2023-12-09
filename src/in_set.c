/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbelfatm <wbelfatm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:07:20 by wbelfatm          #+#    #+#             */
/*   Updated: 2023/12/09 17:03:05 by wbelfatm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	in_set_mandelbrot(double x, double y, t_config *config)
{
	int		i;
	double	a;
	double	b;
	double	tmp;

	i = 0;
	a = x;
	b = y;
	while (a * a + b * b <= 4 && i < config->max_iterations)
	{
		tmp = a * a - b * b + x;
		b = 2 * a * b + y;
		a = tmp;
		i++;
	}
	return (i);
}

int	in_set_tricorn(double x, double y, t_config *config)
{
	int		i;
	double	a;
	double	b;
	double	tmp;

	i = 0;
	a = x;
	b = y;
	while (a * a + b * b <= 4 && i < config->max_iterations)
	{
		tmp = a * a - b * b + x;
		b = -2 * a * b + y;
		a = tmp;
		i++;
	}
	return (i);
}

int	in_set_julia(double x, double y, t_config *config)
{
	int		i;
	double	a;
	double	b;
	double	tmp;

	i = 0;
	a = x;
	b = y;
	while (a * a + b * b <= 4 && i < config->max_iterations)
	{
		tmp = a * a - b * b + config->julia_x;
		b = 2 * a * b + config->julia_y;
		a = tmp;
		i++;
	}
	return (i);
}

int	in_set_ship(double x, double y, t_config *config)
{
	int		i;
	double	a;
	double	b;
	double	tmp;

	i = 0;
	a = x;
	b = y;
	while (a * a + b * b <= 4 && i < config->max_iterations)
	{
		tmp = fabs(a * a - b * b + x);
		b = fabs(2 * a * b + y);
		a = tmp;
		i++;
	}
	return (i);
}
