/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbelfatm <wbelfatm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:24:20 by wbelfatm          #+#    #+#             */
/*   Updated: 2024/01/17 15:28:36 by wbelfatm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	get_color_0(int i, double iterations)
{
	uint32_t	result;

	result = 255 * i / iterations;
	return (create_rgbt(255, result, result, result));
}

uint32_t	get_color_1(int i, double iterations)
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;

	r = (255 - i / iterations * 255);
	g = (255 - i / iterations * 255);
	b = (255 - i / iterations * 255);
	return (create_rgbt(255, r, g, b));
}

uint32_t	get_color_2(int i, double iterations)
{
	uint32_t	result;

	result = ((255 - (i / iterations) * (255))
			/ (cos(i / iterations)
				* sin(i / iterations)
				* tan(i / iterations)));
	return (create_rgbt(255, 0, 0, result));
}

uint32_t	get_color_3(int i, double iterations)
{
	uint32_t	result;

	result = ((255 - (i / iterations) * (255))
			/ (cos(i / iterations)
				* sin(i / iterations)
				* tan(i / iterations)));
	return (create_rgbt(255, 0, result, 0));
}

uint32_t	get_color_4(int i, double iterations)
{
	uint32_t	result;

	result = ((255 - (i / iterations) * (255))
			/ (cos(i / iterations)
				* sin(i / iterations)
				* tan(i / iterations)));
	return (create_rgbt(255, result, 0, 0));
}
