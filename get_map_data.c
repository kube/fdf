/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 17:13:01 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/11 18:41:08 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
**	Really needs to be bettered
*/

static void	store_map_points(t_point **map_line, char *line, int y)
{
	int		i;
	int		x;
	int		sign;
	t_point	*point;

	x = 0;
	sign = 1;
	i = 0;
	while (line[i])
	{
		if (line[i] == '-' && (sign = -1))
			i++;
		point = (t_point*)ft_memalloc(sizeof(t_point));
		point->x = x;
		point->y = y;
		while (line[i] && ft_isdigit(line[i]))
		{
			point->z += sign * (line[i] - '0');
			i++;
		}
		map_line[x] = point;
		while (line[i] && !ft_isdigit(line[i]))
			i++;
		x++;
	}
}

static void	store_map_lines(int fd, t_point ***map_data, unsigned int width)
{
	int				y;
	char			*line;

	y = 0;
	while (get_next_line(fd, &line))
	{
		*map_data = (t_point**)malloc(width * sizeof(t_point*) + 1);
		store_map_points(*map_data, line, y);
		y++;
		map_data++;
		free(line);
	}
}

/*
**	Here the allocation size is hard-coded, very dirty
*/

t_point		***get_map_data(char *file_name)
{
	int				file1;
	t_point			***map_data;

	map_data = (t_point***)malloc(400 * sizeof(t_point**) + 1);
	file1 = open(file_name, O_RDONLY);
	store_map_lines(file1, map_data, 400);
	close(file1);
	return (map_data);
}
