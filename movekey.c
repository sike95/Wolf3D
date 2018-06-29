/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movekey.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:10:58 by mmpofu            #+#    #+#             */
/*   Updated: 2017/11/23 08:56:42 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		up_right(t_main_var *var)
{
	if (var->event.key.keysym.sym == SDLK_UP)
	{
		if (!(var->worldmap[var->myv][(int)(var->posy)]))
			var->posx += var->dirx * var->movespeed;
		if (!(var->worldmap[(int)(var->posx)][var->myy]))
			var->posy += var->diry * var->movespeed;
	}
	if (var->event.key.keysym.sym == SDLK_RIGHT)
	{
		var->olddirx = var->dirx;
		var->dirx = var->dirx * cos(-var->rotspeed)
			- var->diry * sin(-var->rotspeed);
		var->diry = var->olddirx * sin(-var->rotspeed)
			+ var->diry * cos(-var->rotspeed);
		var->oldplanex = var->planex;
		var->planex = var->planex * cos(-var->rotspeed)
			- var->planey * sin(-var->rotspeed);
		var->planey = var->oldplanex * sin(-var->rotspeed)
			+ var->planey * cos(-var->rotspeed);
	}
	return (0);
}

int		down_left(t_main_var *var)
{
	if (var->event.key.keysym.sym == SDLK_DOWN)
	{
		if (!(var->worldmap[var->myv][(int)(var->posy)]))
			var->posx -= var->dirx * var->movespeed;
		if (!(var->worldmap[(int)(var->posx)][var->myy]))
			var->posy -= var->diry * var->movespeed;
	}
	if (var->event.key.keysym.sym == SDLK_LEFT)
	{
		var->olddirx = var->dirx;
		var->dirx = var->dirx * cos(var->rotspeed)
			- var->diry * sin(var->rotspeed);
		var->diry = var->olddirx * sin(var->rotspeed) + var->diry
			* cos(var->rotspeed);
		var->oldplanex = var->planex;
		var->planex = var->planex * cos(var->rotspeed)
			- var->planey * sin(var->rotspeed);
		var->planey = var->oldplanex * sin(var->rotspeed)
			+ var->planey * cos(var->rotspeed);
	}
	return (0);
}

int		key_hook(t_main_var *var)
{
	if (var->event.type == SDL_KEYDOWN)
	{
		up_right(&(*var));
		down_left(&(*var));
		if (var->event.key.keysym.sym == SDLK_ESCAPE)
		{
			var->quit = 1;
		}
	}
	return (0);
}
