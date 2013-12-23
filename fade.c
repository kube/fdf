/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fade.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 23:35:48 by cfeijoo           #+#    #+#             */
/*   Updated: 2013/12/22 23:43:48 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		fade(t_env *env, int color, float coeff)
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

void		clear(t_env *env)
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