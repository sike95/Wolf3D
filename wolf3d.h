/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woldf3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:40:22 by mmpofu            #+#    #+#             */
/*   Updated: 2018/06/29 10:53:57 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdio.h>
# include <SDL.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_row_col
{
	int				row;
	int				col;
}					t_row_col;

typedef struct		s_main_var
{
	SDL_Renderer	*ren;
	SDL_Event		event;
	t_row_col		size;
	char			*file;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			time;
	int				quit;
	int				x;
	int				w;
	int				h;
	double			camerax;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				lineheight;
	int				oldtime;
	int				hit;
	int				side;
	int				drawstart;
	int				myv;
	int				myy;
	int				drawend;
	int				fd;
	int				yy;
	int				**worldmap;
	double			frametime;
	double			movespeed;
	double			rotspeed;
	double			olddirx;
	double			oldplanex;
	int				i;
	int				cnt;
	int				flag;
	char			*line;
	char			**split;
}					t_main_var;

int					execute(t_main_var *var);
int					key_hook(t_main_var *var);
int					raycaster(t_main_var *var);
t_row_col			get_size(int fd);
int					**allocate_map(t_row_col size, int **temp_map);
int					populate_map(int fd, int **map, t_row_col size);
int					ray_dir(t_main_var *var);
int					ren_move(t_main_var *var);
int					up_right(t_main_var *var);
void				ren_calc(t_main_var *var);
int					down_left(t_main_var *var);
#endif
