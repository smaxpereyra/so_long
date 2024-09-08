/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:01:40 by spereyra          #+#    #+#             */
/*   Updated: 2023/11/18 17:35:55 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_w(t_game *g)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(g->map) && g->map[i] != 'P')
		i++;
	if (g->map[i - g->w] == 'C')
		g->coll_cnt++;
	if (g->map[i - g->w] == 'E' && g->all_coll == g->coll_cnt)
		exit_game(g);
	else if (g->map[i - g->w] != '1' && g->map[i - g->w] != 'E')
	{
		g->map[i] = '0';
		g->map[i - g->w] = 'P';
		g->walk_cnt++;
		ft_printf("%d\n", g->walk_cnt);
		set_img(g, 'w');
		if (g->all_coll == g->coll_cnt)
			set_open_exit(g);
	}
}

void	move_a(t_game *g)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(g->map) && g->map[i] != 'P')
		i++;
	if (g->map[i - 1] == 'C')
		g->coll_cnt++;
	if (g->map[i - 1] == 'E' && g->all_coll == g->coll_cnt)
		exit_game(g);
	else if (g->map[i - 1] != '1' && g->map[i - 1] != 'E')
	{
		g->map[i] = '0';
		g->map[i - 1] = 'P';
		g->walk_cnt++;
		ft_printf("%d\n", g->walk_cnt);
		set_img(g, 'a');
		if (g->all_coll == g->coll_cnt)
			set_open_exit(g);
	}
}

void	move_s(t_game *g)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(g->map) && g->map[i] != 'P')
		i++;
	if (g->map[i + g->w] == 'C')
		g->coll_cnt++;
	if (g->map[i + g->w] == 'E' && g->all_coll == g->coll_cnt)
		exit_game(g);
	else if (g->map[i + g->w] != '1' && g->map[i + g->w] != 'E')
	{
		g->map[i] = '0';
		g->map[i + g->w] = 'P';
		g->walk_cnt++;
		ft_printf("%d\n", g->walk_cnt);
		set_img(g, 's');
		if (g->all_coll == g->coll_cnt)
			set_open_exit(g);
	}
}

void	move_d(t_game *g)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(g->map) && g->map[i] != 'P')
		i++;
	if (g->map[i + 1] == 'C')
		g->coll_cnt++;
	if (g->map[i + 1] == 'E' && g->all_coll == g->coll_cnt)
		exit_game(g);
	else if (g->map[i + 1] != '1' && g->map[i + 1] != 'E')
	{
		g->map[i] = '0';
		g->map[i + 1] = 'P';
		g->walk_cnt++;
		ft_printf("%d\n", g->walk_cnt);
		set_img(g, 'd');
		if (g->all_coll == g->coll_cnt)
			set_open_exit(g);
	}
}
