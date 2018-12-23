/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:53:54 by ebatchas          #+#    #+#             */
/*   Updated: 2018/12/19 14:00:20 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

# include <math.h>
# define P2(X) X * X
# define P3(X) X * X * X
# define P4(X) P2(X) * P2(X)
# define P5(X) P3(X) * P2(X)
# define P6(X) P4(X) * P2(X)
# define P7(X) P4(X) * P3(X)

typedef struct	s_complex
{
	double		x;
	double		y;
}				t_complex;

double			ft_module(t_complex *c);
double			ft_pow(double base, int	n);
void			ft_complex(t_complex *z, double x, double y);
void			ft_compute(t_complex *z, t_complex *c, int n);
void			ft_compute7(t_complex *z, t_complex *c, int n);

#endif
