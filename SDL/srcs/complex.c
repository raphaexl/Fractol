/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:10:31 by ebatchas          #+#    #+#             */
/*   Updated: 2018/12/22 02:27:29 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/complex.h"

double			ft_module(t_complex *c)
{
	return (sqrt(c->x * c->x + c->y * c->y));
}

double		ft_pow(double base, int puiss)
{
	double		res;

	res = 1.0;
	if (puiss < 0)
	{
		puiss = -puiss;
		base = 1.0 / base;
	}
	while (puiss)
	{
		if (puiss & 1)
			res *= base;
		puiss >>=  1;
		base *= base;
	}
	return (res);
}

void	ft_complex(t_complex *z, double x, double y)
{
	z->x = x;
	z->y = y;
}

void		ft_compute(t_complex *z, t_complex *c, int n)
{
	t_complex	p;

	if (n == 2)
	{
		p.x = (z->x * z->x - z->y * z->y) + c->x;
		p.y = (z->y * z->x + z->y * z->x) + c->y;
		ft_complex(z, p.x, p.y);
		return ;
	}
	else
	{
		p.x = ft_pow(z->x * z->x + z->y * z->y, n >> 1) * cos(n * atan2(z->y, z->x)) + c->x;
		p.y = ft_pow(z->x * z->x + z->y * z->y, n >> 1) * sin(n * atan2(z->y, z->x)) + c->y;
		ft_complex(z, p.x, p.y);
		return ;
	}
}
