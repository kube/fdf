/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 21:58:14 by cfeijoo           #+#    #+#             */
/*   Updated: 2013/12/22 23:43:20 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <libft.h>
# include <get_next_line.h>

# define WIN_HEIGHT 920
# define WIN_WIDTH 1220
# define MAX_HORIZON_Z 1000

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
	float				angle;					
	int					blured;
	int					horizon;
	int					rotation;
	float				angle_x;
	t_point				***map;
	t_point				center;
}						t_env;

typedef	union
{
	struct
	{
		int				color1;
		int				color2;
	};
}						u_grad;

void		draw_vector(t_env *env, t_vector vect, int color1, int color2);
int			blend_colors(int color1, int color2, float coeff);
void		rotate_z_axis(t_vector *cache, float angle_z);
void		rotate_x_axis(t_vector *cache, float angle_x);
void		rotate_y_axis(t_vector *cache, float angle_y);
void		translation(t_vector *cache, float x, float y, float z);
void		scale(t_vector *cache, float coeff);
t_point		***get_map_data(char *file_name);
void		load_vector(t_vector *cache, t_point *a, t_point *b, t_point *center);
int			get_color_from_z(float z);
void		horizon_point(t_vector *vector);
void		display_vector(t_env *env, t_vector vector, float angle);
void		fade(t_env *env, int color, float coeff);
void		clear(t_env *env);
float		ft_cos(float x);
float		ft_sin(float x);
int			ft_abs(int nb);
#endif
