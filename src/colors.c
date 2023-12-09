/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbelfatm <wbelfatm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:24:20 by wbelfatm          #+#    #+#             */
/*   Updated: 2023/12/09 18:32:29 by wbelfatm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	get_color_0(int i)
{
	uint32_t	result;

	result = 255 * i / MAX_ITERATIONS;
	return create_rgbt(255, result, result, result);
}

uint32_t	get_color_1(int i)
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;

	r = (255 - i / MAX_ITERATIONS * 255);
	g = (255 - i / MAX_ITERATIONS * 255);
	b = (255- i / MAX_ITERATIONS * 255);
	return create_rgbt(255, r, g, b);
}

uint32_t	get_color_2(int i)
{
	uint32_t	result;

	result = ((255 - (i / MAX_ITERATIONS) * (255))
        / (cos(i / MAX_ITERATIONS)
            * sin(i / MAX_ITERATIONS)
            * tan(i / MAX_ITERATIONS)));
	return create_rgbt(255, 0, 0, result);
}

uint32_t	get_color_3(int i)
{
	uint32_t	result;

	result = ((255 - (i / MAX_ITERATIONS) * (255))
        / (cos(i / MAX_ITERATIONS)
            * sin(i / MAX_ITERATIONS)
            * tan(i / MAX_ITERATIONS)));
	return create_rgbt(255, 0, result, 0);
}

uint32_t	get_color_4(int i)
{
	uint32_t	result;

	result = ((255 - (i / MAX_ITERATIONS) * (255))
        / (cos(i / MAX_ITERATIONS)
            * sin(i / MAX_ITERATIONS)
            * tan(i / MAX_ITERATIONS)));
	return create_rgbt(255, result, 0, 0);
}

uint32_t	get_color_5(int i)
{
	uint32_t	result;

	result = ((255 - (i / MAX_ITERATIONS) * (255))
        / (log(i / MAX_ITERATIONS + 0.1)));
	return create_rgbt(255, result * cos(result), result * tan(result), result * atan(result));
}


