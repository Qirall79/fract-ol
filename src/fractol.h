/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbelfatm <wbelfatm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:30:16 by wbelfatm          #+#    #+#             */
/*   Updated: 2023/12/09 20:39:46 by wbelfatm         ###   ########.fr       */
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
# define MAX_ITERATIONS 100.0

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
	int			(*f)(double, double, struct s_config *);
	double		julia_x;
	double		julia_y;
	int			color;
	double		max_iterations;
}	t_config;

void		draw_fractal(t_config *config);
void		redraw_fractal(t_config *config);
int			ft_strcmp(const char *s1, const char *s2);
double		fit_range(double t, t_config *config, char op);
int			in_set_mandelbrot(double x, double y, t_config *config);
int			in_set_tricorn(double x, double y, t_config *config);
int			in_set_julia(double x, double y, t_config *config);
int			in_set_ship(double x, double y, t_config *config);
void		ft_move(mlx_key_data_t key_data, t_config *config);
void		ft_scroll(double xdelta, double ydelta, t_config *config);
void		ft_resize(int32_t width, int32_t height, t_config *config);
void		ft_close(t_config *config);
int			ft_verify_args(int argc, char **argv);
double		ft_atod(char *s);
void		init_hooks(t_config *config);
void		init_set_func(t_config *config);
void		init_config(t_config *config, char *name);
uint32_t	get_color_0(int i);
uint32_t	get_color_1(int i);
uint32_t	get_color_2(int i);
uint32_t	get_color_3(int i);
uint32_t	get_color_4(int i);
uint32_t	get_color_5(int i);
uint32_t	create_rgbt(int t, int r, int g, int b);
void		ft_mouse(mouse_key_t button, action_t action,
				modifier_key_t mods, t_config *config);
void		ft_cursor(double xpos, double ypos, t_config *config);

#endif