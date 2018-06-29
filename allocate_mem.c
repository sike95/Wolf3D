/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:38:10 by mmpofu            #+#    #+#             */
/*   Updated: 2017/11/22 18:37:21 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_row_col		get_size(int fd)
{
	t_main_var	var;

	var.i = 0;
	var.cnt = 0;
	var.flag = 0;
	while ((get_next_line(fd, &var.line)) > 0)
	{
		if (var.flag == 0)
		{
			var.split = ft_strsplit(var.line, ',');
			while (var.split[var.cnt])
				var.cnt++;
			var.flag = 1;
		}
		var.i++;
	}
	free(var.line);
	var.size.row = var.i;
	var.size.col = var.cnt;
	return (var.size);
}

int				**allocate_map(t_row_col size, int **temp_map)
{
	int			y;

	y = 0;
	temp_map = (int**)malloc(sizeof(int*) * (size.row + 1));
	while (y < size.row)
	{
		temp_map[y] = (int*)malloc(sizeof(int) * (size.col + 1));
		y++;
	}
	return (temp_map);
}

int				populate_map(int fd, int **map, t_row_col size)
{
	int			i;
	int			j;
	char		**split;
	char		*line;

	i = 0;
	while ((get_next_line(fd, &line)) > 0)
	{
		split = ft_strsplit(line, ',');
		j = -1;
		while (++j < size.col)
		{
			(map)[i][j] = ft_atoi(split[j]);
		}
		i++;
		free(line);
	}
	return (1);
}
