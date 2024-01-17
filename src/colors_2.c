/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbelfatm <wbelfatm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:28:47 by wbelfatm          #+#    #+#             */
/*   Updated: 2024/01/17 15:28:51 by wbelfatm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	get_color_5(int i, double iterations)
{
	uint32_t	result;

	result = ((255 - (i / iterations) * (255))
			/ (log(i / iterations + 0.1)));
	return (create_rgbt(255, result * cos(result),
			result * tan(result), result * atan(result)));
}
