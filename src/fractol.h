/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbelfatm <wbelfatm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:30:16 by wbelfatm          #+#    #+#             */
/*   Updated: 2023/12/08 15:43:39 by wbelfatm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>

# define WIDTH 720.0
# define HEIGHT 720.0
# define MAX_ITERATIONS 40.0

typedef struct s_config
{
	char		*name;
	double		width;
	double		height;
	mlx_t		*mlx;
	mlx_image_t	*img;
	double		h_boundary;
	double		v_boundary;
	double		zoom;
	double		offset_x;
	double		offset_y;
	double		min_color;
	double		max_color;
	int			(*f)(double, double);
	int			(*f_julia)(double, double, double, double);
	double		julia_x;
	double		julia_y;
}	t_config;

void	draw_fractal(t_config *config);
void	redraw_fractal(t_config *config);
int		ft_strcmp(const char *s1, const char *s2);
double	fit_range(double t, t_config *config, char op);
int		in_set_mandelbrot(double x, double y);
int		in_set_tricorn(double x, double y);
int		in_set_julia(double x, double y, double p, double q);
int		in_set_ship(double x, double y);
void	ft_move(mlx_key_data_t key_data, t_config *config);
void	ft_scroll(double xdelta, double ydelta, t_config *config);
void	ft_resize(int32_t width, int32_t height, t_config *config);
void	ft_close(t_config *config);
int		ft_verify_args(int argc, char **argv);
double	ft_atod(char *s);
void	init_hooks(t_config *config);
void	init_set_func(t_config *config);
void	init_config(t_config *config, char *name);

#endif