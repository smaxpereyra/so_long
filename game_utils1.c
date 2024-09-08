/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:01:28 by spereyra          #+#    #+#             */
/*   Updated: 2024/08/22 17:43:01 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	press_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_w(game);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_a(game);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_s(game);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_d(game);
	return (0);
}

int	exit_game(t_game *g)
{
	ft_printf("GAME OVER!\n");
	mlx_destroy_window(g->mlx, g->win);
	exit(0);
}
