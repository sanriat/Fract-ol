/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damoncad <damoncad@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-22 16:36:29 by damoncad          #+#    #+#             */
/*   Updated: 2024-04-22 16:36:29 by damoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_when_close(t_fractol *fractol)
{
	mlx_destroy_image(fractol->ptr, fractol->img);
	mlx_destroy_window(fractol->ptr, fractol->win);
	mlx_destroy_display(fractol->ptr);
	free(fractol->ptr);
	free(fractol->fractal);
	free(fractol);
	ft_putstr("Closed window!\n");
	exit (EXIT_SUCCESS);
}

int	arrow_move_helper(int keycode, t_fractol *fractol)
{
	if (keycode == RESET)
	{
		fractol->x = 0;
		fractol->y = 0;
		fractol->zoom = 4.0;
	}
	if (keycode == COLOR_UP)
	{
		fractol->color = 0;
	}
	if (keycode == COLOR_DOWN)
	{
		fractol->color = 2;
	}
	return (0);
}

int	arrow_move(int keycode, t_fractol *fractol)
{
	if (keycode == ESC)
		exit_when_close(fractol);
	if (keycode == LEFT)
		fractol->x -= (0.1 * fractol->zoom);
	if (keycode == RIGHT)
		fractol->x += (0.1 * fractol->zoom);
	if (keycode == UP)
		fractol->y -= (0.1 * fractol->zoom);
	if (keycode == DOWN)
		fractol->y += (0.1 * fractol->zoom);
	arrow_move_helper(keycode, fractol);
	mlx_clear_window(fractol->ptr, fractol->win);
	if (!ft_strcmp(fractol->fractal, "Julia"))
		is_julia(fractol->fractal, fractol);
	if (!ft_strcmp(fractol->fractal, "Mandelbrot"))
		is_mandelbrot(fractol);
	if (!ft_strcmp(fractol->fractal, "Burning_ship"))
		is_burning_ship(fractol);
	mlx_put_image_to_window(fractol->ptr, fractol->win, fractol->img,
		fractol->x, fractol->y);
	return (0);
}

int	zoom(int keycode, int x, int y, t_fractol *fractol)
{
	float	prev_zoom;

	prev_zoom = fractol->zoom;
	if (keycode == MOUSE_DOWN)
		fractol->zoom *= 0.8;
	if (keycode == MOUSE_UP)
		fractol->zoom *= 1.25;
	fractol->x += (x - WIN_SIZE / 2) * (prev_zoom - fractol->zoom) / WIN_SIZE;
	fractol->y += (y - WIN_SIZE / 2) * (prev_zoom - fractol->zoom) / WIN_SIZE;
	mlx_clear_window(fractol->ptr, fractol->win);
	if (!ft_strcmp(fractol->fractal, "Julia"))
		is_julia(fractol->fractal, fractol);
	if (!ft_strcmp(fractol->fractal, "Mandelbrot"))
		is_mandelbrot(fractol);
	if (!ft_strcmp(fractol->fractal, "Burning_ship"))
		is_burning_ship(fractol);
	mlx_put_image_to_window(fractol->ptr, fractol->win, fractol->img, 0, 0);
	return (0);
}

void	my_pixel(t_fractol *fractol, int x, int y, int color)
{
	char	*dst;

	dst = fractol->addr + (y * fractol->line_length + x
			* (fractol->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
