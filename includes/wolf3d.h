/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <aroi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:48:20 by aroi              #+#    #+#             */
/*   Updated: 2019/03/14 12:31:45 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <fcntl.h>
# include <math.h>

# include "libft.h"
# include "get_next_line.h"
# include "SDL.h"
# include "SDL_image.h"
// # include "SDL_thread.h"
# include "SDL_ttf.h"

# define ANGLE_PI_4			0.7071

# define SCREEN_WIDTH		1366
# define SCREEN_HEIGHT		768
# define THREADS			2
# define ACTION_KEY_NUMBER	5
# define TEXTURE_NUMBER		7
# define MAX_LENGTH			100
/*
**	Cardinal directions
*/
# define NORTH				0
# define SOUTH				1
# define WEST				2
# define EAST				3

# define BAD_N_K			"Bad n input or line problems.\n\
(no whitespaces between cells)"

typedef struct		s_vector_int
{
	int				x;
	int				y;
}					t_vector_int;

typedef struct		s_vector_double
{
	double			x;
	double			y;
}					t_vector_double;

typedef	struct		s_raycast
{
	t_vector_double	curr;
	t_vector_int	texel;
}					t_raycast;


typedef struct		s_draw_strip
{
	int				start;
	int				end;
}					t_draw_strip;

typedef struct		s_player
{
	t_vector_double	pos;
	//vector
	t_vector_double	dir;
	//directory vector
	t_vector_double	plane;
	//plane vector, FOV = 2 * arctg(plane_v / dir_v)
	double camerax;
	t_vector_double	ray_dir;
	//camera, ray
	t_vector_int	map;
	t_vector_double	delta_dist;
	double			perp_walldist;
	int				direction;
	double			wall_hit;
	double moveSpeed; //the constant value is in squares/second
    double rotSpeed;
	char			move[ACTION_KEY_NUMBER];
	t_raycast		wall;
	t_raycast		floor;
	//speed
}					t_player;

typedef struct		s_cell
{
	char			type;
	int				number;
}					t_cell;

typedef struct		s_map
{
	int				m;
	int				n;
	t_cell			**cell;
}					t_map;

typedef struct		s_fps
{
	double			old;
	double			new;
	double			fps;
}					t_fps;

typedef struct		s_texture
{
	SDL_Surface		*surf;
	Uint32			*data;

}					t_texture;

typedef struct		s_thread
{
	int				start;
	int				end;
}					t_thread;

typedef struct		s_wolf3d
{
	SDL_Window		*win;
	SDL_Surface		*scr;
	SDL_Renderer	*rend;
	SDL_Texture		*texture;
	TTF_Font		*font;
	// Uint32			buff[SCREEN_HEIGHT * SCREEN_WIDTH];
	Uint32			*buff;
	t_texture		txt[TEXTURE_NUMBER];
	t_map			*map;
	t_player		pl;
	t_draw_strip	strip;
	t_fps			fps;
	t_thread		thread;
}					t_wolf3d;

t_wolf3d	*create_wolf(void);
void		init(t_wolf3d *wolf);
int			event_handler(t_wolf3d *wolf);
void		close_wolf(t_wolf3d *wolf);
int			exit_func(char *str);
void	add_char_in(char list[3], char c);
void	remove_char_from(char list[3], char c);
int		is_char_in(char list[3], char c);
void	divide_into_threads(t_wolf3d *wolf);

#endif
