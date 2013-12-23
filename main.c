/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 05:01:28 by cfeijoo           #+#    #+#             */
/*   Updated: 2013/12/22 23:42:56 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int		key_hook(int keycode, t_env *env)
{
	if (keycode == 65507)
		exit(0);
	if (keycode == 98)
		env->blured = 1 - env->blured;
	if (keycode == 65363)
	{
		if (env->rotation == -1)
			env->angle -= 4;
		env->rotation = -1;
	}
	if (keycode == 65361)
	{
		if (env->rotation == 1)
			env->angle += 4;
		env->rotation = 1;
	}
	if (keycode == 65362)
		env->angle_x += 0.4;
	if (keycode == 65364)
		env->angle_x -= 0.4;
	return (0);
}

static void		display_all_vectors(t_env *env, float angle,
									t_point *center)
{
	int			x;
	int			y;
	t_point		cache1;
	t_point		cache2;
	t_vector	cache_vector;

	y = 0;
	cache_vector.a = &cache1;
	cache_vector.b = &cache2;
	while (env->map[y])
	{
		x = 0;
		while (env->map[y][x])
		{
			if (env->map[y][x + 1])
			{
				load_vector(&cache_vector, env->map[y][x], env->map[y][x +1], center);
				display_vector(env, cache_vector, angle);
			}
				if (env->map[y + 1] && env->map[y + 1][x])
			{
				load_vector(&cache_vector, env->map[y][x], env->map[y + 1][x], center);
				display_vector(env, cache_vector, angle);
			}
			x++;
		}
		y++;
	}
}

static int		expose_hook(t_env *env)
{
	if (env->blured)
		fade(env, 0x000000, 0.09);
	else
		clear(env);
	display_all_vectors(env, env->angle, &env->center);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	env->angle += 0.63 * env->rotation;
	return (0);
}

int				main(int argc, char **argv)
{
	t_env		env;

	if (argc == 2)
	{
		env.map = get_map_data(argv[1]);
		env.mlx = mlx_init();
		env.win = mlx_new_window(env.mlx, WIN_WIDTH, WIN_HEIGHT, "42");
		env.img = mlx_new_image(env.mlx, WIN_WIDTH, WIN_HEIGHT);
		env.data = (int*)mlx_get_data_addr(env.img, &(env.bpp), &(env.size_line), &(env.endian));
		env.angle = 0;
		env.blured = 1;
		env.horizon = 1;
		env.rotation = 1;
		env.angle_x = 
		env.center.x = 8.5;
		env.center.y = 5.5;
		mlx_expose_hook(env.win, expose_hook, &env);
		mlx_key_hook(env.win, key_hook, &env);
		mlx_loop_hook(env.mlx, expose_hook, &env);
		mlx_loop(env.mlx);
	}
	return (0);
}