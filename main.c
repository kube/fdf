/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 05:01:28 by cfeijoo           #+#    #+#             */
/*   Updated: 2013/12/21 01:21:55 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <math.h>

static void		rotate_z_axis(t_vector *cache, float angle_z)
{
	t_point		a;
	t_point		b;

	// Cache
	a.x = cache->a->x;
	a.y = cache->a->y;
	b.x = cache->b->x;
	b.y = cache->b->y;

	// Rotation
	cache->a->x = a.x * cos(angle_z) - a.y * sin(angle_z);
	cache->a->y = a.x * sin(angle_z) + a.y * cos(angle_z);
	cache->b->x = b.x * cos(angle_z) - b.y * sin(angle_z);
	cache->b->y = b.x * sin(angle_z) + b.y * cos(angle_z);	
}

static void		translation(t_vector *cache, int left, int top)
{
	// Translation
	cache->a->x += left;
	cache->a->y += top;
	cache->b->x += left;
	cache->b->y += top;	

}

static void		scale(t_vector *cache, float coeff)
{
	// Scale
	cache->a->x *= coeff;
	cache->a->y *= coeff;
	cache->b->x *= coeff;
	cache->b->y *= coeff;
}

static void		load_vector(t_vector *cache, t_vector v)
{
	cache->a->x = v.a->x;
	cache->a->y = v.a->y;
	cache->b->x = v.b->x;
	cache->b->y = v.b->y;
}

int				main(void)
{
	float		angle;
	float		decalage;
	t_env		env;
	t_point		a;
	t_point		b;
	t_point		c;
	t_point		d;
	t_vector	vector1;
	t_vector	vector2;
	t_vector	vector3;
	t_vector	vector4;

	t_point		cache1;
	t_point		cache2;
	t_vector	cache_vector;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_WIDTH, WIN_HEIGHT, "42");
	env.img = mlx_new_image(env.mlx, WIN_WIDTH, WIN_HEIGHT);
	env.data = (int*)mlx_get_data_addr(env.img, &(env.bpp), &(env.size_line), &(env.endian));

	angle = 0;
	decalage = 0;
	while (1)
	{
		a.x = -1;
		a.y = -1;
		
		b.x = +1;
		b.y = -1;
		
		c.x = +1;
		c.y = +1;
		
		d.x = -1;
		d.y = +1;

		vector1.a = &a;
		vector1.b = &b;

		vector2.a = &b;
		vector2.b = &c;

		vector3.a = &c;
		vector3.b = &d;

		vector4.a = &d;
		vector4.b = &a;

		cache1 = a;
		cache2 = b;
		cache_vector.a = &cache1;
		cache_vector.b = &cache2;

		load_vector(&cache_vector, vector1);
		rotate_z_axis(&cache_vector, angle);
		scale(&cache_vector, 100 - decalage);
		translation(&cache_vector, 100 + decalage, 100 + decalage);
		draw_vector(&env, cache_vector, 0xFF0000, 0x00FFFF);
		
		load_vector(&cache_vector, vector2);
		rotate_z_axis(&cache_vector, angle);
		scale(&cache_vector, 100 - decalage);
		translation(&cache_vector, 100 + decalage, 100 + decalage);
		draw_vector(&env, cache_vector, 0x00FFFF, 0x00FF00);
		
		load_vector(&cache_vector, vector3);
		rotate_z_axis(&cache_vector, angle);
		scale(&cache_vector, 100 - decalage);
		translation(&cache_vector, 100 + decalage, 100 + decalage);
		draw_vector(&env, cache_vector, 0x00FF00, 0xFFFF00);
		
		load_vector(&cache_vector, vector4);
		rotate_z_axis(&cache_vector, angle);
		scale(&cache_vector, 100 - decalage);
		translation(&cache_vector, 100 + decalage, 100 + decalage);
		draw_vector(&env, cache_vector, 0xFFFF00, 0xFF0000);

		mlx_put_image_to_window(env.mlx, env.win, env.img, 0, 0);
		angle += 0.06;
		decalage += 0.4;
		// sleep(40);
	}
	return (0);
}
