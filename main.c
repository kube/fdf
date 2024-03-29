/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 05:01:28 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/11 17:17:01 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include "/opt/X11/include/X11/X.h"

static int		keypress_hook(int keycode, t_env *env)
{
	printf("%d\n", keycode);
	if (keycode == 65307)
		exit(0);
	if (keycode == 113)
		env->antialiased = 1 - env->antialiased;
	if (keycode == 104)
		env->horizon = 1 - env->horizon;
	if (keycode == 103)
		env->horizon_z = env->horizon_z - 50;
	if (keycode == 106)
		env->horizon_z = env->horizon_z + 50;
	if (keycode == 98)
		env->blured = (env->blured + 1) % 3;
	if (keycode == 65363)
		env->pressed_keys.left = 1;
	if (keycode == 65361)
		env->pressed_keys.right = 1;
	if (keycode == 65362)
		env->pressed_keys.up = 1;
	if (keycode == 65364)
		env->pressed_keys.down = 1;
	return (0);
}

static int		keyrelease_hook(int keycode, t_env *env)
{
	if (keycode == 65363)
		env->pressed_keys.left = 0;
	if (keycode == 65361)
		env->pressed_keys.right = 0;
	if (keycode == 65362)
		env->pressed_keys.up = 0;
	if (keycode == 65364)
		env->pressed_keys.down = 0;
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
		while (env->map[y] && env->map[y][x])
		{
			if (env->map[y][x + 1])
			{
				load_vector(&cache_vector, env->map[y][x], env->map[y][x + 1], center);
				display_vector(env, cache_vector, angle);
			}
			if (env->map[y + 1] && env->map[y + 1][x])
			{
				load_vector(&cache_vector, env->map[y][x], env->map[y + 1][x], center);
				display_vector(env, cache_vector, angle);
			}
			if (env->map[y + 1] && env->map[y + 1][x + 1])
			{
				load_vector(&cache_vector, env->map[y][x], env->map[y + 1][x + 1], center);
				display_vector(env, cache_vector, angle);
			}
			x++;
		}
		y++;
	}
}

static void				get_fps()
{
	static int			i = 0;
	static float		last_put = 0;
	float				time_ms;

	i++;
	time_ms = ((float)clock() / (float)CLOCKS_PER_SEC);
	if (time_ms - last_put > 1)
	{
		printf("%d FPS\n", i);
		last_put = time_ms;
		i = 0;
	}
}

static int				expose_hook(t_env *env)
{
	if (env->pressed_keys.left)
	{
		if (env->rotation == -1)
			env->angle -= 2;
		env->rotation = -1;
	}
	if (env->pressed_keys.right)
	{
		if (env->rotation == 1)
			env->angle += 2;
		env->rotation = 1;
	}
	if (env->pressed_keys.up)
		env->angle_x += 0.08;
	if (env->pressed_keys.down)
		env->angle_x -= 0.08;
	if (env->blured == 1)
		fade(env, 0x000000, 0.04);
	else if (env->blured == 0)
		clear(env);
	display_all_vectors(env, env->angle, &env->center);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	env->angle += 0.63 * env->rotation;
	get_fps();
	return (0);
}

static t_pressed_keys	init_pressed_keys()
{
	t_pressed_keys		pressed_keys;

	pressed_keys.up = 0;
	pressed_keys.down = 0;
	pressed_keys.left = 0;
	pressed_keys.right = 0;
	return (pressed_keys);
}

int						main(int argc, char **argv)
{
	t_env				env;


	if (argc == 2)
	{
		env.map = get_map_data(argv[1]);
		env.mlx = mlx_init();
		env.win = mlx_new_window(env.mlx, WIN_WIDTH, WIN_HEIGHT, "42");
		env.img = mlx_new_image(env.mlx, WIN_WIDTH, WIN_HEIGHT);
		env.data = (int*)mlx_get_data_addr(env.img, &(env.bpp), &(env.size_line), &(env.endian));
		env.pressed_keys = init_pressed_keys();
		env.angle = 0;
		env.blured = 1;
		env.horizon = 1;
		env.rotation = 1;
		env.horizon_z = 1000;
		env.antialiased = 1;
		env.angle_x = -PI - 0.5;
		env.center.x = 8.5;
		env.center.y = 5.5;
		mlx_expose_hook(env.win, expose_hook, &env);
		mlx_hook(env.win, KeyPress, KeyPressMask, keypress_hook, &env);
		mlx_hook(env.win, KeyRelease, KeyReleaseMask, keyrelease_hook, &env);
		mlx_loop_hook(env.mlx, expose_hook, &env);
		mlx_loop(env.mlx);
	}
	return (0);
}
