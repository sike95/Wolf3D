/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 20:35:45 by mmpofu            #+#    #+#             */
/*   Updated: 2017/10/10 09:50:25 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		read_from_fd(t_gnl *var, int fd, char **line)
{
	while ((var->ret = read(fd, var->buff, BUFF_SIZE)) > 0)
	{
		var->buff[var->ret] = '\0';
		if (ft_strchr(var->buff, '\n'))
		{
			var->save = ft_strdup(ft_strchr(var->buff, '\n'));
			var->temp = *line;
			*line = ft_strjoin(var->temp, ft_strsub(var->buff, 0,
						ft_strlen(var->buff) - ft_strlen(var->save)));
			var->save++;
			free(var->temp);
			return (1);
		}
		var->temp = *line;
		*line = ft_strjoin(var->temp, var->buff);
		free(var->temp);
	}
	if (var->ret < 0)
		return (var->ret);
	if (**line)
		return (1);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl var;

	if (line == NULL)
		return (-1);
	*line = ft_strnew(0);
	if (var.save)
	{
		var.temp = *line;
		*line = ft_strjoin(var.temp, var.save);
		free(var.temp);
		if (ft_strchr(*line, '\n'))
		{
			var.save = ft_strdup(ft_strchr(*line, '\n'));
			var.temp = *line;
			*line = ft_strsub(var.temp, 0, ft_strlen(var.temp)
					- ft_strlen(var.save));
			free(var.temp);
			var.save++;
			return (1);
		}
		var.save = NULL;
	}
	return (read_from_fd(&var, fd, line));
}
