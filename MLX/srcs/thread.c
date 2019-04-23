/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:17:15 by ebatchas          #+#    #+#             */
/*   Updated: 2019/04/06 21:14:42 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			*ft_julia_draw_t(void *ptr)
{
	t_complex	z;
	int			x;
	int			y;
	t_arg		*t;

	t = (t_arg *)ptr;
	t->f.start = t->iter * SCR_WIDTH / NB_THREADS;
	x = (t->iter  + 1) * SCR_WIDTH / NB_THREADS + 1;
	while (--x >= t->f.start)  
	{
		y = SCR_HEIGHT + 1;
		while (--y >= 0)
		{
			ft_setcoordinates(&t->f.j, &z, x, y);
			if (t->f.j.k == MANDEL)
				ft_complex(&t->f.j.c, z.x, z.y);
			t->f.i = -1;
			while ((z.x * z.x + z.y * z.y) < 4 && (++t->f.i < t->f.j.imax))
				ft_compute(&z, &t->f.j.c, t->f.j.n);
			(t->f.i == t->f.j.imax) ? ft_fill_pixel(t->f.ptr.img.data, x, y, 
					0x000000): ft_fill_pixel(t->f.ptr.img.data, x, y, ft_color
						(t->f.j.v, t->f.i, t->f.j.imax, z));
		}
	}
	pthread_exit(NULL);
}
