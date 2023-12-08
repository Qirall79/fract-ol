/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbelfatm <wbelfatm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:07:20 by wbelfatm          #+#    #+#             */
/*   Updated: 2023/12/08 13:06:18 by wbelfatm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	in_set_mandelbrot(double x, double y)
{
	int		i;
	double	a;
	double	b;
	double	tmp;

	i = 0;
	a = x;
	b = y;
	while (a * a + b * b <= 4 && i < MAX_ITERATIONS)
	{
		tmp = a * a - b * b + x;
		b = 2 * a * b + y;
		a = tmp;
		i++;
	}
	return (i);
}

int	in_set_tricorn(double x, double y)
{
	int		i;
	double	a;
	double	b;
	double	tmp;

	i = 0;
	a = x;
	b = y;
	while (a * a + b * b <= 4 && i < MAX_ITERATIONS)
	{
		tmp = a * a - b * b + x;
		b = -2 * a * b + y;
		a = tmp;
		i++;
	}
	return (i);
}

int	in_set_julia(double x, double y, double p, double q)
{
	int		i;
	double	a;
	double	b;
	double	tmp;

	i = 0;
	a = x;
	b = y;
	while (a * a + b * b <= 4 && i < MAX_ITERATIONS)
	{
		tmp = a * a - b * b + p;
		b = 2 * a * b + q;
		a = tmp;
		i++;
	}
	return (i);
}

int	in_set_ship(double x, double y)
{
	int		i;
	double	a;
	double	b;
	double	tmp;

	i = 0;
	a = x;
	b = y;
	while (a * a + b * b <= 4 && i < MAX_ITERATIONS)
	{
		tmp = fabs(a * a - b * b + x);
		b = fabs(2 * a * b + y);
		a = tmp;
		i++;
	}
	return (i);
}
