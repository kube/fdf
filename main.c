/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 05:01:28 by cfeijoo           #+#    #+#             */
/*   Updated: 2013/12/19 19:08:02 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int				main(void)
{
	t_env		env;
	t_vector	vector1;
	t_vector	vector2;
	t_vector	vector3;
	t_vector	vector4;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_WIDTH, WIN_HEIGHT, "42");
	env.img = mlx_new_image(env.mlx, WIN_WIDTH, WIN_HEIGHT);

	vector1.a.x = 50;
	vector1.a.y = 150;
	vector1.b.x = 150;
	vector1.b.y = 100;
	
	vector2.a.x = 150;
	vector2.a.y = 100;
	vector2.b.x = 200;
	vector2.b.y = 200;
	
	vector3.a.x = 200;
	vector3.a.y = 200;
	vector3.b.x = 100;
	vector3.b.y = 250;
	
	vector4.a.x = 100;
	vector4.a.y = 250;
	vector4.b.x = 50;
	vector4.b.y = 150;

	draw_vector(env, &vector1, 0xFF0000, 0x00FFFF);
	draw_vector(env, &vector2, 0x00FFFF, 0x00FF00);
	draw_vector(env, &vector3, 0x00FF00, 0xFFFF00);
	draw_vector(env, &vector4, 0xFFFF00, 0xFF0000);
	/*mlx_put_image_to_window(env.mlx, env.win, env.img, 0, 0);*/
	sleep(40);
	return (0);
}
