/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 21:26:06 by ebatchas          #+#    #+#             */
/*   Updated: 2018/12/19 20:53:20 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double		ft_fc(double x)
{
	if (x <= 0.0)
		return (0.0);
	if (x >= 1.0)
		return (1.0);
	return (2.0 * (1.0 + x * sqrt(x) - (1 - x) * sqrt(1 - x)) - 3.0 * x);
}

void		ft_setpoint(t_poind *p, int x, int y)
{
	p->x = x;
	p->y = y;
}

t_poind		ft_get_point(int x, int y)
{
	t_poind p;

	p.x = x;
	p.y = y;
	return (p);
}

void		ft_tree_draw(t_ptr *ptr, t_poind p, t_poind q, int n)
{
	double		angle;
	t_poind		a;
	t_poind		b;
	t_poind		d;

	angle = 30 * M_PI / 180;
	if (n == 0)
		return ;
	ft_mlx_draw_line(ptr, p, q, 0xFFFF00);
	d.x = 0.8 * (q.x - p.x);
	d.y = 0.8 * (q.y - p.y);
	a.x = q.x + cos(angle) * d.x - sin(angle) * d.y;
	a.y = q.y + sin(angle) * d.x + cos(angle) * d.y;
	b.x = q.x + cos(-angle) * d.x - sin(-angle) * d.y;
	b.y = q.y + sin(-angle) * d.x + cos(-angle) * d.y;
	ft_tree_draw(ptr, q, a, n - 1);
	ft_tree_draw(ptr, q, b, n - 1);
}
