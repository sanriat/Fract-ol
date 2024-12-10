/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damoncad <damoncad@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-09 16:15:38 by damoncad          #+#    #+#             */
/*   Updated: 2024-05-09 16:15:38 by damoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	help_color(double t, int *r, int *g, int *b)
{
	if (t < 0.5)
	{
		*r = 255;
		*g = (int)(255 * (1 - 2 * t));
		*b = 255;
	}
	else if (t < 0.66)
	{
		*r = 0;
		*g = (int)(255 * (2 * t - 1));
		*b = 0;
	}
	else
	{
		*r = 0;
		*g = 255;
		*b = (int)(255 * (3 * (t - 0.66)));
	}
}

int	get_color(int iterations, int max_iterations)
{
	double	t;
	int		r;
	int		g;
	int		b;

	r = 0;
	g = 0;
	b = 0;
	t = (double)iterations / (double)max_iterations;
	help_color(t, &r, &g, &b);
	return ((r << 16) | (g << 8) | b);
}

void	help_color1(double t, int *r, int *g, int *b)
{
	if (t < 0.5)
	{
		*r = (int)(255 * (2 - 4 * t));
		*g = 255;
		*b = 0;
	}
	else if (t < 0.75)
	{
		*r = 0;
		*g = 255;
		*b = (int)(255 * 4 * (t - 0.5));
	}
	else
	{
		*r = 0;
		*g = (int)(255 * (2 - 4 * (t - 0.75)));
		*b = 255;
	}
}

int	get_color1(int iterations, int max_iterations)
{
	double	t;
	int		r;
	int		g;
	int		b;

	r = 0;
	g = 0;
	b = 0;
	t = (double)iterations / (double)max_iterations;
	if (t < 0.25)
	{
		r = 255;
		g = (int)(255 * 4 * t);
		b = 0;
	}
	else
		help_color1(t, &r, &g, &b);
	return ((r << 16) | (g << 8) | b);
}
