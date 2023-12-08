/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbelfatm <wbelfatm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:30:01 by wbelfatm          #+#    #+#             */
/*   Updated: 2023/12/08 15:54:34 by wbelfatm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_close(t_config *config)
{
	mlx_terminate(config->mlx);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_config	*config;

	if (!ft_verify_args(argc, argv))
	{
		printf("Wrong arguments !\n");
		exit(EXIT_FAILURE);
	}
	config = malloc(sizeof(t_config));
	if (!config)
		exit(EXIT_FAILURE);
	init_config(config, argv[1]);
	if (!ft_strcmp(config->name, "julia") || !ft_strcmp(config->name, "Julia"))
	{
		config->julia_x = ft_atod(argv[2]);
		config->julia_y = ft_atod(argv[3]);
	}
	draw_fractal(config);
	init_hooks(config);
	mlx_loop(config->mlx);
	mlx_terminate(config->mlx);
}
