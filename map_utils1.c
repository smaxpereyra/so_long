/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:42:43 by spereyra          #+#    #+#             */
/*   Updated: 2023/11/18 17:37:49 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	coll_count(char *str)
{
	int	i;
	int	colls;

	i = 0;
	colls = 0;
	while (str[i])
	{
		if (str[i] == 'C')
			colls++;
		i++;
	}
	return (colls);
}

int	map_check(t_game *g)
{
	int	is_rectangle;
	int	objects_ok;
	int	is_closed;
	int	reach_exit;

	is_rectangle = 0;
	objects_ok = 0;
	is_closed = 0;
	reach_exit = 0;
	is_rectangle = map_is_rectangle(g);
	if (is_rectangle)
		objects_ok = map_objects_ok(g);
	if (is_rectangle && objects_ok)
		is_closed = map_is_closed(g);
	if (is_rectangle && is_closed && objects_ok)
		reach_exit = map_reach_exit(g);
	if (is_rectangle && is_closed && objects_ok && reach_exit)
		return (1);
	else
	{
		free(g->map);
		return (0);
	}
}

int	map_reach_exit(t_game *g)
{
	char	*map;
	int		to_find;
	size_t	i;

	map = 0;
	map = ft_strdup(g->map);
	to_find = coll_count(g->map) + 1;
	i = 0;
	while (i++ < ft_strlen(g->map))
	{
		if (g->map[i] == 'P')
			break ;
	}
	map_flood_fill(map, g->w, i, &to_find);
	free(map);
	if (to_find > 0)
		ft_printf("Error\nInvalid map: Cannot reach the exit or any key!\n");
	return (to_find == 0);
}

void	map_flood_fill(char *map, int width, int index, int *to_find)
{
	if (map[index] == '1' || map[index] == '*' || *to_find == 0)
		return ;
	if (map[index] == 'E' || map[index] == 'C')
		*to_find = *to_find - 1;
	map[index] = '*';
	if (*to_find > 0)
	{
		map_flood_fill(map, width, index - width, to_find);
		map_flood_fill(map, width, index + 1, to_find);
		map_flood_fill(map, width, index + width, to_find);
		map_flood_fill(map, width, index - 1, to_find);
	}
}
