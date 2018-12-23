/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 00:08:11 by ebatchas          #+#    #+#             */
/*   Updated: 2018/12/22 01:48:10 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/prototypes.h"

double		ft_homothetie(double start, double end, double rapport)
{
	return (start + (end - start) * rapport);
}

void		ft_julia_zoom(t_julia *j, int x, int y, double factor)
{
	t_vect2d	p;
	double		rapport;

	p.x = (double)x * (j->pmax.x - j->pmin.x) / SCR_WIDTH + j->pmin.x;
	p.y = (double)y * (j->pmax.y - j->pmin.y) / SCR_HEIGHT + j->pmin.y;
	rapport = 1.0 / factor;
	j->pmin.x = ft_homothetie(p.x, j->pmin.x, rapport);
	j->pmin.y = ft_homothetie(p.y, j->pmin.y, rapport);
	j->pmax.x = ft_homothetie(p.x, j->pmax.x, rapport);
	j->pmax.y = ft_homothetie(p.y, j->pmax.y, rapport);
}

void		ft_set_juliac(t_complex	*c, int k)
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

void		ft_setjuliacoords(t_julia *j, t_complex *z, int x, int y)
{
	z->x = j->pmin.x + ((j->pmax.x - j->pmin.x) / SCR_WIDTH) * (double)x;
	z->y = j->pmin.y + ((j->pmax.y - j->pmin.y) / SCR_HEIGHT) * (double)y;
	if (j->k == MANDEL)
	{
		j->c.x = z->x;
		j->c.y = z->y;
	}
}
