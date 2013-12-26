/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kube <kube@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 23:34:09 by cfeijoo           #+#    #+#             */
/*   Updated: 2013/12/25 02:11:01 by kube             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		load_vector(t_vector *cache, t_point *a, t_point *b,
							t_point *center)
{
	// printf("%p\n", a);
	// printf("%p\n", b);
	cache->a->x = a->x - center->x;
	cache->a->y = a->y - center->y;
	cache->a->z = a->z;
	cache->b->x = b->x - center->x;
	cache->b->y = b->y - center->y;
	cache->b->z = b->z;
}

int			get_color_from_z(float z)
{
	float		coeff;

	coeff = z;
	if (coeff < 0)
		coeff = -coeff;
	if (coeff > 1)
		coeff = 1;
	if (z >= 0)
		return blend_colors(0xCC0099, 0xFFB400, coeff);
	else
		return blend_colors(0xCC0099, 0x3399FF, coeff);
}

void		horizon_point(t_vector *vector, float horizon_z)
{
	float		coeff;
	t_point		horizon;

	horizon.x = WIN_WIDTH / 2;
	horizon.y = WIN_HEIGHT / 2;
	coeff = vector->a->z / horizon_z;
	if (coeff > 1)
		coeff = 1;
	vector->a->x = (1 - coeff) * vector->a->x + coeff * horizon.x;
	vector->a->y = (1 - coeff) * vector->a->y + coeff * horizon.y;
	coeff = vector->b->z / horizon_z;
	if (coeff > 1)
		coeff = 1;
	vector->b->x = (1 - coeff) * vector->b->x + coeff * horizon.x;
	vector->b->y = (1 - coeff) * vector->b->y + coeff * horizon.y;
}

void		display_vector(t_env *env, t_vector vector, float angle)
{
	int			color1;
	int			color2;

	color1 = get_color_from_z(vector.a->z);
	color2 = get_color_from_z(vector.b->z);
	rotate_z_axis(&vector, angle / 100);
	rotate_x_axis(&vector, env->angle_x);
	scale(&vector, 40);
	translation(&vector, 600, 400, 0);
	if (env->horizon)
		horizon_point(&vector, env->horizon_z);
	draw_vector(env, vector, color1, color2);
}