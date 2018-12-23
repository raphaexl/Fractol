/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 23:49:27 by ebatchas          #+#    #+#             */
/*   Updated: 2018/12/23 22:35:41 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/prototypes.h"

void		ft_julia_init(t_julia *j, int k)
{
	j->pmin.x = (0 - SCR_WIDTH / 2.0) * 4.0 / SCR_WIDTH;
	j->pmin.y = (0 - SCR_HEIGHT / 2.0) * 4.0 / SCR_WIDTH;
	j->pmax.x = (SCR_WIDTH - SCR_WIDTH / 2.0) * 4.0 / SCR_WIDTH;
	j->pmax.y = (SCR_HEIGHT - SCR_HEIGHT / 2.0) * 4.0 / SCR_WIDTH;
	j->k = k;
	j->n = 2;
	j->v = 1;
	j->imax = 42;
	j->zoom = 40.0;
	j->c.x = -2.1;
	j->c.y = -1.2;
}

void		ft_julia_reset(t_julia *j)
{
	j->pmin.x = (0 - SCR_WIDTH / 2.0) * 4.0 / SCR_WIDTH;
	j->pmin.y = (0 - SCR_HEIGHT / 2.0) * 4.0 / SCR_WIDTH;
	j->pmax.x = (SCR_WIDTH - SCR_WIDTH / 2.0) * 4.0 / SCR_WIDTH;
	j->pmax.y = (SCR_HEIGHT - SCR_HEIGHT / 2.0) * 4.0 / SCR_WIDTH;
	j->imax = 42;
	j->zoom = 40.0;
	ft_set_juliac(&j->c, j->k);
}


void		*ft_julia_draw(void *argv)
{
	int			x;
	int			y;
	t_complex	z;
	t_arg		*t;
	int			k;

	t = (t_arg *)argv;
	t->f.start = t->k * SCR_WIDTH / NB_THREADS;
	x = (t->k  + 1) * SCR_WIDTH / NB_THREADS + 1;
	while (--x >= t->f.start)
	{
		y = SCR_HEIGHT + 1;
		while (--y >= 0)
		{
			ft_setjuliacoords(&t->f.j, &z, x, y);
			k = -1;
		   while ((z.x * z.x + z.y * z.y) < 4.0 && (++k < t->f.j.imax))
				ft_compute(&z, &t->f.j.c, t->f.j.n);
		   k == t->f.j.imax ? ft_sdl_put_pixel(t->f.pixels, x, y, 0) :
			   ft_sdl_put_pixel(t->f.pixels, x, y, ft_color(z, k , t->f.j.imax, t->f.j.v));
		}
	}
	pthread_exit(NULL);
}
