/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:51:22 by ebatchas          #+#    #+#             */
/*   Updated: 2018/12/19 21:02:06 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		main(int argc, char *argv[])
{
	t_fractol	f;

	if (argc != 2)
		ft_usage();
	ft_fractol_init(&f, ft_get_fractal(argv));
	ft_display_usage();
	ft_update_event(&f);
	ft_fractol_draw(&f);
	mlx_loop(f.ptr.mlx_ptr);
	return (0);
}
