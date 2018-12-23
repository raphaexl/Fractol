/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 21:35:14 by ebatchas          #+#    #+#             */
/*   Updated: 2018/12/23 19:23:21 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# define SCR_WIDTH 400
# define SCR_HEIGHT 400
# define NB_THREADS 200

# include <SDL2/SDL.h>
# include <sys/stat.h>
# include <math.h>
# include <fcntl.h>
# include <libft.h>
# include <pthread.h>
# include <complex.h>

typedef	enum	e_fractol
{
	MANDEL
}				t_fractol;

typedef struct		s_point
{
	int		x;
	int		y;
}					t_point;

typedef	struct		s_vect2d
{
	double	x;
	double	y;
}					t_vect2d;

typedef struct		s_input
{
	int		quit;
	int		mousex;
	int		mousey;
	int		xwheel;
	int		ywheel;
	int		mousexrel;
	int		mouseyrel;
	int		mouse[6];
	int		keys[SDL_NUM_SCANCODES];
}					t_input;

typedef	struct		s_ptr
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
}					t_ptr;

typedef struct		s_julia
{
	t_complex		c;
	t_vect2d		pmin;
	t_vect2d		pmax;
	double			zoom;
	int				imax;
	int				n;
	int				v;
	int				k;
}					t_julia;

typedef	struct		s_fractal
{
	t_julia		j;
	int			start;
	Uint32		*pixels;
}					t_fractal;

typedef	struct		s_arg
{
	int				k;
	t_fractal 		f;
}					t_arg;

void		ft_draw(t_fractal *f);
void		ft_sdl_error(void);
void		ft_sdl_put_pixel(Uint32 *pixels, int x, int y, int color);
void		ft_clear_pixels(Uint32 *pixels);

int			ft_color1( int i, int imax);
int			ft_rgb_color(unsigned int r, unsigned int g, unsigned int b);
t_point		ft_point(int x, int y);
int			ft_color(t_complex z, int i, int imax, int choice);
int			ft_color2(int	k, int n);

double		ft_homothetie(double start, double end, double rapport);
void		ft_set_juliac(t_complex	*c, int k);
void		ft_setjuliacoords(t_julia *j, t_complex *z, int x, int y);

void		ft_sdl_draw_octant1(Uint32 *pixels, t_point p1, t_point p2, Uint32 color);
void		ft_sdl_draw_octant2(Uint32 *pixels, t_point p1, t_point p2, Uint32 color);
void		ft_sdl_draw_line(Uint32 *pixels, t_point p1, t_point p2, Uint32 color);
void		ft_sdl_draw_circle(Uint32 *pixels, t_point co, int radius , Uint32 color);
void		ft_sdl_draw_disc(Uint32 *pixels, t_point co, int radius, Uint32 color);

void		ft_update_event(t_input *in);
void		ft_handle_input(t_input *in, t_julia *j);
int			ft_sdl_init(t_ptr *ptr, int width, int height, const char *title);
int			ft_update_renderer(t_ptr ptr, Uint32 *pixel);

void		ft_julia_init(t_julia *j, int k);
void		ft_julia_reset(t_julia *j);
void		*ft_julia_draw(void *args);
void		ft_julia_zoom(t_julia *j, int x, int y, double factor);
void		ft_sdl_quit(t_ptr *ptr);
#endif
