/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blend_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 19:07:01 by cfeijoo           #+#    #+#             */
/*   Updated: 2013/12/27 21:06:30 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int				blend_colors(int color1, int color2, float coeff)
{
	u_color		ucolor1;
	u_color		ucolor2;
	u_color		new_color;

	ucolor1.color = color1;
	ucolor2.color = color2;
	new_color.red = ucolor1.red * (1 - coeff) + ucolor2.red * coeff;
	new_color.green = ucolor1.green * (1 - coeff) + ucolor2.green * coeff;
	new_color.blue = ucolor1.blue * (1 - coeff) + ucolor2.blue * coeff;
	return (new_color.color);
}