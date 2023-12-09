/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbelfatm <wbelfatm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:07:28 by wbelfatm          #+#    #+#             */
/*   Updated: 2023/12/09 18:04:56 by wbelfatm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

double	fit_range(double t, t_config *config, char op)
{
	double	old_min;
	double	old_max;
	double	new_min;
	double	new_max;

	old_min = config->width - 1;
	old_max = 0;
	new_min = -config->h_boundary * config->zoom;
	new_max = config->h_boundary * config->zoom;
	if (op == 'h')
	{
		old_min = 0;
		old_max = config->height - 1;
		new_min = -config->v_boundary * config->zoom;
		new_max = config->v_boundary * config->zoom;
	}
	else if (op == 's')
	{
		old_min = config->height - 1;
		old_max = 0;
	}
	return (new_min + ((new_max - new_min) / (old_min - old_max))
		* (t - old_min));
}
