/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 22:21:00 by ebatchas          #+#    #+#             */
/*   Updated: 2019/04/23 21:22:43 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/prototypes.h"


void		ft_handle_input(t_input *in, t_julia *j)
{
	if (in->keys[SDL_SCANCODE_UP])
	{
		j->pmin.y -= 0.005;
		j->pmax.y -= 0.005;
	}
	if (in->keys[SDL_SCANCODE_DOWN])
	{
		j->pmin.y += 0.005;
		j->pmax.y += 0.005;
	}
	if (in->keys[SDL_SCANCODE_RIGHT])
	{
		j->pmax.x += 0.005;
		j->pmin.x += 0.005;
	}
	if (in->keys[SDL_SCANCODE_LEFT])
	{
		j->pmin.x -= 0.005;
		j->pmax.x -= 0.005;
	}
	if (in->keys[SDL_SCANCODE_SPACE])
		ft_set_juliac(&j->c, j->k = ++j->k % 10);
	if (in->keys[SDL_SCANCODE_I])
		ft_julia_init(j, j->k);
	if (in->keys[SDL_SCANCODE_N])
	{
		j->n += 1;
		ft_julia_reset(j);
	}
	if (in->keys[SDL_SCANCODE_M])
	{
		j->n -= 1;
		ft_julia_reset(j);
	}
	if (in->keys[SDL_SCANCODE_C])
		j->v = (++j->v % 3);
	if (in->keys[SDL_SCANCODE_KP_PLUS])
		j->imax += 6;
	if (in->keys[SDL_SCANCODE_KP_MINUS])
		j->imax -= (j->imax > 0) ? 6 : 0;
	if (in->mouse[SDL_BUTTON_LEFT])
		ft_julia_zoom(j, in->mousex, in->mousey, 1.0 / 0.8);
	if (in->mouse[SDL_BUTTON_RIGHT])
		ft_julia_zoom(j, in->mousex, in->mousey, 0.8);
}

void		ft_draw(t_fractal *f, Uint32 *pixels)
{
	int		k;
	t_arg	arg[NB_THREADS];
	pthread_t	t[NB_THREADS];
	pthread_attr_t attr[NB_THREADS];

	k = -1;
	while (++k < NB_THREADS)
	{	
		arg[k].k = k;
		arg[k].f = f;
		arg[k].pixels = pixels;
		pthread_attr_init(&attr[k]);
		pthread_create(&t[k], &attr[k], &ft_julia_draw, (void *)&arg[k]);
	}
	k = -1;
	while (++k < NB_THREADS)
	{	
		pthread_join(t[k], NULL);
	}
}
