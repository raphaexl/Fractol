/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 22:34:32 by ebatchas          #+#    #+#             */
/*   Updated: 2018/12/22 12:44:00 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

unsigned int	ft_color3(double x)
{
	int		xx;

	x += 0.2;
	x -= (int)x;
	if (x < 0)
		x += 1.0;
	x *= 6;
	xx = x;
	x -= xx;
	if (xx == 0)
		return (ft_get_color(255, 255 * ft_fc(1.0 - x), 0));
	if (xx == 1)
		return (ft_get_color(255, 0, 255 * ft_fc(x)));
	if (xx == 2)
		return (ft_get_color(255 * ft_fc(1.0 - x), 0, 255));
	if (xx == 3)
		return (ft_get_color(0, 255 * ft_fc(x), 255));
	if (xx == 4)
		return (ft_get_color(0, 255, 255 * ft_fc(1 - x)));
	return (ft_get_color(255 * ft_fc(x), 255, 0));
}

unsigned int	ft_hsv_to_rgb(double h, double s, double v)
{
	double		p;
	double		q;
	double		r;
	int			k;

	if (s == 0)
		return (ft_get_color(v * 255, v * 255, v * 255));
	h = 6 * (h - floor(h));
	p = v * (1 - s);
	q = v * (1 - (s * (h - floor(h))));
	r = v * (1 - (s * (1 - h + floor(h))));
	k = h - floor(h);
	if (k == 0)
		return (ft_get_color(v * 255, r * 255, p * 255));
	else if (k == 1)
		return (ft_get_color(q * 255, v * 255, p * 255));
	else if (k == 2)
		return (ft_get_color(p * 255, v * 255, r * 255));
	else if (k == 3)
		return (ft_get_color(p * 255, q * 255, v * 255));
	else if (k == 4)
		return (ft_get_color(r * 255, p * 255, v * 255));
	else
		return (ft_get_color(v * 255, p * 255, q * 255));
}

void			ft_settab(int *tab, double x, double y, double z)
{
	tab[0] = fmin(fmax(255 * x, 0), 255);
	tab[1] = fmin(fmax(255 * y, 0), 255);
	tab[2] = fmin(fmax(255 * z, 0), 255);
}

unsigned int	ft_color2(int n, int max)
{
	int			tab[3];
	int			nn;
	double		t;

	t = (double)n / (double)max;
	n = (int)(t * (double)N3);
	tab[2] = n / (NC * NC);
	nn = n - tab[2] * NC * NC;
	tab[0] = nn / NC;
	tab[1] = nn - tab[0] * NC;
	return (ft_get_color(tab[0], tab[1], tab[2]));
}

unsigned int	ft_color(int val, int iter, int max, t_complex z)
{
	double			hu;
	double			mod;

	if (val == 0)
		return (ft_color1(iter, max));
	if (val == 1)
	{
		if (z.y > 0)
			return (0x000000);
		return (0xFFFFFF);
	}
	if (val == 3)
		return (ft_color2(iter, max));
	mod = log(sqrt(z.x * z.x + z.y * z.y)) / log(4.0) - 1.0;
	hu = (iter - log2(mod + 1.0)) / 128.0;
	return (ft_hsv_to_rgb(hu, 0.7, 1.0));
}
