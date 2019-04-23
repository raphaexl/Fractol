/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:18:52 by ebatchas          #+#    #+#             */
/*   Updated: 2019/02/08 15:37:18 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			ft_fill_pixel(int *data, int x, int y, int color)
{
	if (y < SCR_HEIGHT && y >= 0 && x >= 0 && x < SCR_WIDTH)
		data[y * SCR_WIDTH + x] = color;
}

void			ft_mlx_clear_pixels(int *pixels)
{
	int		i;

	i = -1;
	while (++i < SCR_WIDTH * SCR_HEIGHT)
		pixels[i] = 0x000000;
}

void			ft_mlx_draw_octant1(t_ptr *ptr, t_poind p1, t_poind p2, int c)
{
	t_poind		dp;
	t_poind		pincr;
	int			error;
	int			i;

	i = -1;
	pincr.x = p1.x < p2.x ? 1 : -1;
	pincr.y = p1.y < p2.y ? 1 : -1;
	dp.x = abs(p2.x - p1.x);
	dp.y = abs(p2.y - p1.y);
	error = dp.x / 2;
	while (++i <= dp.x)
	{
		p1.x += pincr.x;
		error += dp.y;
		if (error > dp.x)
		{
			error -= dp.x;
			p1.y += pincr.y;
		}
		ft_fill_pixel(ptr->img.data, p1.x, p1.y, c);
	}
}

void			ft_mlx_draw_octant2(t_ptr *ptr, t_poind p1, t_poind p2, int c)
{
	t_poind		dp;
	t_poind		pincr;
	int			error;
	int			i;

	i = -1;
	pincr.x = p1.x < p2.x ? 1 : -1;
	pincr.y = p1.y < p2.y ? 1 : -1;
	dp.x = abs(p2.x - p1.x);
	dp.y = abs(p2.y - p1.y);
	error = dp.y / 2;
	while (++i <= dp.y)
	{
		p1.y += pincr.y;
		error += dp.x;
		if (error > dp.y)
		{
			error -= dp.y;
			p1.x += pincr.x;
		}
		ft_fill_pixel(ptr->img.data, p1.x, p1.y, c);
	}
}

void			ft_mlx_draw_line(t_ptr *ptr, t_poind p1, t_poind p2, int c)
{
	ft_fill_pixel(ptr->img.data, p1.x, p1.y, c);
	ft_fill_pixel(ptr->img.data, p2.x, p2.y, c);
	if (abs(p2.x - p1.x) > abs(p2.y - p1.y))
		ft_mlx_draw_octant1(ptr, p1, p2, c);
	else
		ft_mlx_draw_octant2(ptr, p1, p2, c);
}
