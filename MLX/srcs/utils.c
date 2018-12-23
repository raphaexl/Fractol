/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:48:35 by ebatchas          #+#    #+#             */
/*   Updated: 2018/12/22 12:41:11 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int				ft_close(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

unsigned int	ft_get_color(unsigned int r, unsigned int g, unsigned int b)
{
	char			tab[4];

	tab[3] = 0;
	tab[2] = r;
	tab[1] = g;
	tab[0] = b;
	return (*(int *)(tab));
}

unsigned int	ft_color1(int n, int k)
{
	int		x;

	x = (n / (k / 6));
	if (x == 0)
		return (ft_get_color(255, (n % (k / 6)) * (255 / (k / 6)), 0));
	if (x == 1)
		return (ft_get_color(255 - (n % (k / 6)) * (255 / (k / 6)), 255, 0));
	if (x == 2)
		return (ft_get_color(0, 255, (n % (k / 6)) * (255 / (k / 6))));
	if (x == 3)
		return (ft_get_color(0, 255 - (n % (k / 6)) * (255 / (k / 6)), 0));
	if (x == 4)
		return (ft_get_color((n % (k / 6)) * (255 / (k / 6)), 0, 255));
	if (x == 5)
		return (ft_get_color(255, 0, 255 - (n % (k / 6)) * (255 / (k / 6))));
	return (ft_get_color(0, 0, 0));
}

int				ft_get_fractal(char *argv[])
{
	if (!ft_strcmp(argv[1], "Mandelbrot"))
		return (0);
	if (!ft_strcmp(argv[1], "Julia"))
		return (1);
	if (!ft_strcmp(argv[1], "Tree"))
		return (9);
	ft_usage();
	return (-1);
}

void			ft_usage(void)
{
	ft_putendl("./fractol Mandelbrot");
	ft_putendl("          Julia");
	ft_putendl("          Tree");
	exit(EXIT_FAILURE);
}
