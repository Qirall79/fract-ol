/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbelfatm <wbelfatm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:28:47 by wbelfatm          #+#    #+#             */
/*   Updated: 2023/12/09 20:38:55 by wbelfatm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	get_color_5(int i)
{
	uint32_t	result;

	result = ((255 - (i / MAX_ITERATIONS) * (255))
			/ (log(i / MAX_ITERATIONS + 0.1)));
	return (create_rgbt(255, result * cos(result),
			result * tan(result), result * atan(result)));
}
