/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbelfatm <wbelfatm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:11:33 by wbelfatm          #+#    #+#             */
/*   Updated: 2024/01/17 15:27:30 by wbelfatm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	create_rgbt(int t, int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | t);
}

uint32_t	handle_color(int i, int color, double iterations)
{
	if (color == 0)
		return (get_color_0(i, iterations));
	if (color == 1)
		return (get_color_1(i, iterations));
	if (color == 2)
		return (get_color_2(i, iterations));
	if (color == 3)
		return (get_color_3(i, iterations));
	if (color == 4)
		return (get_color_4(i, iterations));
	return (get_color_5(i, iterations));
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
			if (!ft_strcmp(config->name, "ship")
				|| !ft_strcmp(config->name, "Ship"))
				mapped_y = (fit_range((double)y, config, 's')
						+ config->offset_y);
			color = handle_color((config->f)(mapped_x, mapped_y, config),
					config->color, config->max_iterations);
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
		exit(EXIT_FAILURE);
	config->img = img;
	draw_fractal(config);
}
