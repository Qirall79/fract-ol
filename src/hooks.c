/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbelfatm <wbelfatm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:07:28 by wbelfatm          #+#    #+#             */
/*   Updated: 2023/12/08 16:07:37 by wbelfatm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_move(mlx_key_data_t key_data, t_config *config)
{
	if (key_data.key == MLX_KEY_DOWN)
		config->offset_y += 0.05 * config->zoom;
	else if (key_data.key == MLX_KEY_UP)
		config->offset_y -= 0.05 * config->zoom;
	else if (key_data.key == MLX_KEY_RIGHT)
		config->offset_x += 0.05 * config->zoom;
	else if (key_data.key == MLX_KEY_LEFT)
		config->offset_x -= 0.05 * config->zoom;
	else if (key_data.key == MLX_KEY_SPACE)
	{
		config->zoom = 1;
		config->offset_x = 4;
		config->offset_y = 4;
	}
	else if (key_data.key == MLX_KEY_ESCAPE)
		return (ft_close(config));
	else
		return ;
	redraw_fractal(config);
}

void	ft_resize(int32_t width, int32_t height, t_config *config)
{
	config->width = (double)width;
	config->height = (double)height;
	redraw_fractal(config);
}

void	ft_scroll(double xdelta, double ydelta, t_config *config)
{
	int32_t	tmp_x;
	int32_t	tmp_y;
	double	mouse_x_before;
	double	mouse_y_before;

	tmp_x = 0;
	tmp_y = 0;
	mouse_x_before = 0;
	mouse_y_before = 0;
	xdelta *= 1;
	mlx_get_mouse_pos(config->mlx, &tmp_x, &tmp_y);
	mouse_x_before = fit_range((double) tmp_x, config, 'w');
	mouse_y_before = fit_range((double) tmp_y, config, 'h');
	if (ydelta < 0)
		config->zoom *= 0.97;
	else
		config->zoom *= 1.03;
	config->offset_x += mouse_x_before
		- (fit_range((double) tmp_x, config, 'w'));
	config->offset_y += mouse_y_before
		- (fit_range((double) tmp_y, config, 'h'));
	redraw_fractal(config);
}
