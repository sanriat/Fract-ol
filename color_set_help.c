/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_set_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damoncad <damoncad@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-10 08:32:01 by damoncad          #+#    #+#             */
/*   Updated: 2024-05-10 08:32:01 by damoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_set(t_fractol *fractol)
{
	if (fractol->color == 0)
	{
		my_pixel(fractol, fractol->i, fractol->j,
			iterate_mandelbrot(fractol)
			* get_color(fractol->n, MAX_ITER));
	}
	if (fractol->color == 2)
	{
		my_pixel(fractol, fractol->i, fractol->j,
			iterate_mandelbrot(fractol)
			* get_color1(fractol->n, MAX_ITER));
	}
}

void	color_set1(t_fractol *fractol)
{
	if (fractol->color == 0)
	{
		my_pixel(fractol, fractol->i, fractol->j,
			iterate_ship(fractol)
			* get_color(fractol->n, MAX_ITER));
	}
	if (fractol->color == 2)
	{
		my_pixel(fractol, fractol->i, fractol->j,
			iterate_ship(fractol)
			* get_color1(fractol->n, MAX_ITER));
	}
}

void	color_set2(t_fractol *fractol)
{
	if (fractol->color == 0)
	{
		my_pixel(fractol, fractol->i, fractol->j,
			iterate_julia(fractol)
			* get_color(fractol->n, MAX_ITER));
	}
	if (fractol->color == 2)
	{
		my_pixel(fractol, fractol->i, fractol->j,
			iterate_julia(fractol)
			* get_color1(fractol->n, MAX_ITER));
	}
}
