/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keycode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:54:26 by ebatchas          #+#    #+#             */
/*   Updated: 2018/12/22 01:29:42 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_key_pressed(int keycode, void *params)
{
	t_fractol	*f;

	f = (t_fractol *)params;
	if (keycode == MLX_SCANCODE_ESCAPE)
		ft_close();
	if (keycode == MLX_SCANCODE_PAD_ADD)
		f->j.imax += (f->j.imax < 600) ? 6 : 0;
	if (keycode == MLX_SCANCODE_PAD_SUB)
		f->j.imax -= (f->j.imax > 30) ? 6 : 0;
	if (keycode == MLX_SCANCODE_SPACEBAR)
		ft_julia_init(&f->j, f->k = (++f->j.k % 10));
	if (keycode == MLX_SCANCODE_I)
		ft_julia_init(&f->j, f->j.k);
	if (keycode == MLX_SCANCODE_C)
		f->j.v = (++f->j.v % 4);
	if (keycode == MLX_SCANCODE_N)
		f->j.n += 1;
	if (keycode == MLX_SCANCODE_M)
		f->j.n -= 1;
	ft_julia_move(&f->j, keycode);
	ft_fractol_draw(f);
	return (0);
}

int		ft_mouse_pressed(int button, int x, int y, void *params)
{
	t_fractol	*f;

	f = (t_fractol *)params;
	if (button == MLX_BUTTON_LEFT)
		f->j.move = 0;
	if (button == MLX_BUTTON_RIGHT)
		f->j.move = 1;
	if (button == MLX_BUTTON_UP)
		ft_julia_zoom(&f->j, x, y, 1.0 / 0.9);
	if (button == MLX_BUTTON_DOWN)
		ft_julia_zoom(&f->j, x, y, 0.9);
	ft_fractol_draw(f);
	return (0);
}

int		ft_mouse_move(int x, int y, void *params)
{
	t_fractol	*f;

	f = (t_fractol *)params;
	if (f->j.move && f->k != MANDEL)
	{
		f->j.c.x = (0.0018 * (SCR_WIDTH / 2 - x));
		f->j.c.y = (0.0018 * (SCR_HEIGHT / 2 - y));
	}
	ft_fractol_draw(f);
	return (0);
}
