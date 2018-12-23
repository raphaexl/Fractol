/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:10:31 by ebatchas          #+#    #+#             */
/*   Updated: 2018/12/22 03:42:20 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/complex.h"

double			ft_module(t_complex *c)
{
	return (sqrt(c->x * c->x + c->y * c->y));
}

void			ft_complex(t_complex *z, double x, double y)
{
	z->x = x;
	z->y = y;
}

double			ft_pow(double base, int n)
{
	double		res;

	res = 1.0;
	if (n == 0)
		return (1);
	if (n == 1)
		return (base);
	if (n < 0)
	{
		n = -n;
		base = 1.0 / base;
	}
	while (n)
	{
		if (n & 1)
			res *= base;
		n >>= 1;
		base *= base;
	}
	return (res);
}

void			ft_compute7(t_complex *z, t_complex *c, int n)
{
	if (n == 7)
		ft_complex(z, P7(z->x) - P5(z->x) * P2(z->y) * 21 + P3(z->x) * P4(z->y)
				* 35 - z->x * P6(z->y) * 7 + c->x, z->y * P6(z->x) * 7 -
				P3(z->y) * P4(z->x) * 35 + P2(z->x) * P5(z->y) * 21 - P7(z->y)
				+ c->y);
	else
		ft_complex(z, ft_pow(z->x * z->x + z->y * z->y, n >> 1) * cos(n * atan2(
						z->y, z->x)) + c->x, ft_pow(z->y * z->y + z->x * z->x,
						n >> 1) * sin(n * atan2(z->y, z->x)) + c->y);
}

void			ft_compute(t_complex *z, t_complex *c, int n)
{
	if (n == 2)
		ft_complex(z, P2(z->x) - P2(z->y) + c->x, z->x * z->y * 2 + c->y);
	else if (n == 3)
		ft_complex(z, P3(z->x) - P2(z->y) * z->x * 3 + c->x, z->y * P2(z->x) * 3
			- P3(z->y) + c->y);
	else if (n == 4)
		ft_complex(z, P4(z->x) - P2(z->x) * P2(z->y) * 6 + P4(z->y) + c->x,
			P3(z->x) * z->y * 4 - P3(z->y) * z->x * 4 + c->y);
	else if (n == 5)
		ft_complex(z, P5(z->x) - P3(z->x) * P2(z->y) * 10 + z->x * P4(z->y)
			* 5 + c->x, z->y * P4(z->x) * 5 - P2(z->x) * P3(z->y) * 10 +
			P5(z->y) + c->y);
	else if (n == 6)
		ft_complex(z, P6(z->x) - P4(z->x) * P2(z->y) * 15 + P4(z->y) *
			P2(z->x) * 15 - P6(z->y) + c->x, P5(z->x) * z->y * 6
			- P3(z->x) * P3(z->y) * 20 + z->x * P5(z->y) * 6 + c->y);
	else
		ft_compute7(z, c, n);
}
