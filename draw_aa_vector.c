/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_aa_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 17:27:34 by cfeijoo           #+#    #+#             */
/*   Updated: 2013/12/29 10:55:28 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	pixel_to_image(t_env *env, t_point a, int color, float opacity)
{
	int		i;

	i = WIN_WIDTH * (int)a.y + (int)a.x;
	if (i < WIN_WIDTH * WIN_HEIGHT && (int)a.y >= 0 && (int)a.x >= 0
		&& (int)a.x < WIN_WIDTH)
	{
		env->data[i] = blend_colors(env->data[i], color, (opacity + 1) / 2);	
	}
}

static void	swap_points(t_point **a, t_point **b, u_grad *grad)
{
	t_point	*cache_point;
	int		cache_color;

	cache_point = *a;
	cache_color = grad->color2;
	*a = *b;
	*b = cache_point;
	grad->color2 = grad->color1;
	grad->color1 = cache_color;
}

static void	draw_loop_x(t_env *env, t_point *start, t_point *end, u_grad grad)
{
	float	derivative;
	float	proportion;
	t_point	current;
	int		color;

	current.x = (int)start->x;
	current.y = start->y;
	derivative = (end->y - start->y) / (end->x - start->x);
	while ((int)current.x <= (int)end->x)
	{
		proportion = (current.x - start->x) / (end->x - start->x);
		color = blend_colors(grad.color1, grad.color2, proportion);
		pixel_to_image(env, current, color, current.y - (int)current.y);
		current.y--;
		pixel_to_image(env, current, color, 1 - (current.y - (int)current.y));
		current.y++;
		current.x = current.x + 1;
		current.y = current.y + derivative;
	}
}

static void	draw_loop_y(t_env *env, t_point *start, t_point *end, u_grad grad)
{
	float	derivative;
	float	proportion;
	t_point	current;
	int		color;

	current.x = start->x;
	current.y = (int)start->y;
	derivative = (end->x - start->x) / (end->y - start->y);
	while ((int)current.y <= (int)end->y)
	{
		proportion = (current.y - start->y) / (end->y - start->y);
		color = blend_colors(grad.color1, grad.color2, proportion);
		pixel_to_image(env, current, color, current.x - (int)current.x);
		current.x--;
		pixel_to_image(env, current, color, 1 - (current.x - (int)current.x));
		current.x++;
		current.x = current.x + derivative;
		current.y = current.y + 1;
	}
}

void		draw_aa_vector(t_env *env, t_vector v, int color1, int color2)
{
	t_point	*start;
	t_point	*end;
	u_grad	grad;

	start = v.a;
	end = v.b;
	grad.color1 = color1;
	grad.color2 = color2;
	if (ft_abs((int)(v.a->x - v.b->x)) <= ft_abs((int)(v.a->y - v.b->y)))
	{
		if (v.b->y < v.a->y)
			swap_points(&start, &end, &grad);
		draw_loop_y(env, start, end, grad);
	}
	else
	{
		if (v.b->x < v.a->x)
			swap_points(&start, &end, &grad);
		draw_loop_x(env, start, end, grad);
	}
}