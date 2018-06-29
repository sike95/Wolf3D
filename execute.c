/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:59:45 by mmpofu            #+#    #+#             */
/*   Updated: 2018/06/29 10:58:02 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		execute(t_main_var *var)
{
	while (!var->quit)
	{
		SDL_SetRenderDrawColor(var->ren, 0, 0, 0, 255);
		SDL_RenderClear(var->ren);
		var->x = 0;
		raycaster(&(*var));
		var->oldtime = var->time;
		var->time = SDL_GetTicks();
		var->frametime = (var->time - var->oldtime) / 1000.0;
		SDL_RenderPresent(var->ren);
		SDL_RenderClear(var->ren);
		var->movespeed = var->frametime * 5.0;
		var->rotspeed = var->frametime * 8.0;
		while (SDL_PollEvent(&(var->event)))
		{
			var->myv = var->posx + var->dirx * var->movespeed;
			var->myy = var->posy + var->diry * var->movespeed;
			key_hook(&(*var));
		}
		if (var->event.type == SDL_QUIT)
			var->quit = 1;
	}
	return (0);
}
