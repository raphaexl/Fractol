/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:41:53 by ebatchas          #+#    #+#             */
/*   Updated: 2018/12/19 16:52:01 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		ft_update_event(t_fractol *f)
{
	mlx_hook(f->ptr.mlx_win, 2, 0, ft_key_pressed, f);
	mlx_hook(f->ptr.mlx_win, 4, 0, ft_mouse_pressed, f);
	mlx_hook(f->ptr.mlx_win, 6, 0, ft_mouse_move, f);
	mlx_hook(f->ptr.mlx_win, 17, 0, ft_close, f);
}
