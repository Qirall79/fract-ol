/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbelfatm <wbelfatm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:30:01 by wbelfatm          #+#    #+#             */
/*   Updated: 2023/12/10 09:58:56 by wbelfatm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_close(t_config *config)
{
	mlx_terminate(config->mlx);
	exit(EXIT_SUCCESS);
}

void	ft_putstr(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		write(1, s + i, 1);
}

void	print_error(void)
{
	ft_putstr("Wrong arguments !\n");
	ft_putstr("Usage: ./fractol <fractal_name>");
	ft_putstr(" (the julia set accepts 2 optional (floats) x and y)\n");
}

void	print_header(void)
{
	ft_putstr("Wbelfatm\n");
	ft_putstr("  __                _        _ \n");
	ft_putstr(" / _|              | |      | |\n");
	ft_putstr("| |_ _ __ __ _  ___| |_ ___ | |\n");
	ft_putstr("|  _| '__/ _` |/ __| __/ _ \\| |\n");
	ft_putstr("| | | | | (_| | (__| || (_) | |\n");
	ft_putstr("|_| |_|  \\__,_|\\___|\\__\\___/|_|\n");
}

int	main(int argc, char **argv)
{
	t_config	*config;

	if (!ft_verify_args(argc, argv))
	{
		print_error();
		exit(EXIT_FAILURE);
	}
	config = malloc(sizeof(t_config));
	if (!config)
		exit(EXIT_FAILURE);
	init_config(config, argv[1]);
	if (argc == 4)
	{
		config->julia_x = ft_atod(argv[2]);
		config->julia_y = ft_atod(argv[3]);
		config->julia_default = 0;
	}
	print_header();
	draw_fractal(config);
	init_hooks(config);
	mlx_loop(config->mlx);
	mlx_terminate(config->mlx);
}
