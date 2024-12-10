/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damoncad <damoncad@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-22 15:42:27 by damoncad          #+#    #+#             */
/*   Updated: 2024-04-22 15:42:27 by damoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIN_SIZE 800
# define MAX_ITER 250
# define JULIACHIARO 0xfffdff

# define ESC 65307
# define RESET 114
# define COLOR_UP 111
# define COLOR_DOWN 112
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

# define MOUSE_DOWN 4
# define MOUSE_UP 5

typedef struct s_fractol
{
	void	*ptr;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	zoom;
	char	*fractal;
	double	x;
	double	y;
	double	real;
	double	immag;
	double	temp;
	double	c_real;
	double	c_immag;
	int		j;
	int		n;
	int		i;
	int		color;
}	t_fractol;

//main.c
void	window_init(t_fractol *fractol);
int		available_fractals(char **av);
void	choose_fractal(char *av, t_fractol *fractol);
void	events(t_fractol *fractol);
//event_functions.c
int		exit_when_close(t_fractol *fractol);
int		arrow_move_helper(int keycode, t_fractol *fractol);
int		arrow_move(int keycode, t_fractol *fractol);
int		zoom(int keycode, int x, int y, t_fractol *fractol);
void	my_pixel(t_fractol *fractol, int x, int y, int color);
//utils.c
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
int		ft_putstr(char *str);
void	data_init(t_fractol *fractol);
//fractals.c
void	is_mandelbrot(t_fractol *fractol);
void	is_burning_ship(t_fractol *fractol);
void	is_julia(char *av, t_fractol *fractol);
//iterate_fractals.c
int		iterate_mandelbrot(t_fractol *fractol);
int		iterate_ship(t_fractol *fractol);
int		iterate_julia(t_fractol *fractol);
//help.c
int		check_param(char *str, int i);
void	handle_signs(char *str, int *i, int *neg);
double	ft_atod(char *str);
int		ft_error(int n);
void	check(int ac, char **av);
//color.c
void	help_color(double t, int *r, int *g, int *b);
int		get_color(int iterations, int max_iterations);
void	help_color1(double t, int *r, int *g, int *b);
int		get_color1(int iterations, int max_iterations);
//color_set_help.c
void	color_set(t_fractol *fractol);
void	color_set1(t_fractol *fractol);
void	color_set2(t_fractol *fractol);
//more_utils.c
int		check_chars(char **av, int ac);
int		hehe(int ac, char **av, t_fractol *fractol);
int		aid(void);

#endif
