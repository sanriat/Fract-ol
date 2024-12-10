/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damoncad <damoncad@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-22 15:50:46 by damoncad          #+#    #+#             */
/*   Updated: 2024-04-22 15:50:46 by damoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s1[i] && i < len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_putstr(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
	return (1);
}

void	data_init(t_fractol *fractol)
{
	fractol->zoom = 4.0;
	fractol->x = 0;
	fractol->y = 0;
	fractol->real = 0;
	fractol->immag = 0;
	fractol->temp = 0;
	fractol->c_real = 0;
	fractol->c_immag = 0;
	fractol->j = 0;
	fractol->n = 0;
	fractol->i = 0;
	fractol->color = 0;
}
