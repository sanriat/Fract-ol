/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damoncad <damoncad@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-22 16:57:39 by damoncad          #+#    #+#             */
/*   Updated: 2024-04-22 16:57:39 by damoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	is_mandelbrot(t_fractol *fractol)
{
	fractol->i = 0;
	while (fractol->i < WIN_SIZE)
	{
		fractol->j = 0;
		while (fractol->j < WIN_SIZE)
		{
			fractol->n = 0;
			fractol->real = 0;
			fractol->immag = 0;
			if (fractol->n < MAX_ITER)
				color_set(fractol);
			fractol->j++;
		}
		fractol->i++;
	}
}

void	is_burning_ship(t_fractol *fractol)
{
	fractol->i = 0;
	while (fractol->i < WIN_SIZE)
	{
		fractol->j = 0;
		while (fractol->j < WIN_SIZE)
		{
			fractol->n = 0;
			fractol->real = 0;
			fractol->immag = 0;
			if (fractol->n < MAX_ITER)
				color_set1(fractol);
			fractol->j++;
		}
		fractol->i++;
	}
}

void	is_julia(char *av, t_fractol *fractol)
{
	fractol->i = 0;
	while (fractol->i < WIN_SIZE)
	{
		fractol->j = 0;
		while (fractol->j < WIN_SIZE)
		{
			fractol->n = 0;
			fractol->real = (fractol->i - WIN_SIZE / 2.0)
				* (fractol->zoom / WIN_SIZE) + fractol->x;
			fractol->immag = (fractol->j - WIN_SIZE / 2.0)
				* (fractol->zoom / WIN_SIZE) + fractol->y;
			if (fractol->n < MAX_ITER)
				color_set2(fractol);
			fractol->j++;
		}
		fractol->i++;
	}
}
