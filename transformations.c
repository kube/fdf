/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 14:09:42 by cfeijoo           #+#    #+#             */
/*   Updated: 2013/12/22 16:37:55 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void			rotate_z_axis(t_vector *cache, float angle_z)
{
	t_point		a;
	t_point		b;

	a.x = cache->a->x;
	a.y = cache->a->y;
	b.x = cache->b->x;
	b.y = cache->b->y;
	cache->a->x = a.x * cos(angle_z) - a.y * sin(angle_z);
	cache->a->y = a.x * sin(angle_z) + a.y * cos(angle_z);
	cache->b->x = b.x * cos(angle_z) - b.y * sin(angle_z);
	cache->b->y = b.x * sin(angle_z) + b.y * cos(angle_z);
}

void			rotate_x_axis(t_vector *cache, float angle_x)
{
	t_point		a;
	t_point		b;

	a.y = cache->a->y;
	a.z = cache->a->z;
	b.y = cache->b->y;
	b.z = cache->b->z;
	cache->a->y = a.y * sin(angle_x) + a.z * cos(angle_x);
	cache->a->z = a.y * cos(angle_x) - a.z * sin(angle_x);
	cache->b->y = b.y * sin(angle_x) + b.z * cos(angle_x);
	cache->b->z = b.y * cos(angle_x) - b.z * sin(angle_x);
}

void			rotate_y_axis(t_vector *cache, float angle_y)
{
	t_point		a;
	t_point		b;

	a.x = cache->a->x;
	a.z = cache->a->z;
	b.x = cache->b->x;
	b.z = cache->b->z;
	cache->a->x = a.z * sin(angle_y) + a.x * cos(angle_y);
	cache->a->z = a.z * cos(angle_y) - a.x * sin(angle_y);
	cache->b->x = b.z * sin(angle_y) + b.x * cos(angle_y);
	cache->b->z = b.z * cos(angle_y) - b.x * sin(angle_y);
}

void			translation(t_vector *cache, float x, float y, float z)
{
	cache->a->x += x;
	cache->a->y += y;
	cache->a->z += z;
	cache->b->x += x;
	cache->b->y += y;
	cache->b->z += z;
}

void			scale(t_vector *cache, float coeff)
{
	cache->a->x *= coeff;
	cache->a->y *= coeff;
	cache->a->z *= coeff;
	cache->b->x *= coeff;
	cache->b->y *= coeff;
	cache->b->z *= coeff;
}