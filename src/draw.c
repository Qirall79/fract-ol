/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbelfatm <wbelfatm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:11:33 by wbelfatm          #+#    #+#             */
/*   Updated: 2023/12/09 15:55:34 by wbelfatm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


uint32_t	create_rgbt(int t, int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | t);
}

uint32_t	get_color(int i)
{
	uint32_t	result;

	
	// result = 255 - (210 + i / MAX_ITERATIONS * 70);

	result = ((255 - (i / MAX_ITERATIONS) * (255))
        / (cos(i / MAX_ITERATIONS)
            * sin(i / MAX_ITERATIONS)
            * tan(i / MAX_ITERATIONS)));
	// result = 255 * i / MAX_ITERATIONS;
	return create_rgbt(255, sin(result), tan(result), result);
}

void	draw_fractal(t_config *config)
{
	uint32_t	color;
	uint32_t	x;
	uint32_t	y;
	double		mapped_x;
	double		mapped_y;

	x = -1;
	while (++x < config->width)
	{
		y = -1;
		while (++y < config->height)
		{
			mapped_x = (fit_range((double)x, config, 'w') + config->offset_x);
			mapped_y = (fit_range((double)y, config, 'h') + config->offset_y);
			color = get_color((config->f)(mapped_x, mapped_y));
			if (!ft_strcmp(config->name, "julia")
				|| !ft_strcmp(config->name, "Julia"))
				color = get_color((config->f_julia)
						(mapped_x, mapped_y, config->julia_x, config->julia_y));
			mlx_put_pixel(config->img, x, y, color);
		}
	}
}

void	redraw_fractal(t_config *config)
{
	mlx_image_t	*img;

	mlx_delete_image(config->mlx, config->img);
	img = mlx_new_image(config->mlx, config->width, config->height);
	if (!img || (mlx_image_to_window(config->mlx, img, 0, 0) < 0))
		return ;
	config->img = img;
	draw_fractal(config);
}
