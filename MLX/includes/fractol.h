/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:58:27 by ebatchas          #+#    #+#             */
/*   Updated: 2019/04/08 15:46:00 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define SCR_WIDTH  840
# define SCR_HEIGHT 640

# define NB_THREADS 6 
# define NC 256
# define N3 NC*NC*NC

# include "mlx.h"
# include "libft.h"
# include <time.h>
# include <pthread.h>
# include "complex.h"
# include "mlx_keycode.h"

typedef	enum	e_fractal
{
	MANDEL, JUL_1, JUL_2, JUL_3, JUL_4, JUL_5, JUL_6, JUL_7, JUL_8, TREE
}				t_fractal;

typedef struct	s_point
{
	double		x;
	double		y;
}				t_point;

typedef struct	s_poind
{
	int			x;
	int			y;
}				t_poind;

typedef	struct	s_img
{
	void	*img_ptr;
	int		*data;
	int		bpp;
	int		size_len;
	int		endian;
}				t_img;

typedef	struct	s_ptr
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	img;
}				t_ptr;

typedef struct	s_julia
{
	t_point		pmin;
	t_point		pmax;
	t_point		delta;
	t_complex	c;
	double		n;
	int			imax;
	int			move;
	int			v;
	t_fractal	k;
}				t_julia;

typedef struct	s_fractol
{
	t_ptr			ptr;
	t_julia			j;
	int				k;
	int				i;
	int				start;
}				t_fractol;

typedef	struct	s_arg
{
	int			iter;
	t_fractol	f;
}				t_arg;

double			ft_fc(double x);
int				ft_close(void);
void			ft_usage(void);
void			ft_display_usage(void);
int				ft_randint(int xmin, int max);
int				ft_get_fractal(char **argv);
double			ft_interpolate(double start, double end, double fact);
unsigned int	ft_get_color(unsigned int r, unsigned int g, unsigned int b);
unsigned int	ft_color1(int n, int k);
unsigned int	ft_color2(int iter, int max);
unsigned int	ft_color3(double x);
unsigned int	ft_color(int v, int iter, int max, t_complex z);
unsigned int	ft_hsv_to_rgb(double h, double s, double v);
void			ft_settab(int *tab, double x, double y, double z);
void			ft_setpoint(t_poind *p, int x, int y);
t_poind			ft_get_point(int x, int y);

void			ft_fill_pixel(int *data, int x, int y, int color);
void			ft_mlx_clear_pixels(int *data);
void			ft_mlx_draw_octant1(t_ptr *ptr, t_poind p1, t_poind p2, int c);
void			ft_mlx_draw_octant2(t_ptr *ptr, t_poind p1, t_poind p2, int c);
void			ft_mlx_draw_line(t_ptr *ptr, t_poind p1, t_poind p2, int c);
void			ft_draw_triangle(t_ptr *ptr, t_poind *p, int color);

void			ft_tree_draw(t_ptr *ptr, t_poind p, t_poind q, int n);

void			ft_julia_init(t_julia *j, int k);
void			ft_julia_draw(t_fractol *f);

void			*ft_julia_draw_t(void *argv);

void			ft_setfractalc(t_complex *c, int k);
void			ft_setcoordinates(t_julia *j, t_complex *z, int x, int y);
void			ft_julia_reset(t_julia *j);
void			ft_julia_zoom(t_julia *j, int x, int y, double factor);
void			ft_julia_move(t_julia *j, int keycode);

void			ft_fractol_init(t_fractol *f, int k);
void			ft_fractol_draw(t_fractol *f);
void			ft_fractol_quit(t_fractol *f);

void			ft_update_event(t_fractol *ptr);
int				ft_key_pressed(int keycode, void *params);
int				ft_key_released(int keycode, void *params);
int				ft_mouse_pressed(int button, int x, int y, void *params);
int				ft_mouse_released(int button, int x, int y, void *params);
int				ft_mouse_move(int x, int y, void *params);
#endif
