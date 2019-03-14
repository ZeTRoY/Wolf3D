#include "wolf3d.h"

static int	key_up(SDL_Keycode sym, t_wolf3d *wolf)
{
	if (sym == SDL_SCANCODE_ESCAPE)
		return (0);
	if (sym == SDL_SCANCODE_W)
		remove_char_from(wolf->pl.move, 'w');
	else if (sym == SDL_SCANCODE_S)
		remove_char_from(wolf->pl.move, 's');
	else if (sym == SDL_SCANCODE_D)
		remove_char_from(wolf->pl.move, 'd');
	else if (sym == SDL_SCANCODE_A)
		remove_char_from(wolf->pl.move, 'a');
	else if (sym == SDL_SCANCODE_LSHIFT)
	{
		remove_char_from(wolf->pl.move, 'l');
		wolf->pl.rotSpeed = 0.018;
	}
	return (1);
}

static int	key_down(SDL_Keycode sym, t_wolf3d *wolf)
{
	if (sym == SDL_SCANCODE_ESCAPE)
		return (0);
	else
	{
		if (sym == SDL_SCANCODE_W && !is_char_in(wolf->pl.move, 'w'))
			add_char_in(wolf->pl.move, 'w');
		else if (sym == SDL_SCANCODE_S && !is_char_in(wolf->pl.move, 's'))
			add_char_in(wolf->pl.move, 's');
		else if (sym == SDL_SCANCODE_A && !is_char_in(wolf->pl.move, 'a'))
			add_char_in(wolf->pl.move, 'a');
		else if (sym == SDL_SCANCODE_D && !is_char_in(wolf->pl.move, 'd'))
			add_char_in(wolf->pl.move, 'd');
		else if (sym == SDL_SCANCODE_LSHIFT && !is_char_in(wolf->pl.move, 'l'))
		{
			add_char_in(wolf->pl.move, 'l');
			wolf->pl.rotSpeed = 0.03;
		}
	}
	return (1);
}

int			event_handler(t_wolf3d *wolf)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			return (0);
		else if (event.type == SDL_KEYDOWN)
			return (key_down(event.key.keysym.scancode, wolf));
		else if (event.type == SDL_KEYUP)
			return (key_up(event.key.keysym.scancode, wolf));
		else
			return (-1);
	}
	return (-228);
}
