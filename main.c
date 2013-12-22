/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 05:01:28 by cfeijoo           #+#    #+#             */
/*   Updated: 2013/12/22 16:28:44 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void		load_vector(t_vector *cache, t_vector v)
{
	cache->a->x = v.a->x;
	cache->a->y = v.a->y;
	cache->a->z = v.a->z;
	cache->b->x = v.b->x;
	cache->b->y = v.b->y;
	cache->b->z = v.b->z;
}

static void		fade(t_env *env, int color, float coeff)
{
	int			i;

	i = 0;
	while (i < WIN_WIDTH * WIN_HEIGHT)
	{
		if (env->data[i] != color)
			env->data[i] = blend_colors(env->data[i], color, coeff);
		i++;
	}
}

static void		clear(t_env *env)
{
	int			i;

	i = 0;
	while (i < WIN_WIDTH * WIN_HEIGHT)
	{
		if (env->data[i])
			env->data[i] = 0;
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

		(void)fade;
		(void)clear;
		// clear(&env);
		// fade(&env, 0x000000, 0.09);
		fade(&env, 0xFFFFFF, 0.09);
		// fade(&env, rand() % 0xF0F0F0, 0.06);

		load_vector(&cache_vector, vector1);
		rotate_z_axis(&cache_vector, angle);
		rotate_x_axis(&cache_vector, angle);
		rotate_y_axis(&cache_vector, angle);
		scale(&cache_vector, 100 - decalage);
		translation(&cache_vector, 100 + decalage, 100 + decalage, 0);
		draw_vector(&env, cache_vector, 0xFF0000, 0x00FFFF);
		
		load_vector(&cache_vector, vector2);
		rotate_z_axis(&cache_vector, angle);
		rotate_x_axis(&cache_vector, angle);
		rotate_y_axis(&cache_vector, angle);
		scale(&cache_vector, 100 - decalage);
		translation(&cache_vector, 100 + decalage, 100 + decalage, 0);
		draw_vector(&env, cache_vector, 0x00FFFF, 0x00FF00);
		
		load_vector(&cache_vector, vector3);
		rotate_z_axis(&cache_vector, angle);
		rotate_x_axis(&cache_vector, angle);
		rotate_y_axis(&cache_vector, angle);
		scale(&cache_vector, 100 - decalage);
		translation(&cache_vector, 100 + decalage, 100 + decalage, 0);
		draw_vector(&env, cache_vector, 0x00FF00, 0xFFFF00);
		
		load_vector(&cache_vector, vector4);
		rotate_z_axis(&cache_vector, angle);
		rotate_x_axis(&cache_vector, angle);
		rotate_y_axis(&cache_vector, angle);
		scale(&cache_vector, 100 - decalage);
		translation(&cache_vector, 100 + decalage, 100 + decalage, 0);
		draw_vector(&env, cache_vector, 0xFFFF00, 0xFF0000);





		load_vector(&cache_vector, vector5);
		rotate_z_axis(&cache_vector, angle);
		rotate_x_axis(&cache_vector, angle);
		rotate_y_axis(&cache_vector, angle);
		scale(&cache_vector, 100 - decalage);
		translation(&cache_vector, 100 + decalage, 100 + decalage, 0);
		draw_vector(&env, cache_vector, 0xFF0000, 0x00FFFF);
		
		load_vector(&cache_vector, vector6);
		rotate_z_axis(&cache_vector, angle);
		rotate_x_axis(&cache_vector, angle);
		rotate_y_axis(&cache_vector, angle);
		scale(&cache_vector, 100 - decalage);
		translation(&cache_vector, 100 + decalage, 100 + decalage, 0);
		draw_vector(&env, cache_vector, 0x00FFFF, 0x00FF00);
		
		load_vector(&cache_vector, vector7);
		rotate_z_axis(&cache_vector, angle);
		rotate_x_axis(&cache_vector, angle);
		rotate_y_axis(&cache_vector, angle);
		scale(&cache_vector, 100 - decalage);
		translation(&cache_vector, 100 + decalage, 100 + decalage, 0);
		draw_vector(&env, cache_vector, 0x00FF00, 0xFFFF00);
		
		load_vector(&cache_vector, vector8);
		rotate_z_axis(&cache_vector, angle);
		rotate_x_axis(&cache_vector, angle);
		rotate_y_axis(&cache_vector, angle);
		scale(&cache_vector, 100 - decalage);
		translation(&cache_vector, 100 + decalage, 100 + decalage, 0);
		draw_vector(&env, cache_vector, 0xFFFF00, 0xFF0000);




		load_vector(&cache_vector, vector9);
		rotate_z_axis(&cache_vector, angle);
		rotate_x_axis(&cache_vector, angle);
		rotate_y_axis(&cache_vector, angle);
		scale(&cache_vector, 100 - decalage);
		translation(&cache_vector, 100 + decalage, 100 + decalage, 0);
		draw_vector(&env, cache_vector, 0xFF0000, 0x00FFFF);
		
		load_vector(&cache_vector, vector10);
		rotate_z_axis(&cache_vector, angle);
		rotate_x_axis(&cache_vector, angle);
		rotate_y_axis(&cache_vector, angle);
		scale(&cache_vector, 100 - decalage);
		translation(&cache_vector, 100 + decalage, 100 + decalage, 0);
		draw_vector(&env, cache_vector, 0x00FFFF, 0x00FF00);
		
		load_vector(&cache_vector, vector11);
		rotate_z_axis(&cache_vector, angle);
		rotate_x_axis(&cache_vector, angle);
		rotate_y_axis(&cache_vector, angle);
		scale(&cache_vector, 100 - decalage);
		translation(&cache_vector, 100 + decalage, 100 + decalage, 0);
		draw_vector(&env, cache_vector, 0x00FF00, 0xFFFF00);
		
		load_vector(&cache_vector, vector12);
		rotate_z_axis(&cache_vector, angle);
		rotate_x_axis(&cache_vector, angle);
		rotate_y_axis(&cache_vector, angle);
		scale(&cache_vector, 100 - decalage);
		translation(&cache_vector, 100 + decalage, 100 + decalage, 0);
		draw_vector(&env, cache_vector, 0xFFFF00, 0xFF0000);


		mlx_put_image_to_window(env.mlx, env.win, env.img, 0, 0);
		angle += 0.04 + angle / 1000;
		decalage += 0.9;
		// mlx_loop(env.mlx);
	}
	return (0);
}
