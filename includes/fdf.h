/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 21:58:14 by cfeijoo           #+#    #+#             */
/*   Updated: 2013/12/21 01:21:59 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <libft.h>
# include <stdio.h>

# define WIN_HEIGHT 920
# define WIN_WIDTH 1220

typedef struct			s_point
{
	float				x;
	float				y;
	float				z;
}						t_point;

typedef struct			s_vector
{
	t_point				*a;
	t_point				*b;
}						t_vector;

typedef union
{
	struct			
	{
		unsigned char	blue;
		unsigned char	green;
		unsigned char	red;
		char			opacity;
	};
	int					color;
}						u_color;

typedef	struct			s_env
{
	void				*mlx;
	void				*win;
	void				*img;
	int					bpp;
	int					size_line;
	int					endian;
	int					*data;
}						t_env;

typedef	union
{
	struct
	{
		int					color1;
		int					color2;
	};
}						u_grad;

void		draw_vector(t_env *env, t_vector vect, int color1, int color2);
int			blend_colors(int color1, int color2, float coeff);

#endif
