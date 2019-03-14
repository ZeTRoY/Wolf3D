/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <aroi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:46:37 by aroi              #+#    #+#             */
/*   Updated: 2019/03/14 14:38:00 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h" //division by 0

int		is_not_determined(const char *line, int *k, t_map *map, int j, int i)
{
	if (line[*k] == '0')
	{
		if (j == 0 || j == map->n - 1 || i == 0 || i == map->m - 1 || ft_isdigit(line[*k + 1]))
			return (1);
		map->cell[i][j].type = 0;
		map->cell[i][j].number = 0;
		(*k)++;
		return (0);
	}
	else
		return (1);
}

void	check_for_n_lineend(t_map *map, const char *line, int k, int j, int n)
{
	ft_skip_whitespaces(line, &k);
	if (line[k] || j != n)
	{
		free(map->cell[0]);
		write(1, "sos\n", 4);
		exit_func("sosat");
	}
}

void	get_cells(t_map *map, const char *line, int i)
{
	int j;
	int k;

	k = 0;
	j = -1;
	while (++j < map->n && line[k])
	{
		!ft_is_whitespace(line[k]) && k > 0 ? exit_func(BAD_N_K) : 0;
		ft_skip_whitespaces(line, &k);
		if (line[k] == 'w')
		{
			j == 0 ? (map->cell[i] = (t_cell *)malloc(sizeof(t_cell) * map->n)) : 0;//segfault? check_many_times!!!!!!!!!!
			// system("leaks wolf3d");
			map->cell[i][j].type = line[k++];
			if ((map->cell[i][j].number = ft_atoi(line + k)) <= 0 ||
					map->cell[i][j].number > TEXTURE_NUMBER)
				break ;
			k += ft_count_digits_base(map->cell[i][j].number, 10);
		}
		else if (is_not_determined(line, &k, map, j, i))
			break ;
	}
	ft_printf("%d\n", j);
	check_for_n_lineend(map, line, k, j, map->n);
}

int		is_bad_edge_elems(t_map *map, int m)
{
	int i;
	int j;

	i = 0;
	while (i < m)
	{
		j = 0;
		while (j < map->n)
		{
			if ((i == 0 || i == map->m - 1 || j == 0 || j == map->n - 1) &&
					map->cell[i][j].type != 'w')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	free_map(t_map **map)
{
	int i;
	int j;

	i = 0;
	while (i < (*map)->m)
	{
		// if ((*map)->cell[i])
		// 	free((*map)->cell[i]);
		i++;
	}
	// free((*map)->cell);
}

void	get_map(t_wolf3d *wolf, int fd, char **line)
{
	int i;
	int gnl;

	*line = NULL;
	i = 0;
	wolf->map->cell = (t_cell **)malloc(sizeof(t_cell *) * wolf->map->m);
	while ((gnl = get_next_line(fd, line) > 0) && **line)
	{
		if (i >= wolf->map->m)
			exit_func("Bad map input (m). Too big size.");
		get_cells(wolf->map, *line, i);
		ft_strdel(line);
		i++;
	}
	if (gnl < 0 || (gnl == 0 && i == 0) || i != wolf->map->m)
	{
		while (--i >= 0)
			free(wolf->map->cell[i]);
		exit_func("Bad map input (m).");
	}
	// if (is_bad_edge_elems(wolf->map, i))
	// 	exit_func("Bad input (m or n). Edge elements shold be walls!.");
}

void	get_two_numbers(char *line, int *x, int *y)
{
	int i;

	i = 0;
	ft_skip_whitespaces(line, &i);
	ft_printf("x:%d\n", ft_atoi(line + i));
	if ((*x = ft_atoi(line + i)) < 0 || !ft_isdigit(line[i]))
		exit_func("Bad first number.");
	i += ft_count_digits_base(*x, 10);
	ft_skip_whitespaces(line, &i);
	ft_printf("y:%d\n", ft_atoi(line + i));
	if ((*y = ft_atoi(line + i)) < 0 || !ft_isdigit(line[i]))
		exit_func("Bad second number.");
	//mb add additional check after this point
}

void	parse_map(t_wolf3d *wolf, char *str)
{
	int		fd;
	char	*line;
	int		tmp_x;
	int		tmp_y;

	line = NULL;
	fd = open(str, O_RDONLY);
	if (get_next_line(fd, &line) < 0 || line == NULL || line[0] == 0)
		exit_func("Couldn't read first line of map.");
	get_two_numbers(line, &wolf->map->m, &wolf->map->n);
	wolf->map->m == 0 || wolf->map->n == 0 ? exit_func("Bad row/clmn qnt") : 0;
	// wolf->map->m > 10000 || wolf->map->n > 10000 ? exit_func("Too big size of map (m||n)") : 0;
	ft_strdel(&line);
	if (get_next_line(fd, &line) < 0 || line == NULL || line[0] == 0)
		exit_func("Couldn't read second line of map.");
	get_two_numbers(line, &tmp_y, &tmp_x); //pos[i][j]
	wolf->pl.pos.x = (double)tmp_x + 0.5;
	wolf->pl.pos.y = (double)tmp_y + 0.5;
	ft_strdel(&line);
	get_map(wolf, fd, &line);
	close(fd);
	if (tmp_y >= wolf->map->m || tmp_x >= wolf->map->n ||
			wolf->map->cell[(int)wolf->pl.pos.y][(int)wolf->pl.pos.x].type != 0)
		exit_func("Bad player position.");
}

void	get_ceiling_floor(t_wolf3d *wolf)
{
	SDL_Rect ceiling;
	SDL_Rect floor_c;
	
	ceiling.x = 0;
	ceiling.y = 0;
	ceiling.w = SCREEN_WIDTH;
	ceiling.h = SCREEN_HEIGHT / 2;
	floor_c.x = 0;
	floor_c.y = SCREEN_HEIGHT / 2;
	floor_c.w = SCREEN_WIDTH;
	floor_c.h = SCREEN_HEIGHT / 2;
	SDL_SetRenderDrawColor(wolf->rend, 0xFF, 0, 0, 0xFF);
	SDL_RenderFillRect(wolf->rend, &floor_c);
	SDL_SetRenderDrawColor(wolf->rend, 0xFF, 0, 0xFF, 0xFF);
	SDL_RenderFillRect(wolf->rend, &ceiling);
}

void	put_text(t_wolf3d *wolf, char *str, int size, int x, int y)
{
	SDL_Color	textcolor = {0,0,0};
	SDL_Surface	*tmp;
	SDL_Texture *texture;
	SDL_Rect rend;

	if (wolf->font != NULL)
		TTF_CloseFont(wolf->font);
	if ((wolf->font = TTF_OpenFont("fonts/SwedieCruel.ttf", size)) == NULL)
		exit_func("Bad ttf loading.");
	if ((tmp = TTF_RenderText_Solid(wolf->font, str, textcolor)) == NULL)
		exit_func("Bad font rendering to surface.");
	if (!(texture = SDL_CreateTextureFromSurface(wolf->rend, tmp)))
		exit_func("Bad font rendering from surface.");
	rend.x = x;
	rend.y = y;
	rend.w = tmp->w;
	rend.h = tmp->h;
	SDL_RenderCopyEx(wolf->rend, texture, NULL, &rend, 0, NULL, 0);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(tmp);
}


void	clear_buff(Uint32 buff[SCREEN_HEIGHT * SCREEN_WIDTH])
{
	int i;
	int j;

	i = 0;
	while (i < SCREEN_HEIGHT)
	{
		j = 0;
		while (j < SCREEN_WIDTH)
		{
			buff[i * SCREEN_WIDTH + j] = 0xF81894;
			j++;
		}
		i++;
	}
}

void	add_char_in(char list[ACTION_KEY_NUMBER], char c)
{
	int j;

	j = 0;
	while (j < ACTION_KEY_NUMBER)
	{
		if (list[j] == 0)
		{
			list[j] = c;
			break ;
		}
		j++;
	}
}

void	remove_char_from(char list[ACTION_KEY_NUMBER], char c)
{
	int j;

	j = ACTION_KEY_NUMBER;
	while (--j >= 0)
	{
		if (list[j] == c)
		{
			list[j] = 0;
			break ;
		}
	}
}

int		is_char_in(char list[ACTION_KEY_NUMBER], char c)
{
	int j;

	j = 0;
	while (j < ACTION_KEY_NUMBER)
	{
		if (list[j++] == c)
			return (1);
	}
	return (0);
}

void	get_floor_wall(t_player player, double floor[2])
{
	floor[0] = (double)player.map.x;
	floor[1] = (double)player.map.y;
	if (player.direction == EAST || player.direction == WEST)
	{
		floor[1] += player.wall_hit;
		if (player.ray_dir.x < 0)
			floor[0] += 1.0;
	}
	else
	{
		floor[0] += player.wall_hit;
		if (player.ray_dir.y < 0)
			floor[1] += 1.0;
	}
}

void	buffer_floor_ceiling(t_wolf3d *wolf, int j, int x, double floor_wall[2])
{
	double	coeff;

	coeff = SCREEN_HEIGHT / (2.0 * j - SCREEN_HEIGHT) /
		wolf->pl.perp_walldist;
	wolf->pl.floor.curr.x = coeff * floor_wall[0] +
		(1.0 - coeff) * wolf->pl.pos.x;
	wolf->pl.floor.curr.y = coeff * floor_wall[1] +
		(1.0 - coeff) * wolf->pl.pos.y;
	wolf->pl.floor.texel.x = (int)(wolf->pl.floor.curr.x *
		wolf->txt[4].surf->w) % wolf->txt[4].surf->w;
	wolf->pl.floor.texel.y = (int)(wolf->pl.floor.curr.y *
		wolf->txt[4].surf->h) % wolf->txt[4].surf->h;
	wolf->buff[j * SCREEN_WIDTH + x] = (((Uint32 *)
		(wolf->txt[4].surf->pixels))[wolf->txt[4].surf->h *
		wolf->pl.floor.texel.y + wolf->pl.floor.texel.x] >> 1) &
		8355711;
	wolf->pl.floor.texel.x = (int)(wolf->pl.floor.curr.x *
		wolf->txt[5].surf->w) % wolf->txt[5].surf->w;
	wolf->pl.floor.texel.y = (int)(wolf->pl.floor.curr.y *
		wolf->txt[5].surf->h) % wolf->txt[5].surf->h;
	wolf->buff[(SCREEN_HEIGHT - j) * SCREEN_WIDTH + x] = ((Uint32 *)
		(wolf->txt[5].surf->pixels))[wolf->txt[5].surf->h *
			wolf->pl.floor.texel.y + wolf->pl.floor.texel.x];
}

void	floorcasting(t_wolf3d *wolf, int x)
{
	double	floor_wall[2];
	int		j;

	get_floor_wall(wolf->pl, floor_wall);
	if (wolf->strip.end < 0)
		wolf->strip.end = SCREEN_HEIGHT;
	j = wolf->strip.end;
	if (j + 1 < SCREEN_HEIGHT)
	{
		while (++j < SCREEN_HEIGHT)
			buffer_floor_ceiling(wolf, j, x, floor_wall);
		wolf->buff[x] = ((Uint32 *)(wolf->txt[5].surf->pixels))
			[wolf->txt[5].surf->w * wolf->pl.floor.texel.y +
			wolf->pl.floor.texel.x];		
	}
}

void	rotate_player(t_player *player, double rot_speed)
{
	double old_dirx;
	double old_planex;
	
	old_dirx = player->dir.x;
    player->dir.x = player->dir.x * cos(rot_speed) -
		player->dir.y * sin(rot_speed);
    player->dir.y = old_dirx * sin(rot_speed) +
		player->dir.y * cos(rot_speed);
    old_planex = player->plane.x;
    player->plane.x = player->plane.x * cos(rot_speed) -
		player->plane.y * sin(rot_speed);
    player->plane.y = old_planex * sin(rot_speed) +
		player->plane.y * cos(rot_speed);
}

void	move_player_backward(t_player *player, t_cell **cell)
{
	int steps;

	steps = is_char_in(player->move, 'l') ? 3 : 1;
	while (steps-- > 0)
	{
    	if (cell[(int)(player->pos.y)][(int)(player->pos.x -
				8 * player->dir.x * player->moveSpeed)].type != 'w')
			player->pos.x -= player->dir.x * player->moveSpeed;
    	if (cell[(int)(player->pos.y - 8 * player->dir.y * player->moveSpeed)]
				[(int)(player->pos.x)].type != 'w')
			player->pos.y -= player->dir.y * player->moveSpeed;
	}
}

void	move_player_forward(t_player *player, t_cell **cell)
{
	int steps;

	steps = is_char_in(player->move, 'l') ? 3 : 1;
	while (steps-- > 0)
	{
		if (cell[(int)(player->pos.y)][(int)(player->pos.x +
				8 * player->dir.x * player->moveSpeed)].type != 'w')
			player->pos.x += player->dir.x * player->moveSpeed;
		if (cell[(int)(player->pos.y + 8 * player->dir.y * player->moveSpeed)]
				[(int)(player->pos.x)].type != 'w')
			player->pos.y += player->dir.y * player->moveSpeed;
	}
}

void	move_rotate(t_player *player, t_cell **cell)
{
    if ((is_char_in(player->move, 'd') && !is_char_in(player->move, 'a')) ||
			(!is_char_in(player->move, 'd') && is_char_in(player->move, 'a')))
	{
    	if (is_char_in(player->move, 'd'))
			rotate_player(player, -player->rotSpeed);
    	if (is_char_in(player->move, 'a'))
			rotate_player(player, player->rotSpeed);
	}
	// int i = 0;
	// while (player->move[i] && i < ACTION_KEY_NUMBER)
	// 	ft_putchar(player->move[i++]);
	// write(1, "\n", 1);
    if ((is_char_in(player->move, 'w') && !is_char_in(player->move, 's')) ||
			(!is_char_in(player->move, 'w') && is_char_in(player->move, 's')))
	{
		if (is_char_in(player->move, 'w'))
			move_player_forward(player, cell);
	    if (is_char_in(player->move, 's'))
			move_player_backward(player, cell);
	}
}

void	get_players_env(t_wolf3d *wolf, int *stepx, int *stepy, int x)
{
	wolf->pl.camerax = 2.0 * x / (double)SCREEN_WIDTH - 1.0;
	wolf->pl.ray_dir.x = wolf->pl.dir.x + wolf->pl.plane.x * wolf->pl.camerax;
	wolf->pl.ray_dir.y = wolf->pl.dir.y + wolf->pl.plane.y * wolf->pl.camerax;
	wolf->pl.map.x = (int)wolf->pl.pos.x;
	wolf->pl.map.y = (int)wolf->pl.pos.y;
	wolf->pl.delta_dist.x = fabs(1.0 / wolf->pl.ray_dir.x);
	wolf->pl.delta_dist.y = fabs(1.0 / wolf->pl.ray_dir.y);
	*stepx = wolf->pl.ray_dir.x > 0.0 ? 1 : -1;
	*stepy = wolf->pl.ray_dir.y > 0.0 ? 1 : -1;
	if (wolf->pl.ray_dir.x < 0.0)
		wolf->pl.wall.curr.x = (wolf->pl.pos.x - (double)wolf->pl.map.x) *
			wolf->pl.delta_dist.x;
	else
		wolf->pl.wall.curr.x = ((double)wolf->pl.map.x + 1.0 - wolf->pl.pos.x) *
			wolf->pl.delta_dist.x;
	if (wolf->pl.ray_dir.y < 0.0)
		wolf->pl.wall.curr.y = (wolf->pl.pos.y - (double)wolf->pl.map.y) *
			wolf->pl.delta_dist.y;
	else
		wolf->pl.wall.curr.y = ((double)wolf->pl.map.y + 1.0 - wolf->pl.pos.y) *
			wolf->pl.delta_dist.y;
}

Uint32	get_color(t_wolf3d *wolf, Uint32 color, double fog_coeff)
{
	Uint8 r;
	Uint8 g;
	Uint8 b;

	r = (Uint8)(color >> 16 & 0xFF) * (1.0 - fog_coeff) + fog_coeff * (Uint8)(((Uint32 *)wolf->txt[6].surf->pixels)[wolf->txt[6].surf->w * wolf->pl.wall.texel.y + wolf->pl.wall.texel.x] >> 16 & 0xFF);
	g = (Uint8)(color >> 8 & 0xFF) * (1.0 - fog_coeff) + fog_coeff * (Uint8)(((Uint32 *)wolf->txt[6].surf->pixels)[wolf->txt[6].surf->w * wolf->pl.wall.texel.y + wolf->pl.wall.texel.x] >> 8 & 0xFF);
	b = (Uint8)(color & 0xFF) * (1.0 - fog_coeff) + fog_coeff * (Uint8)(((Uint32 *)wolf->txt[6].surf->pixels)[wolf->txt[6].surf->w * wolf->pl.wall.texel.y + wolf->pl.wall.texel.x] & 0xFF);
	return (r << 16 | g << 8 | b);
}

void	buffer_fog(t_wolf3d *wolf, int lineheight, int x)
{
	int		j;
	int		d;
	Uint32	color;

	j = wolf->strip.start;
	while (j <= wolf->strip.end)
	{
		d = (j << 1) - SCREEN_HEIGHT + lineheight;
		wolf->pl.wall.texel.y = lineheight == 0 ? 0 :
			((d * wolf->txt[6].surf->w) / lineheight) >> 1;
		color = ((Uint32 *)wolf->txt[6].surf->pixels)
			[wolf->txt[6].surf->w * wolf->pl.wall.texel.y +
				wolf->pl.wall.texel.x];
		// if (wolf->pl.direction == NORTH || wolf->pl.direction == SOUTH)
		// 	color = (color >> 1) & 8355711;
    	wolf->buff[j * SCREEN_WIDTH + x] = color;
		j++;
	}
}

void	buffer_wall(t_wolf3d *wolf, int lineheight, int tex_num, int x)
{
	int		j;
	int		d;
	Uint32	color;

	j = wolf->strip.start;
	while (j <= wolf->strip.end)
	{
		d = (j << 1) - SCREEN_HEIGHT + lineheight;
		wolf->pl.wall.texel.y = lineheight == 0 ? 0 :
			((d * wolf->txt[tex_num].surf->w) / lineheight) >> 1;
		// color = get_color(wolf, ((Uint32 *)wolf->txt[tex_num].surf->pixels)
		// 	[wolf->txt[tex_num].surf->w * wolf->pl.wall.texel.y +
		// 		wolf->pl.wall.texel.x], wolf->pl.perp_walldist / MAX_LENGTH);
		color = ((Uint32 *)wolf->txt[tex_num].surf->pixels)
			[wolf->txt[tex_num].surf->w * wolf->pl.wall.texel.y +
				wolf->pl.wall.texel.x];
		if (wolf->pl.direction == NORTH || wolf->pl.direction == SOUTH)
			color = (color >> 1) & 8355711;
    	wolf->buff[j * SCREEN_WIDTH + x] = color;
		j++;
	}
}

int		get_wall_hit_texelx(t_wolf3d *wolf)
{
	int tex_num;

	if (wolf->pl.direction == NORTH)
		tex_num = wolf->map->cell[wolf->pl.map.y][wolf->pl.map.x].number - 1;
	else if (wolf->pl.direction == SOUTH)
		tex_num = 1;
	else if (wolf->pl.direction == EAST)
		tex_num = 2;
	else
		tex_num = 3;
	if (wolf->pl.direction == WEST || wolf->pl.direction == EAST)
		wolf->pl.wall_hit = wolf->pl.pos.y +
			wolf->pl.perp_walldist * wolf->pl.ray_dir.y;
	else
		wolf->pl.wall_hit = wolf->pl.pos.x +
			wolf->pl.perp_walldist * wolf->pl.ray_dir.x;
	wolf->pl.wall_hit -= floor((wolf->pl.wall_hit));
	wolf->pl.wall.texel.x = (int)(wolf->pl.wall_hit *
		(double)wolf->txt[tex_num].surf->w);
	if ((wolf->pl.direction == EAST || wolf->pl.direction == WEST) &&
			wolf->pl.ray_dir.x > 0)
		wolf->pl.wall.texel.x = wolf->txt[tex_num].surf->w -
			wolf->pl.wall.texel.x - 1;
	if ((wolf->pl.direction == NORTH || wolf->pl.direction == SOUTH) &&
			wolf->pl.ray_dir.y < 0)
		wolf->pl.wall.texel.x = wolf->txt[tex_num].surf->w -
			wolf->pl.wall.texel.x - 1;
	return (tex_num);
}

int		get_walls_limits(t_draw_strip *strip,
			t_player *player, int stepx, int stepy)
{
	int lines_height;

	if (player->direction == WEST || player->direction == EAST)
		player->perp_walldist = (player->map.x - player->pos.x +
			(1 - stepx) / 2) / player->ray_dir.x;
	else
		player->perp_walldist = (player->map.y - player->pos.y +
			(1 - stepy) / 2) / player->ray_dir.y;
	lines_height = (int)(SCREEN_HEIGHT / player->perp_walldist);
	strip->start = SCREEN_HEIGHT / 2 - lines_height / 2;
	if(strip->start < 0)
		strip->start = 0;
	strip->end = strip->start + lines_height - 1;
	if(strip->end >= SCREEN_HEIGHT)
		strip->end = SCREEN_HEIGHT - 1;
	return (lines_height);
}

int		hit_wall(t_wolf3d *wolf, int stepx, int stepy, int x)
{
	int lines_height;
	int	tex_num;

	if (wolf->pl.wall.curr.x < wolf->pl.wall.curr.y)
	{
		wolf->pl.wall.curr.x += wolf->pl.delta_dist.x;
		wolf->pl.map.x += stepx;
		wolf->pl.direction = wolf->pl.ray_dir.x > 0.0 ? EAST : WEST;
	}
	else
	{
		wolf->pl.wall.curr.y += wolf->pl.delta_dist.y;
		wolf->pl.map.y += stepy;
		wolf->pl.direction = wolf->pl.ray_dir.y > 0.0 ? SOUTH : NORTH;
	}
	if (wolf->map->cell[wolf->pl.map.y][wolf->pl.map.x].type == 'w')
	{
		// printf("%d %d\n", wolf->pl.map.x, wolf->pl.map.y);
		lines_height = get_walls_limits(&wolf->strip, &wolf->pl, stepx, stepy);
		tex_num = get_wall_hit_texelx(wolf);
		buffer_wall(wolf, lines_height, tex_num, x);
		floorcasting(wolf, x);
		return (1);
	}
	else if ((wolf->pl.map.x - (int)wolf->pl.pos.x) * (wolf->pl.map.x - (int)wolf->pl.pos.x) + (wolf->pl.map.y - (int)wolf->pl.pos.y) * (wolf->pl.map.y - (int)wolf->pl.pos.y) >= (MAX_LENGTH - 1) * (MAX_LENGTH - 1))
	{

	if (wolf->pl.direction == WEST || wolf->pl.direction == EAST)
		wolf->pl.perp_walldist = (wolf->pl.map.x - wolf->pl.pos.x +
			(1 - stepx) / 2) / wolf->pl.ray_dir.x;
	else
		wolf->pl.perp_walldist = (wolf->pl.map.y - wolf->pl.pos.y +
			(1 - stepy) / 2) / wolf->pl.ray_dir.y;
	lines_height = (int)(SCREEN_HEIGHT / wolf->pl.perp_walldist);
	wolf->strip.start = SCREEN_HEIGHT / 2 - lines_height / 2;
	if(wolf->strip.start < 0)
		wolf->strip.start = 0;
	wolf->strip.end = wolf->strip.start + lines_height - 1;
	if(wolf->strip.end >= SCREEN_HEIGHT)
		wolf->strip.end = SCREEN_HEIGHT - 1;
		if (wolf->pl.direction == WEST || wolf->pl.direction == EAST)
			wolf->pl.wall_hit = wolf->pl.pos.y +
				wolf->pl.perp_walldist * wolf->pl.ray_dir.y;
		else
			wolf->pl.wall_hit = wolf->pl.pos.x +
				wolf->pl.perp_walldist * wolf->pl.ray_dir.x;
		wolf->pl.wall_hit -= floor((wolf->pl.wall_hit));
		wolf->pl.wall.texel.x = (int)(wolf->pl.wall_hit *
			(double)wolf->txt[6].surf->w);
		if ((wolf->pl.direction == EAST || wolf->pl.direction == WEST) &&
				wolf->pl.ray_dir.x > 0)
			wolf->pl.wall.texel.x = wolf->txt[6].surf->w -
				wolf->pl.wall.texel.x - 1;
		if ((wolf->pl.direction == NORTH || wolf->pl.direction == SOUTH) &&
				wolf->pl.ray_dir.y < 0)
			wolf->pl.wall.texel.x = wolf->txt[6].surf->w -
				wolf->pl.wall.texel.x - 1;
		buffer_fog(wolf, lines_height, x);
		floorcasting(wolf, x);
		return (1);
	}
	return (0);
}

void	raycasting(t_wolf3d *wolf)
{
	char *tmp;
	int x;
	int stepx;
	int stepy;

	// ft_putendl("new one");
	x = -1;
	while (++x < SCREEN_WIDTH)
	// ft_printf("%d %d\n", wolf->thread.start, wolf->thread.end);
	// x = wolf->thread.start - 1;
	// while (++x < wolf->thread.end)
	{
		get_players_env(wolf, &stepx, &stepy, x);
		while (1)
			if (hit_wall(wolf, stepx, stepy, x))
				break ;
	}
	SDL_UpdateTexture(wolf->texture, NULL, wolf->buff, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(wolf->rend);
	SDL_RenderCopy(wolf->rend, wolf->texture, NULL, NULL);
	wolf->fps.old = wolf->fps.new;
	wolf->fps.new = SDL_GetTicks();
	// printf(" | %f -> %f\n", wolf->fps.old, wolf->fps.new);
	wolf->fps.fps = 1000 / (int)(wolf->fps.new - wolf->fps.old);
	put_text(wolf, "FPS:", 33, 1, 1);
	put_text(wolf, (tmp = ft_itoa(wolf->fps.fps)), 33, 33, 1);
	ft_strdel(&tmp);
}

void			divide_into_threads(t_wolf3d *wolf)
{
	SDL_Thread	*thread[THREADS];
	t_wolf3d	worker[THREADS];
	int			i;

	i = -1;
	while (++i < THREADS)
	{
		worker[i] = *wolf;
		worker[i].thread.start = (i) * SCREEN_WIDTH / THREADS;
		worker[i].thread.end = (i + 1) * SCREEN_WIDTH / THREADS;
		thread[i] = SDL_CreateThread((int(*)())raycasting, "name", (void *)&worker[i]);//name
	}
	while (--i >= 0)
		SDL_WaitThread(thread[i], NULL);
}

void	get_players_position(t_wolf3d *wolf)
{
	wolf->fps.new = SDL_GetTicks();
	wolf->pl.dir.x = 1.0;
	wolf->pl.dir.y = 0.0;
	wolf->pl.plane.x = 0;
	wolf->pl.plane.y = -0.66;
	wolf->pl.moveSpeed = 0.03;
	wolf->pl.rotSpeed = 0.018;
	wolf->pl.move[0] = 0;
	wolf->pl.move[1] = 0;
	wolf->pl.move[2] = 0;
}

void	load_textures_2(t_texture textures[TEXTURE_NUMBER],
	SDL_Surface *tmp[TEXTURE_NUMBER])
{
	SDL_FreeSurface(textures[0].surf);
	SDL_FreeSurface(textures[1].surf);
	SDL_FreeSurface(textures[2].surf);
	SDL_FreeSurface(textures[3].surf);
	SDL_FreeSurface(textures[4].surf);
	SDL_FreeSurface(textures[5].surf);
	SDL_FreeSurface(textures[6].surf);
	textures[0].surf = tmp[0];
	textures[1].surf = tmp[1];
	textures[2].surf = tmp[2];
	textures[3].surf = tmp[3];
	textures[4].surf = tmp[4];
	textures[5].surf = tmp[5];
	textures[6].surf = tmp[6];
}

void	load_textures(t_texture textures[TEXTURE_NUMBER], t_wolf3d *wolf)
{
	SDL_Surface	*tmp[TEXTURE_NUMBER];

	if ((textures[0].surf = IMG_Load("img/0.png")) == NULL ||
		(textures[1].surf = IMG_Load("img/1.png")) == NULL ||
		(textures[2].surf = IMG_Load("img/2.png")) == NULL ||
		(textures[3].surf = IMG_Load("img/3.png")) == NULL ||
		(textures[4].surf = IMG_Load("img/floor_stone.jpg")) == NULL ||
		(textures[5].surf = IMG_Load("img/ceiling.jpg")) == NULL ||
		(textures[6].surf = IMG_Load("img/fog_low.jpg")) == NULL)
		exit_func("Bad texture initialisation 1.");
	if ((tmp[0] = SDL_ConvertSurfaceFormat(textures[0].surf,
				SDL_PIXELFORMAT_RGB888, 0)) == NULL ||
			(tmp[1] = SDL_ConvertSurfaceFormat(textures[1].surf,
				SDL_PIXELFORMAT_RGB888, 0)) == NULL ||
			(tmp[2] = SDL_ConvertSurfaceFormat(textures[2].surf,
				SDL_PIXELFORMAT_RGB888, 0)) == NULL ||
			(tmp[3] = SDL_ConvertSurfaceFormat(textures[3].surf,
				SDL_PIXELFORMAT_RGB888, 0)) == NULL ||
			(tmp[4] = SDL_ConvertSurfaceFormat(textures[4].surf,
				SDL_PIXELFORMAT_RGB888, 0)) == NULL ||
			(tmp[5] = SDL_ConvertSurfaceFormat(textures[5].surf,
				SDL_PIXELFORMAT_RGB888, 0)) == NULL ||
			(tmp[6] = SDL_ConvertSurfaceFormat(textures[6].surf,
				SDL_PIXELFORMAT_RGB888, 0)) == NULL)
		exit_func("Bad texture initialisation.");
	load_textures_2(textures, tmp);
}


void	begin_game(t_wolf3d *wolf)
{
	int			i;

	load_textures(wolf->txt, wolf);
	get_players_position(wolf);
	while (1)
	{
		if (wolf->fps.old > 50 && event_handler(wolf) == 0)
			break ;
		move_rotate(&wolf->pl, wolf->map->cell);
		raycasting(wolf);
		// SDL_UpdateTexture(wolf->texture, NULL, wolf->buff, SCREEN_WIDTH * sizeof(Uint32));
		SDL_RenderPresent(wolf->rend);
		clear_buff(wolf->buff);
	}
		// divide_into_threads(wolf);
		// while (event_handler(wolf))
		// {
			// move_rotate(&wolf->pl, wolf->map->cell);
			// divide_into_threads(wolf);
			// clear_buff(wolf->buff);
			// SDL_UpdateTexture(wolf->texture, NULL, wolf->buff, SCREEN_WIDTH * sizeof(Uint32));
			// SDL_RenderPresent(wolf->rend);
		// }
		// SDL_Delay(2000);
}

void	ft_usage(void)
{
	ft_putendl("\033[31mUsage:\033[0m ./wolf3d [map]\n");
	ft_putstr("If no map is provided, wolf3d will launch");
	ft_putendl(" map \033[32mmaps/map_test.map\033[0m .\n");
	ft_putendl("[W]\t\t- move forward.\n[S]\t\t- move backward.");
	ft_putendl("[A]\t\t- turn left.\n[D]\t\t- turn right.");
	ft_putendl("[Left Shift]\t- speed up moves and rotations.");
	ft_putendl("[ESC]\t\t- close wolf3d.\n");
}

int		main(int argc, char **argv)
{
	t_wolf3d *wolf;

	wolf = create_wolf();
	init(wolf);
	if (argc == 1)
	{
		ft_usage();
		parse_map(wolf, "maps/map_test.map");
	}
	else if (argc == 2)
		parse_map(wolf, argv[1]);
	else
		exit_func("Please, enter only one map as an argument.");
	begin_game(wolf);
	close_wolf(wolf);
	system("leaks wolf3d");
	return (0);
}
