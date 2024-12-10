/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damoncad <damoncad@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-09 14:21:30 by damoncad          #+#    #+#             */
/*   Updated: 2024-05-09 14:21:30 by damoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_param(char *str, int i)
{
	while (str[i] != '\0')
	{
		if (str[i] < '.' || str[i] == '/' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	handle_signs(char *str, int *i, int *neg)
{
	if (str[*i] == '-')
		*neg = -1;
	if (str[*i] == '-' || str[*i] == '+')
		(*i)++;
}

double	ft_atod(char *str)
{
	double	result;
	double	decimal;
	int		neg;
	int		i;

	i = 0;
	result = 0;
	decimal = 0;
	neg = 1;
	handle_signs(str, &i, &neg);
	if (!check_param(str, i))
		exit (ft_putstr("Only numbers accepted as params.\n"));
	while (str[i] && str[i] != '.')
		result = result * 10 + (double)(str[i++] - 48);
	if (str[i] == '.')
	{
		i++;
		while (str[i])
			decimal = decimal * 10 + (double)(str[i++] - 48);
	}
	while (decimal >= 1)
		decimal /= 10;
	return ((result + decimal) * neg);
}

void	check(int ac, char **av)
{
	if (ac != 2 && !(ac == 4 && ft_strcmp(av[1], "Julia") == 0))
		exit (ft_error(0));
	if (available_fractals(av))
		exit (ft_error(0));
	if (ft_strcmp(av[1], "Julia") == 0 && ac != 4)
		exit (ft_error(1));
}

int	ft_error(int n)
{
	if (n == 0)
	{
		ft_putstr("\nThe program must be executed as follows:\n \
				\n./fract-ol <fractal>\n \
				\nIf it's Julia, then: ./fract-ol <Julia> <c_real> <c_immag>\n \
				\nThe available fractals are:\n \
				\n'Mandelbrot' 'Burning_ship' 'Julia <c_real> <c_immag>'\n");
		exit (1);
	}
	if (n == 1)
	{
		ft_putstr("\nJulia is missing parameters\n \
				\nTo run julia you need to write:\n \
				\n./fract-ol julia <c_ real> <c_immag>\n \
				\nExample: ./fract-ol julia 0.000061 -0.000371\n \
				\nThe parameters must be between -2 and 2\n");
		exit (1);
	}
	if (n == 2)
	{
		ft_putstr("Parameters are not compressed between -2 and 2\n");
		exit (1);
	}
	else
		exit (1);
}
