/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:54:55 by ebatchas          #+#    #+#             */
/*   Updated: 2018/12/22 03:06:19 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/prototypes.h"

int		main(int argc, char *argv[])
{
	t_input	in;
	int		status;
	t_ptr	ptr;
	t_fractal	f;

	status = EXIT_FAILURE;
	if (argc != 2)
	{
		ft_putendl("usage : ./fdf fractal_name");
		goto Quit;
	}
	ft_julia_init(&f.j, 0);
	if (ft_sdl_init(&ptr, SCR_WIDTH, SCR_HEIGHT, argv[1]))
		goto Quit;
	if (!(f.pixels = (Uint32 *)malloc(sizeof(Uint32) * SCR_WIDTH * SCR_HEIGHT)))
	{
		ft_putendl("Error Malloc pixels");
	}
	ft_memset(f.pixels, 0, sizeof(Uint32) * SCR_WIDTH * SCR_HEIGHT);
	ft_memset(&in, SDL_FALSE, sizeof(t_input));
	while (!in.quit)
	{
		ft_update_event(&in);
		ft_handle_input(&in, &f.j);
		ft_draw(&f);
		ft_update_renderer(ptr, f.pixels);
	}
	status = EXIT_SUCCESS;
Quit:
	ft_sdl_quit(&ptr);
	return (status);
}
