/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 12:21:52 by ebatchas          #+#    #+#             */
/*   Updated: 2018/12/23 22:37:26 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		ft_display_usage(void)
{
	ft_putendl(" Utiliser + / - pour augmanter le nombre d'iterations ");
	ft_putendl("Attention Car Il croit de 6 en 6!");
	ft_putendl(" Les Touches directionnelles serve a deplacer la Mandelbrot");
	ft_putendl(" Attention Il se fait Mieux Pour Un Zoom  !");
	ft_putendl("Les Touches N et M Pour Le Multibrot !");
	ft_putendl("La Touche C Pour La Coloration");
	ft_putendl("La Touche Space Pour Changer De Fracatle");
	ft_putendl("1337.ma");
}

double		ft_interpolate(double start, double end, double fact)
{
	return (start + ((end - start) * fact));
}

void		ft_setcoordinates(t_julia *j, t_complex *z, int x, int y)
{
	z->x = j->pmin.x + ((j->pmax.x - j->pmin.x) / SCR_WIDTH) * (double)x;
	z->y = j->pmin.y + ((j->pmax.y - j->pmin.y) / SCR_HEIGHT) * (double)y;
}

void		ft_fractol_init(t_fractol *f, int k)
{
	f->ptr.mlx_ptr = mlx_init();
	f->ptr.mlx_win = mlx_new_window(f->ptr.mlx_ptr, SCR_WIDTH, SCR_HEIGHT, "F");
	f->ptr.img.img_ptr = mlx_new_image(f->ptr.mlx_ptr, SCR_WIDTH, SCR_HEIGHT);
	f->ptr.img.data = (int *)mlx_get_data_addr(f->ptr.img.img_ptr,
			&f->ptr.img.bpp, &f->ptr.img.size_len, &f->ptr.img.endian);
	f->k = k;
	f->start = 0;
	ft_julia_init(&f->j, k);
}

void		ft_fractol_draw(t_fractol *f)
{
	if (f->k == TREE)
	{
		ft_mlx_clear_pixels(f->ptr.img.data);
		ft_tree_draw(&f->ptr, ft_get_point(SCR_WIDTH / 2, SCR_HEIGHT - 5),
				ft_get_point(SCR_WIDTH / 2, SCR_HEIGHT - 150), 8);
	}
	else
		ft_julia_draw(f);
	mlx_put_image_to_window(f->ptr.img.data, f->ptr.mlx_win, f->ptr.img.img_ptr,
			0, 0);
}
