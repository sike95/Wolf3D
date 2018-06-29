/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:31:12 by mmpofu            #+#    #+#             */
/*   Updated: 2018/06/29 10:57:45 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

SDL_Renderer	*init(char *title)
{
	SDL_Window		*win;
	SDL_Renderer	*ren;

	SDL_Init(SDL_INIT_VIDEO);
	win = SDL_CreateWindow(title, 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED
			| SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
	SDL_RenderClear(ren);
	SDL_RenderPresent(ren);
	return (ren);
}

void			prep(t_main_var *var)
{
	var->ren = init("WolfWoof");
	var->quit = 0;
	var->posx = 22;
	var->posy = 12;
	var->dirx = -1;
	var->diry = 0;
	var->planex = 0;
	var->planey = 0.66;
	var->time = 0;
	var->oldtime = 0;
	var->x = 0;
	var->w = 640;
	var->h = 480;
	var->worldmap = NULL;
	var->fd = open(var->file, O_RDONLY);
	var->size = get_size(var->fd);
	var->worldmap = allocate_map(var->size, var->worldmap);
	close(var->fd);
	var->fd = open(var->file, O_RDONLY);
	populate_map(var->fd, var->worldmap, var->size);
}

int				main(int argc, char **argv)
{
	t_main_var		var;

	var.file = argv[1];
	if (argc == 2)
	{
		if (ft_strrchr(var.file, '.') == NULL)
		{
			ft_putstr("Incorrect file\n");
			exit(-1);
		}
		if (ft_strcmp(".txt", ft_strrchr(var.file, '.')) != 0)
		{
			ft_putstr("Wrong File\n");
			exit(-1);
		}
		else
		{
			prep(&var);
			execute(&var);
		}
	}
	else
		ft_putstr("Invalid File: Please enter file name");
	SDL_Quit();
	return (0);
}
