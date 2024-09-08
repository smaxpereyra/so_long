/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:31:25 by spereyra          #+#    #+#             */
/*   Updated: 2023/11/18 19:09:11 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_game(t_game *g)
{
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, g->w * 32, g->h * 32, "so_long");
	g->img.wall = mlx_xpm_file_to_image(g->mlx, \
			"./textures/wall.xpm", &(g->img.w), &(g->img.h));
	g->img.floor = mlx_xpm_file_to_image(g->mlx, \
			"./textures/floor.xpm", &(g->img.w), &(g->img.h));
	g->img.coll = mlx_xpm_file_to_image(g->mlx, \
			"./textures/coll.xpm", &(g->img.w), &(g->img.h));
	g->img.exit = mlx_xpm_file_to_image(g->mlx, \
			"./textures/exit.xpm", &(g->img.w), &(g->img.h));
	g->img.open = mlx_xpm_file_to_image(g->mlx, \
			"./textures/open.xpm", &(g->img.w), &(g->img.h));
	g->img.player.player_up = mlx_xpm_file_to_image(g->mlx, \
			"./textures/player_up.xpm", &(g->img.w), &(g->img.h));
	g->img.player.player_right = mlx_xpm_file_to_image(g->mlx, \
			"./textures/player_right.xpm", &(g->img.w), &(g->img.h));
	g->img.player.player_down = mlx_xpm_file_to_image(g->mlx, \
			"./textures/player_down.xpm", &(g->img.w), &(g->img.h));
	g->img.player.player_left = mlx_xpm_file_to_image(g->mlx, \
			"./textures/player_left.xpm", &(g->img.w), &(g->img.h));
	g->coll_cnt = 0;
	g->all_coll = coll_count(g->map);
	g->walk_cnt = 0;
}

void	set_img(t_game *g, char direction)
{
	int	h;
	int	w;

	h = -1;
	while (++h < g->h)
	{
		w = -1;
		while (++w < g->w)
		{
			if (g->map[h * g->w + w] == '1')
				mlx_put_image_to_window(g->mlx, \
						g->win, g->img.wall, w * 32, h * 32);
			else if (g->map[h * g->w + w] == 'C')
				mlx_put_image_to_window(g->mlx, \
						g->win, g->img.coll, w * 32, h * 32);
			else if (g->map[h * g->w + w] == 'P')
				set_player(g, w, h, direction);
			else if (g->map[h * g->w + w] == 'E')
				mlx_put_image_to_window(g->mlx, \
						g->win, g->img.exit, w * 32, h * 32);
			else
				mlx_put_image_to_window(g->mlx, \
						g->win, g->img.floor, w * 32, h * 32);
		}
	}
}

void	set_player(t_game *game, int w, int h, char direction)
{
	if (direction == 'w')
		mlx_put_image_to_window(game->mlx, game->win, \
				game->img.player.player_up, w * 32, h * 32);
	if (direction == 'a')
		mlx_put_image_to_window(game->mlx, game->win, \
				game->img.player.player_left, w * 32, h * 32);
	if (direction == 's')
		mlx_put_image_to_window(game->mlx, game->win, \
				game->img.player.player_down, w * 32, h * 32);
	if (direction == 'd')
		mlx_put_image_to_window(game->mlx, game->win, \
				game->img.player.player_right, w * 32, h * 32);
}

void	set_open_exit(t_game *game)
{
	int	h;
	int	w;

	h = 0;
	while (h < game->h)
	{
		w = 0;
		while (w < game->w)
		{
			if (game->map[h * game->w + w] == 'E')
				mlx_put_image_to_window(game->mlx, \
						game->win, game->img.open, w * 32, h * 32);
			w++;
		}
		h++;
	}
}
