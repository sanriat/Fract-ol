/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_fractals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damoncad <damoncad@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-22 17:11:21 by damoncad          #+#    #+#             */
/*   Updated: 2024-04-22 17:11:21 by damoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iterate_mandelbrot(t_fractol *fractol)
{
	fractol->c_real = (fractol->i - WIN_SIZE / 2.0) * fractol->zoom
		/ WIN_SIZE + fractol->x;
	fractol->c_immag = (fractol->j - WIN_SIZE / 2.0) * fractol->zoom
		/ WIN_SIZE + fractol->y;
	while (fractol->n < MAX_ITER && fractol->real * fractol->real
		+ fractol->immag * fractol->immag < 4)
	{
		fractol->temp = fractol->real * fractol->real - fractol->immag
			* fractol->immag + fractol->c_real;
		fractol->immag = 2 * fractol->real * fractol->immag + fractol->c_immag;
		fractol->real = fractol->temp;
		fractol->n++;
	}
	return (fractol->n);
}

int	iterate_ship(t_fractol *fractol)
{
	fractol->c_real = (fractol->i - WIN_SIZE / 2.0) * fractol->zoom
		/ WIN_SIZE + fractol->x;
	fractol->c_immag = (fractol->j - WIN_SIZE / 2.0) * fractol->zoom
		/ WIN_SIZE + fractol->y;
	while (fractol->n < MAX_ITER && fractol->real * fractol->real
		+ fractol->immag * fractol->immag < 4)
	{
		fractol->temp = fractol->real * fractol->real - fractol->immag
			* fractol->immag + fractol->c_real;
		fractol->immag = fabs(2 * fractol->real * fractol->immag)
			+ fractol->c_immag;
		fractol->real = fractol->temp;
		fractol->n++;
	}
	return (fractol->n);
}

int	iterate_julia(t_fractol *fractol)
{
	while (fractol->n < MAX_ITER && fractol->real * fractol->real
		+ fractol->immag * fractol->immag < 4)
	{
		fractol->temp = fractol->real * fractol->real - fractol->immag
			* fractol->immag;
		fractol->immag = 2 * fractol->real * fractol->immag + fractol->c_real;
		fractol->real = fractol->temp + fractol->c_immag;
		fractol->n++;
	}
	return (fractol->n);
}
