/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 05:01:28 by cfeijoo           #+#    #+#             */
/*   Updated: 2013/12/21 23:35:36 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <math.h>
#include <strings.h>

static void		rotate_z_axis(t_vector *cache, float angle_z)
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

static void		rotate_x_axis(t_vector *cache, float angle_x)
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

static void		rotate_y_axis(t_vector *cache, float angle_y)
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

static void		translation(t_vector *cache, int left, int top)
{
	cache->a->x += left;
	cache->a->y += top;
	cache->b->x += left;
	cache->b->y += top;	
}

static void		scale(t_vector *cache, float coeff)
{
	cache->a->x *= coeff;
	cache->a->y *= coeff;
	cache->a->z *= coeff;
	cache->b->x *= coeff;
	cache->b->y *= coeff;
	cache->b->z *= coeff;
}

static void		load_vector(t_vector *cache, t_vector v)
{
	cache->a->x = v.a->x;
	cache->a->y = v.a->y;
	cache->a->z = v.a->z;
	cache->b->x = v.b->x;
	cache->b->y = v.b->y;
	cache->b->z = v.b->z;
}

static void		hide(t_env *env, float coeff)
{
	int			i;

	i = 0;
	while (i < WIN_WIDTH * WIN_HEIGHT)
	{
		if (env->data[i])
			env->data[i] = blend_colors(env->data[i], 0x000000, coeff);
		i++;
	}
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
	t_point		f;
	t_point		g;
	t_point		h;
	t_point		i;

	t_vector	vector1;
	t_vector	vector2;
	t_vector	vector3;
	t_vector	vector4;
	t_vector	vector5;
	t_vector	vector6;
	t_vector	vector7;
	t_vector	vector8;
	t_vector	vector9;
	t_vector	vector10;
	t_vector	vector11;
	t_vector	vector12;

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
		a.z = +1;
		
		b.x = +1;
		b.y = -1;
		b.z = +1;
		
		c.x = +1;
		c.y = +1;
		c.z = +1;
		
		d.x = -1;
		d.y = +1;
		d.z = +1;

		f.x = -1;
		f.y = -1;
		f.z = -1;
		
		g.x = +1;
		g.y = -1;
		g.z = -1;
		
		h.x = +1;
		h.y = +1;
		h.z = -1;
		
		i.x = -1;
		i.y = +1;
		i.z = -1;

		vector1.a = &a;
		vector1.b = &b;

		vector2.a = &b;
		vector2.b = &c;

		vector3.a = &c;
		vector3.b = &d;

		vector4.a = &d;
		vector4.b = &a;


		vector5.a = &f;
		vector5.b = &g;

		vector6.a = &g;
		vector6.b = &h;

		vector7.a = &h;
		vector7.b = &i;

		vector8.a = &i;
		vector8.b = &f;


		vector9.a = &a;
		vector9.b = &f;

		vector10.a = &b;
		vector10.b = &g;

		vector11.a = &c;
		vector11.b = &h;

		vector12.a = &d;
		vector12.b = &i;

		cache1 = a;
		cache2 = b;
		cache_vector.a = &cache1;
		cache_vector.b = &cache2;



		bzero(env.data, WIN_WIDTH * WIN_HEIGHT * 4);
		(void)hide;
		(void)rotate_y_axis;
		(void)rotate_x_axis;
		// hide(&env, 0.01);



		load_vector(&cache_vector, vector1);
		rotate_z_axis(&cache_vector, angle);
		rotate_x_axis(&cache_vector, angle);
		rotate_y_axis(&cache_vector, angle);
		scale(&cache_vector, 100 - decalage);
		translation(&cache_vector, 100 + decalage, 100 + decalage);
		draw_vector(&env, cache_vector, 0xFF0000, 0x00FFFF);
		
		load_vector(&cache_vector, vector2);
		rotate_z_axis(&cache_vector, angle);
		rotate_x_axis(&cache_vector, angle);
		rotate_y_axis(&cache_vector, angle);
		scale(&cache_vector, 100 - decalage);
		translation(&cache_vector, 100 + decalage, 100 + decalage);
		draw_vector(&env, cache_vector, 0x00FFFF, 0x00FF00);
		
		load_vector(&cache_vector, vector3);
		rotate_z_axis(&cache_vector, angle);
		rotate_x_axis(&cache_vector, angle);
		rotate_y_axis(&cache_vector, angle);
		scale(&cache_vector, 100 - decalage);
		translation(&cache_vector, 100 + decalage, 100 + decalage);
		draw_vector(&env, cache_vector, 0x00FF00, 0xFFFF00);
		
		load_vector(&cache_vector, vector4);
		rotate_z_axis(&cache_vector, angle);
		rotate_x_axis(&cache_vector, angle);
		rotate_y_axis(&cache_vector, angle);
		scale(&cache_vector, 100 - decalage);
		translation(&cache_vector, 100 + decalage, 100 + decalage);
		draw_vector(&env, cache_vector, 0xFFFF00, 0xFF0000);





		load_vector(&cache_vector, vector5);
		rotate_z_axis(&cache_vector, angle);
		rotate_x_axis(&cache_vector, angle);
		rotate_y_axis(&cache_vector, angle);
		scale(&cache_vector, 100 - decalage);
		translation(&cache_vector, 100 + decalage, 100 + decalage);
		draw_vector(&env, cache_vector, 0xFF0000, 0x00FFFF);
		
		load_vector(&cache_vector, vector6);
		rotate_z_axis(&cache_vector, angle);
		rotate_x_axis(&cache_vector, angle);
		rotate_y_axis(&cache_vector, angle);
		scale(&cache_vector, 100 - decalage);
		translation(&cache_vector, 100 + decalage, 100 + decalage);
		draw_vector(&env, cache_vector, 0x00FFFF, 0x00FF00);
		
		load_vector(&cache_vector, vector7);
		rotate_z_axis(&cache_vector, angle);
		rotate_x_axis(&cache_vector, angle);
		rotate_y_axis(&cache_vector, angle);
		scale(&cache_vector, 100 - decalage);
		translation(&cache_vector, 100 + decalage, 100 + decalage);
		draw_vector(&env, cache_vector, 0x00FF00, 0xFFFF00);
		
		load_vector(&cache_vector, vector8);
		rotate_z_axis(&cache_vector, angle);
		rotate_x_axis(&cache_vector, angle);
		rotate_y_axis(&cache_vector, angle);
		scale(&cache_vector, 100 - decalage);
		translation(&cache_vector, 100 + decalage, 100 + decalage);
		draw_vector(&env, cache_vector, 0xFFFF00, 0xFF0000);




		load_vector(&cache_vector, vector9);
		rotate_z_axis(&cache_vector, angle);
		rotate_x_axis(&cache_vector, angle);
		rotate_y_axis(&cache_vector, angle);
		scale(&cache_vector, 100 - decalage);
		translation(&cache_vector, 100 + decalage, 100 + decalage);
		draw_vector(&env, cache_vector, 0xFF0000, 0x00FFFF);
		
		load_vector(&cache_vector, vector10);
		rotate_z_axis(&cache_vector, angle);
		rotate_x_axis(&cache_vector, angle);
		rotate_y_axis(&cache_vector, angle);
		scale(&cache_vector, 100 - decalage);
		translation(&cache_vector, 100 + decalage, 100 + decalage);
		draw_vector(&env, cache_vector, 0x00FFFF, 0x00FF00);
		
		load_vector(&cache_vector, vector11);
		rotate_z_axis(&cache_vector, angle);
		rotate_x_axis(&cache_vector, angle);
		rotate_y_axis(&cache_vector, angle);
		scale(&cache_vector, 100 - decalage);
		translation(&cache_vector, 100 + decalage, 100 + decalage);
		draw_vector(&env, cache_vector, 0x00FF00, 0xFFFF00);
		
		load_vector(&cache_vector, vector12);
		rotate_z_axis(&cache_vector, angle);
		rotate_x_axis(&cache_vector, angle);
		rotate_y_axis(&cache_vector, angle);
		scale(&cache_vector, 100 - decalage);
		translation(&cache_vector, 100 + decalage, 100 + decalage);
		draw_vector(&env, cache_vector, 0xFFFF00, 0xFF0000);


		mlx_put_image_to_window(env.mlx, env.win, env.img, 0, 0);
		angle += 0.04;
		decalage += 0.9;
		usleep(90000);
		// mlx_loop(env.mlx);
	}
	return (0);
}
