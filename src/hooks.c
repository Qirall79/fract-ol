/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbelfatm <wbelfatm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:07:28 by wbelfatm          #+#    #+#             */
/*   Updated: 2023/12/09 20:27:11 by wbelfatm         ###   ########.fr       */
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
	char	action;

	xdelta *= 1;
	action = 'h';
	if (!ft_strcmp(config->name, "ship"))
		action = 's';
	mlx_get_mouse_pos(config->mlx, &tmp_x, &tmp_y);
	mouse_x_before = fit_range((double) tmp_x, config, 'w');
	mouse_y_before = fit_range((double) tmp_y, config, action);
	if (ydelta < 0)
		config->zoom *= 0.97;
	else
		config->zoom *= 1.03;
	config->offset_x += mouse_x_before
		- (fit_range((double) tmp_x, config, 'w'));
	config->offset_y += mouse_y_before
		- (fit_range((double) tmp_y, config, action));
	redraw_fractal(config);
}

void	ft_mouse(mouse_key_t button, action_t action,
		modifier_key_t mods, t_config *config)
{
	(void)mods;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
	{
		config->color++;
		if (config->color == 6)
			config->color = 0;
	}
	redraw_fractal(config);
}

void	ft_cursor(double xpos, double ypos, t_config *config)
{
	config->julia_x = xpos / config->width;
	config->julia_y = ypos / config->height;
	redraw_fractal(config);
}
