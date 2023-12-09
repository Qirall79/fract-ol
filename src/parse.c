/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbelfatm <wbelfatm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:38:47 by wbelfatm          #+#    #+#             */
/*   Updated: 2023/12/09 18:33:55 by wbelfatm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atod(char *s)
{
	int		sign;
	int		places;
	int		i;
	double	result;

	sign = 1;
	places = 0;
	result = 0;
	i = -1;
	if (s[0] == '-')
	{
		sign *= -1;
		i++;
	}
	while (s[++i] && (s[i] >= '0' && s[i] <= '9'))
		result = result * 10 + s[i] - 48;
	if (s[i] == '.')
		i++;
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
	{
		result = result * 10 + s[i++] - 48;
		places++;
	}
	return ((result / pow(10, places) * sign));
}

static int	is_valid_double(char *s)
{
	int	points;
	int	i;

	i = -1;
	points = 0;
	if (s[0] == '-')
		i++;
	while (s[++i] && ((s[i] == '.') || (s[i] <= '9' && s[i] >= '0')))
	{
		if (s[i] == '.')
			points++;
		if (points > 1)
			return (0);
	}
	if ((s[i] && !(s[i] <= '9' && s[i] >= '0'))
		|| i > 16 || !i)
		return (0);
	return (1);
}

int	ft_verify_args(int argc, char **argv)
{
	if (argc == 2 && (!ft_strcmp(argv[1], "mandelbrot")
			|| !ft_strcmp(argv[1], "Mandelbrot")))
		return (1);
	if (argc == 2 && (!ft_strcmp(argv[1], "tricorn")
			|| !ft_strcmp(argv[1], "Tricorn")))
		return (1);
	if (argc == 2 && (!ft_strcmp(argv[1], "ship")
			|| !ft_strcmp(argv[1], "Ship")))
		return (1);
	if (argc == 2 && (!ft_strcmp(argv[1], "julia")
			|| !ft_strcmp(argv[1], "Julia")))
		return (1);
	if (argc == 4 && (!ft_strcmp(argv[1], "julia")
			|| !ft_strcmp(argv[1], "Julia"))
		&& is_valid_double(argv[2])
		&& is_valid_double(argv[3]))
		return (1);
	return (0);
}
