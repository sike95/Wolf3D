/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:31:12 by mmpofu            #+#    #+#             */
/*   Updated: 2017/11/20 18:51:42 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include<sdl.h>
#define mapWidth 24
#define mapHeight 24

SDL_Renderer	*init(char *title)
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window *win = SDL_CreateWindow(title, 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
	SDL_RenderClear(ren);
	SDL_RenderPresent(ren);
	return (ren);
}

int col_convert(int r, int g, int b)
{
	int   hexValue;
	hexValue = r << 16;
	hexValue += g << 8;
	hexValue += b;
	return (hexValue);
}

int main() {

	SDL_Renderer	*ren;
	SDL_Event		event;
	double			posX;
	double			posY;
	double			dirX;
	double			dirY;
	double			planeX;
	double			planeY;
	double			time;
	int				quit;
	int				x;
	//	int				y;
	int				w;
	int				h;
	double			cameraX;
	double			rayPosX;
	double			rayPosY;
	double			rayDirX;
	double			rayDirY;
	int				mapX;
	int				mapY;
	double			sideDistX;
	double			sideDistY;
	double			deltaDistX;
	double			deltaDistY;
	double			perpWallDist;
	int 			stepX;
	int 			stepY;
	int 			lineHeight;
	int				oldTime;
	int 			Myv;
	int				Myy;

	int worldmap[mapWidth][mapHeight] =
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

	ren = init("WolfWoof");
	quit = 0;
	posX = 22;
	posY = 12;
	dirX = -1;
	dirY = 0;
	planeX = 0;
	planeY = 0.66;
	time = 0;
	oldTime = 0;
	x = 0;
	w = 640;
	h = 480;
	while (!quit)
	{
		while (x < w)
		{
			cameraX = 2 * x / (double)(w) - 1; //x-coordinate in camera space
			rayPosX = posX;
			rayPosY = posY;
			rayDirX = dirX + planeX * cameraX;
			rayDirY = dirY + planeY * cameraX;

			mapX   = rayPosX;
			mapY   = rayPosY;

			deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
			deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));

			int hit = 0; //was there a wall hit?
			int side; //was a NS or a EW wall hit?
			if (rayDirX < 0)
			{
				stepX = -1;
				sideDistX = (rayPosX - mapX) * deltaDistX;
			}
			else
			{
				stepX = 1;
				sideDistX = (mapX + 1.0 - rayPosX) * deltaDistX;
			}
			if (rayDirY < 0)
			{
				stepY = -1;
				sideDistY = (rayPosY - mapY) * deltaDistY;
			}
			else
			{
				stepY = 1;
				sideDistY = (mapY + 1.0 - rayPosY) * deltaDistY;
			}
			while (hit == 0)
			{
				//jump to next map square, OR in x-direction, OR in y-direction
				if (sideDistX < sideDistY)
				{
					sideDistX += deltaDistX;
					mapX += stepX;
					side = 0;
				}
				else
				{
					sideDistY += deltaDistY;
					mapY += stepY;
					side = 1;
				}
				//Check if ray has hit a wall
				if (worldmap[mapX][mapY] > 0) hit = 1;
				//x++;
			}
			if (side == 0)
				perpWallDist = (mapX - rayPosX + (1 - stepX) / 2) / rayDirX;
			else
				perpWallDist = (mapY - rayPosY + (1 - stepY) / 2) / rayDirY;
			lineHeight = (int)(h / perpWallDist);

			int drawStart = -lineHeight / 2 + h / 2;
			if(drawStart < 0)
				drawStart = 0;
			int drawEnd = lineHeight / 2 + h / 2;
			if(drawEnd >= h)
				drawEnd = h - 1;
			int color;

			switch(worldmap[mapX][mapY])
			{
				case 1:  color = col_convert(255, 0, 0);  break; //red
				case 2:  color = col_convert(0, 255, 0);  break; //green
				case 3:  color = col_convert(0, 0, 255);   break; //blue
				case 4:  color = col_convert(255, 255, 255);  break; //white
				default: color = col_convert(255, 255, 0); break; //yellow
			}
			if (side == 1) 
			{
				color = color / 2;
			}
			SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
			SDL_RenderClear(ren);
			printf("Start: %d | End: %d\n", drawStart, drawEnd);
			//	verLine(x, drawStart, drawEnd, ff0000);
			SDL_RenderDrawPoint(ren, drawStart, drawEnd);
			x++;
			
		}
		oldTime = time;
		time = SDL_GetTicks();
		double frameTime = (time - oldTime) / 1000.0;
		//printf("%f", 1.0 / frameTime);
		SDL_RenderPresent(ren);
		//cls();
		double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
		double rotSpeed = frameTime * 3.0; //the constant value is in radians/second
		while (SDL_PollEvent(&event))
		{
			Myv = posX + dirX * moveSpeed;
			Myy = posY + dirY * moveSpeed;
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_UP)
				{
					if(!(worldmap[Myv][(int)(posY)]))
						posX += dirX * moveSpeed;
					if(!(worldmap[(int)(posX)][Myy])) 
						posY += dirY * moveSpeed;
				}
				if (event.key.keysym.sym == SDLK_DOWN)
				{
					if(!(worldmap[Myv][(int)(posY)]))
						posX -= dirX * moveSpeed;
					if(!(worldmap[(int)(posX)][Myy]))
						posY -= dirY * moveSpeed;
				}
				if (event.key.keysym.sym == SDLK_RIGHT)
				{
					double oldDirX = dirX;
					dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
					dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
					double oldPlaneX = planeX;
					planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
					planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
				}
				if (event.key.keysym.sym == SDLK_LEFT)
				{
					double oldDirX = dirX;
					dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
					dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
					double oldPlaneX = planeX;
					planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
					planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);

				}
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					quit = 1;
				}
				else if (event.key.keysym.sym == SDLK_x)
				{
					SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
					SDL_RenderClear(ren);
					SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
					SDL_RenderDrawPoint(ren, 50, 50);
					SDL_RenderPresent(ren);
				}

			}


		}
		if (event.type == SDL_QUIT)
		{
			quit = 1;
		}
	}
	SDL_Quit();
	return (0);
}	
