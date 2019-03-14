/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <aroi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 18:09:09 by aroi              #+#    #+#             */
/*   Updated: 2019/03/13 18:21:31 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_wolf3d	*create_wolf(void)
{
	t_wolf3d *wolf;

	wolf = (t_wolf3d *)malloc(sizeof(t_wolf3d));
	wolf->map = (t_map *)malloc(sizeof(t_map));
	return (wolf);
}

void	init(t_wolf3d *wolf)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		exit_func("Initialisation problem.");
	if ((wolf->win = SDL_CreateWindow("Wolf3D", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,
				SDL_WINDOW_SHOWN)) == NULL)
		exit_func("Creating window problem has been deteced.");
	if ((wolf->rend = SDL_CreateRenderer(wolf->win, -1,
			SDL_RENDERER_ACCELERATED)) == NULL)
		exit_func("Renderer problems.");
	SDL_SetRenderDrawColor(wolf->rend, 0xFF, 0xFF, 0xFF, 0xFF);
	if (!(IMG_Init(IMG_INIT_PNG) & (IMG_INIT_PNG)))
		exit_func("Initialising image problem has occured.");
	wolf->font = NULL;
	wolf->texture = SDL_CreateTexture(wolf->rend, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (TTF_Init() == -1)
		exit_func("Initialising ttf problem has occured.");
	wolf->buff = (Uint32 *)malloc(sizeof(Uint32) * (SCREEN_HEIGHT * SCREEN_WIDTH));
}

void	close_wolf(t_wolf3d *wolf)
{
	TTF_CloseFont(wolf->font);
	SDL_DestroyTexture(wolf->texture);
	SDL_DestroyRenderer(wolf->rend);
	SDL_DestroyWindow(wolf->win);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}
