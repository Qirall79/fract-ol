/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbelfatm <wbelfatm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:42:57 by wbelfatm          #+#    #+#             */
/*   Updated: 2023/12/09 18:40:11 by wbelfatm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_hooks(t_config *config)
{
	mlx_scroll_hook(config->mlx, (mlx_scrollfunc)ft_scroll, config);
	mlx_key_hook(config->mlx, (mlx_keyfunc)ft_move, config);
	mlx_resize_hook(config->mlx, (mlx_resizefunc)ft_resize, config);
	mlx_mouse_hook(config->mlx, (mlx_mousefunc)ft_mouse, config);
	mlx_cursor_hook(config->mlx, (mlx_cursorfunc)ft_cursor, config);
}

void	init_set_func(t_config *config)
{
	config->f = in_set_mandelbrot;
	if (!ft_strcmp(config->name, "tricorn")
		|| !ft_strcmp(config->name, "Tricorn"))
		config->f = in_set_tricorn;
	else if (!ft_strcmp(config->name, "ship")
		|| !ft_strcmp(config->name, "Ship"))
		config->f = in_set_ship;
	else if (!ft_strcmp(config->name, "julia")
		|| !ft_strcmp(config->name, "Julia"))
		config->f = in_set_julia;
}

void	init_config(t_config *config, char *name)
{
	config->name = name;
	config->width = WIDTH;
	config->height = HEIGHT;
	config->mlx = mlx_init(config->width, config->height, config->name, 1);
	config->h_boundary = 2;
	config->v_boundary = 2;
	config->offset_x = 4;
	config->offset_y = 4;
	config->zoom = 1;
	config->color = 0;
	config->max_iterations = MAX_ITERATIONS;
	config->julia_x = 0;
	config->julia_y = 0;
	init_set_func(config);
	if (!config->mlx)
		exit(EXIT_FAILURE);
	config->img = mlx_new_image(config->mlx, config->width, config->height);
	if (!config->img || mlx_image_to_window(config->mlx, config->img, 0, 0) < 0)
		exit(EXIT_FAILURE);
}
