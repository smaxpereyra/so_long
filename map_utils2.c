/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:48:50 by spereyra          #+#    #+#             */
/*   Updated: 2023/11/18 17:50:03 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_objects_ok(t_game *g)
{
	int	exit_count;
	int	player_count;
	int	coll_count;
	int	i;

	exit_count = 0;
	player_count = 0;
	coll_count = 0;
	i = -1;
	while (g->map[++i])
	{
		if (g->map[i] == 'E')
			exit_count++;
		if (g->map[i] == 'P')
			player_count++;
		if (g->map[i] == 'C')
			coll_count++;
	}
	if (exit_count != 1)
		ft_printf("Error\nInvalid map: The number of exits is not one!\n");
	if (player_count != 1)
		ft_printf("Error\nInvalid map: The number of players is not one!\n");
	if (coll_count < 1)
		ft_printf("Error\nInvalid map: There must be at least one key!\n");
	return (exit_count == 1 && player_count == 1 && coll_count >= 1);
}

int	map_is_closed(t_game *g)
{
	int	h;
	int	w;
	int	closed;

	closed = 1;
	h = -1;
	while (++h < g->h)
	{
		w = -1;
		while (++w < g->w)
		{
			if (w == 0 && g->map[h * g->w + w] != '1')
				closed = 0;
			else if (h == 0 && g->map[h * g->w + w] != '1')
				closed = 0;
			else if (h == g->h - 1 && g->map[h * g->w + w] != '1')
				closed = 0;
			else if (w == g->w - 1 && g->map[h * g->w + w] != '1')
				closed = 0;
		}
	}
	if (closed == 0)
		ft_printf("Error\nInvalid map: The map is not surrounded by walls!\n");
	return (closed);
}

int	map_is_rectangle(t_game *g)
{
	if (g->w >= 2 && g->h >= 2 && (g->h * g->w) == (int)ft_strlen(g->map))
		return (1);
	else
	{
		ft_printf("Error\nInvalid map: The map is not rectangular!\n");
		return (0);
	}
}

int	map_load(t_game *g, char *filepath)
{
	int		fd;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nFile cannot be loaded!\n");
		return (0);
	}
	else
	{
		map_create(g, fd);
		close(fd);
		return (1);
	}
}

void	map_create(t_game *g, int fd)
{
	char	*line;
	char	*tmp;

	g->map = 0;
	g->map = malloc(1 * sizeof(char));
	if (g->map == 0)
		return ;
	g->map[0] = '\0';
	line = 0;
	line = get_next_line(fd);
	tmp = 0;
	while (line != 0)
	{
		g->h++;
		g->w = ft_strlen(line) - 1;
		line[g->w] = '\0';
		tmp = g->map;
		g->map = ft_strjoin(tmp, line);
		free(tmp);
		tmp = 0;
		free(line);
		line = 0;
		line = get_next_line(fd);
	}
	free(line);
}
