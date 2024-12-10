/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damoncad <damoncad@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-10 12:25:00 by damoncad          #+#    #+#             */
/*   Updated: 2024-05-10 12:25:00 by damoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	aid(void)
{
	ft_putstr("Only numbers accepted as params.\n");
	return (0);
}

int	check_chars(char **av, int ac)
{
	int	i;
	int	j;

	i = 1;
	j = -1;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			if (av[i][j] <= 127 && av[i][j] >= 58)
				return (aid());
			if ((av[i][j] == 47)
			|| (av[i][j] <= 42 && av[i][j] >= 32)
			|| (av[i][j] == 44))
				return (aid());
			if (av[i][j] == 45 && av[i][j + 2] == 45)
				return (!ft_putstr("Only minus is not allowed!\n"));
			if (av[i][j] == 43 && av[i][j + 2] == 43)
				return (!ft_putstr("Only plus is not allowed!\n"));
		}
	}
	return (1);
}

int	hehe(int ac, char **av, t_fractol *fractol)
{
	free(fractol);
	return (1);
}
