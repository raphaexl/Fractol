/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 23:49:27 by ebatchas          #+#    #+#             */
/*   Updated: 2019/04/23 21:37:53 by ebatchas         ###   ########.fr       */
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

void	ft_onahiz(t_arg *g, int x, int y, int k)
{
	if (k == g->f->j.imax)
		g->pixels[x + y * SCR_WIDTH] = 0xFF00;
	else
		g->pixels[x + y * SCR_WIDTH] = 0xFFFF00;
}

void		*ft_julia_draw(void *argv)
{
	int			x;
	int			y;
	t_complex	z;
	t_complex	c;
	t_arg		*t;
	int			k;

	t = (t_arg *)argv;
	t->f->start = t->k * SCR_WIDTH / NB_THREADS;
	x = t->f->start - 1;
	while (++x <  (t->k  + 1) * SCR_WIDTH / NB_THREADS)
	{
		y = -1;
		while (++y < SCR_HEIGHT)
		{
			ft_setjuliacoords(&t->f->j, &z, x, y);
			c = z;
			k = -1;
		   while ((z.x * z.x + z.y * z.y) < 4.0 && (++k < t->f->j.imax))
				ft_compute(&z, &c, t->f->j.n);
		   k == t->f->j.imax ? ft_sdl_put_pixel(t->pixels, x, y, 0) :
			   ft_sdl_put_pixel(t->pixels, x, y, ft_color(z, k , t->f->j.imax, t->f->j.v));
		}
	}
	pthread_exit(NULL);
}
