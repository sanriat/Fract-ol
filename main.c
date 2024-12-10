/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damoncad <damoncad@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-22 15:42:02 by damoncad          #+#    #+#             */
/*   Updated: 2024-04-22 15:42:02 by damoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	window_init(t_fractol *fractol)
{
	fractol->ptr = mlx_init();
	if (fractol->ptr == NULL)
		exit (ft_putstr("Malloc error\n"));
	fractol->win = mlx_new_window(fractol->ptr, WIN_SIZE, WIN_SIZE, "Fractol");
	if (fractol->win == NULL)
	{
		exit_when_close(fractol);
		exit (ft_putstr("Malloc error\n"));
	}
	fractol->img = mlx_new_image(fractol->ptr, WIN_SIZE, WIN_SIZE);
	if (fractol->img == NULL)
	{
		exit_when_close(fractol);
		exit (ft_putstr("Malloc error\n"));
	}
	fractol->addr = mlx_get_data_addr(fractol->img, &fractol->bits_per_pixel,
			&fractol->line_length, &fractol->endian);
}

int	available_fractals(char **av)
{
	if (ft_strcmp(av[1], "Mandelbrot") == 0)
		return (0);
	if (ft_strcmp(av[1], "Julia") == 0)
		return (0);
	if (ft_strcmp(av[1], "Burning_ship") == 0)
		return (0);
	return (1);
}

void	choose_fractal(char *av, t_fractol *fractol)
{
	if (!ft_strcmp(av, "Julia"))
	{
		is_julia(av, fractol);
		fractol->fractal = ft_strdup(av);
	}
	else if (!ft_strcmp(av, "Mandelbrot"))
	{
		is_mandelbrot(fractol);
		fractol->fractal = ft_strdup("Mandelbrot");
	}
	else if (!ft_strcmp(av, "Burning_ship"))
	{
		is_burning_ship(fractol);
		fractol->fractal = ft_strdup("Burning_ship");
	}
	mlx_put_image_to_window(fractol->ptr, fractol->win, fractol->img, 0, 0);
}

void	events(t_fractol *fractol)
{
	mlx_key_hook(fractol->win, arrow_move, fractol);
	mlx_hook(fractol->win, 17, 0, exit_when_close, fractol);
	mlx_mouse_hook(fractol->win, zoom, fractol);
}

int	main(int ac, char **av)
{
	t_fractol	*fractol;

	check(ac, av);
	fractol = malloc(sizeof(t_fractol));
	if (!fractol)
		exit (ft_putstr("Malloc error\n"));
	if (!(check_chars(av, ac)))
		return (hehe(ac, av, fractol));
	data_init(fractol);
	if (ft_strcmp(av[1], "Julia") == 0)
	{
		fractol->c_real = ft_atod(av[2]);
		fractol->c_immag = ft_atod(av[3]);
		if (fractol->c_real < -2 || (fractol->c_real > 2)
			|| fractol->c_immag < -2 || fractol->c_immag > 2)
		{
			free(fractol);
			exit(ft_error(2));
		}
	}
	window_init(fractol);
	choose_fractal(av[1], fractol);
	events(fractol);
	mlx_loop(fractol->ptr);
	return (0);
}
