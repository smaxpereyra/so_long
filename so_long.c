/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:09:18 by spereyra          #+#    #+#             */
/*   Updated: 2024/08/22 19:25:00 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_is_ber(char *arg)
{
	int	len;

	len = ft_strlen(arg);
	return (ft_strncmp((const char *)&arg[len - 4], ".ber", 4));
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Error\nInvalid number of arguments: %d\n", argc - 1);
		ft_printf("Example: ./so_long <map.ber>\n");
		return (1);
	}
	else if (file_is_ber(argv[1]) != 0)
	{
		ft_printf("Error\nInvalid map type: File extension is not .ber\n");
		return (2);
	}
	if (!map_load(&game, argv[1]))
		return (3);
	if (!map_check(&game))
		return (4);
	set_game(&game);
	set_img(&game, 'w');
	mlx_hook(game.win, X_EVENT_KEY_RELEASE, 1L << 1, &press_key, &game);//0->1L<<1
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &exit_game, &game);
	mlx_loop(game.mlx);
}
