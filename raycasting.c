/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:02:00 by mmpofu            #+#    #+#             */
/*   Updated: 2018/06/29 11:00:02 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			ray_dir(t_main_var *var)
{
	var->hit = 0;
	if (var->raydirx < 0)
	{
		var->stepx = -1;
		var->sidedistx = (var->rayposx - var->mapx) * var->deltadistx;
	}
	else
	{
		var->stepx = 1;
		var->sidedistx = (var->mapx + 1.0 - var->rayposx) * var->deltadistx;
	}
	if (var->raydiry < 0)
	{
		var->stepy = -1;
		var->sidedisty = (var->rayposy - var->mapy) * var->deltadisty;
	}
	else
	{
		var->stepy = 1;
		var->sidedisty = (var->mapy + 1.0 - var->rayposy) * var->deltadisty;
	}
	return (0);
}

int			ren_move(t_main_var *var)
{
	while (var->hit == 0)
	{
		if (var->sidedistx < var->sidedisty)
		{
			var->sidedistx += var->deltadistx;
			var->mapx += var->stepx;
			var->side = 0;
		}
		else
		{
			var->sidedisty += var->deltadisty;
			var->mapy += var->stepy;
			var->side = 1;
		}
		if (var->worldmap[var->mapx][var->mapy] > 0)
			var->hit = 1;
	}
	return (0);
}

void		ren_calc(t_main_var *var)
{
	if (var->side == 0)
		var->perpwalldist = (var->mapx - var->rayposx +
				(1 - var->stepx) / 2) / var->raydirx;
	else
		var->perpwalldist = (var->mapy - var->rayposy
				+ (1 - var->stepy) / 2) / var->raydiry;
	var->lineheight = (int)(var->h / var->perpwalldist);
	var->drawstart = -var->lineheight / 2 + var->h / 2;
	if (var->drawstart < 0)
		var->drawstart = 0;
	var->drawend = var->lineheight / 2 + var->h / 2;
	if (var->drawend >= var->h)
		var->drawend = var->h - 1;
}

int			ren_color(t_main_var *var)
{
	while (var->yy < var->drawend)
	{
		if (0 == var->side)
		{
			if (0 > var->stepx)
				SDL_SetRenderDrawColor(var->ren, 255, 0, 0, 255);
			else
				SDL_SetRenderDrawColor(var->ren, 0, 255, 0, 255);
		}
		else if (0 > var->stepy)
			SDL_SetRenderDrawColor(var->ren, 0, 0, 255, 255);
		else
			SDL_SetRenderDrawColor(var->ren, 255, 255, 0, 255);
		SDL_RenderDrawPoint(var->ren, var->x, var->yy);
		var->yy++;
	}
	return (0);
}

int			raycaster(t_main_var *var)
{
	while (var->x < var->w)
	{
		var->camerax = 2 * var->x / (double)(var->w) - 1;
		var->rayposx = var->posx;
		var->rayposy = var->posy;
		var->raydirx = var->dirx + var->planex * var->camerax;
		var->raydiry = var->diry + var->planey * var->camerax;
		var->mapx = var->rayposx;
		var->mapy = var->rayposy;
		var->deltadistx = sqrt(1 + (var->raydiry * var->raydiry)
				/ (var->raydirx * var->raydirx));
		var->deltadisty = sqrt(1 + (var->raydirx * var->raydirx)
				/ (var->raydiry * var->raydiry));
		ray_dir(&(*var));
		ren_move(&(*var));
		ren_calc(&(*var));
		var->yy = var->drawstart;
		ren_color(&(*var));
		var->x++;
	}
	return (0);
}
