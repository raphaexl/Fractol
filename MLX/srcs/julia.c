/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 20:46:55 by ebatchas          #+#    #+#             */
/*   Updated: 2018/12/23 22:41:41 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		ft_julia_init(t_julia *j, int k)
{
	j->pmin.x = (0 - SCR_WIDTH / 2.0) * 4.0 / SCR_WIDTH;
	j->pmin.y = (0 - SCR_HEIGHT / 2.0) * 4.0 / SCR_WIDTH;
	j->pmax.x = (SCR_WIDTH - SCR_WIDTH / 2.0) * 4.0 / SCR_WIDTH;
	j->pmax.y = (SCR_HEIGHT - SCR_HEIGHT / 2.0) * 4.0 / SCR_WIDTH;
	j->n = 2;
	if (j->k == MANDEL)
		j->imax = 42;
	else if (j->k == JUL_1 || j->k == JUL_2)
		j->imax = 60;
	else
		j->imax = 90;
	j->k = k;
	j->v = 0;
	j->move = 0;
	if (k < 9)
		ft_setfractalc(&j->c, k);
}

void		ft_julia_zoom(t_julia *j, int x, int y, double factor)
{
	t_point	p;
	double	interpolation;

	p.x = (double)x * (j->pmax.x - j->pmin.x) / SCR_WIDTH + j->pmin.x;
	p.y = (double)y * (j->pmax.y - j->pmin.y) / SCR_HEIGHT + j->pmin.y;
	interpolation = 1.0 / factor;
	j->pmin.x = ft_interpolate(p.x, j->pmin.x, interpolation);
	j->pmin.y = ft_interpolate(p.y, j->pmin.y, interpolation);
	j->pmax.x = ft_interpolate(p.x, j->pmax.x, interpolation);
	j->pmax.y = ft_interpolate(p.y, j->pmax.y, interpolation);
}

void		ft_julia_move(t_julia *j, int keycode)
{
	if (keycode == MLX_SCANCODE_UP)
	{
		j->pmin.y += 0.05;
		j->pmax.y += 0.05;
	}
	if (keycode == MLX_SCANCODE_DOWN)
	{
		j->pmin.y -= 0.05;
		j->pmax.y -= 0.05;
	}
	if (keycode == MLX_SCANCODE_RIGHT)
	{
		j->pmin.x -= 0.05;
		j->pmax.x -= 0.05;
	}
	if (keycode == MLX_SCANCODE_LEFT)
	{
		j->pmin.x += 0.05;
		j->pmax.x += 0.05;
	}
}

void		ft_setfractalc(t_complex *c, int k)
{
	t_complex	tab[9];

	tab[0].x = 0.0;
	tab[0].y = 0.0;
	tab[1].x = -0.96;
	tab[1].y = 0.735;
	tab[2].x = -0.414;
	tab[2].y = -0.612;
	tab[3].x = 0.382;
	tab[3].y = 0.147;
	tab[4].x = 0.284;
	tab[4].y = -0.0122;
	tab[5].x = -0.181;
	tab[5].y = -0.667;
	tab[6].x = 0.299;
	tab[6].y = 0.449;
	tab[7].x = 0.103;
	tab[7].y = 0.636;
	tab[8].x = -0.861;
	tab[8].y = -0.231;
	*c = tab[k];
}

void		ft_julia_draw(t_fractol *f)
{
	int		k;
	t_arg	arg[NB_THREADS];
	pthread_t	t[NB_THREADS];
	pthread_attr_t attr[NB_THREADS];

	k = -1;
	while (++k < NB_THREADS)
	{	
		arg[k].iter = k;
		arg[k].f = *f;
		pthread_attr_init(&attr[k]);
		pthread_create(&t[k], &attr[k], &ft_julia_draw_t, (void *)&arg[k]);
	}
	k = -1;
	while (++k < NB_THREADS)
	{	
		pthread_join(t[k], NULL);
	}
}
