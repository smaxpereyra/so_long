/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:08:07 by spereyra          #+#    #+#             */
/*   Updated: 2024/08/22 18:15:12 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx.h"
//# include <X11/keysym.h>/////////
# include "get_next_line.h"
# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <fcntl.h>

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17
# define KEY_ESC				65307//53
# define KEY_W					119//13
# define KEY_A					97//0
# define KEY_S					115//1
# define KEY_D					100//2
# define KEY_UP					126
# define KEY_DOWN				125
# define KEY_LEFT				123
# define KEY_RIGHT				124

typedef struct s_player
{
	void	*player_up;
	void	*player_right;
	void	*player_down;
	void	*player_left;
}				t_player;

typedef struct s_img
{
	void		*wall;
	void		*floor;
	void		*coll;
	void		*exit;
	void		*open;
	t_player	player;
	int			w;
	int			h;
}				t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		w;
	int		h;
	int		coll_cnt;
	int		all_coll;
	int		walk_cnt;
	char	*map;
}				t_game;

int		file_is_ber(char *arg);
int		coll_count(char *str);
int		map_check(t_game *g);
int		map_reach_exit(t_game *g);
void	map_flood_fill(char *map, int width, int index, int *to_find);
int		map_objects_ok(t_game *g);
int		map_is_closed(t_game *g);
int		map_is_rectangle(t_game *g);
int		map_load(t_game *g, char *filepath);
void	map_create(t_game *g, int fd);
int		press_key(int keycode, t_game *game);
void	move_w(t_game *g);
void	move_a(t_game *g);
void	move_s(t_game *g);
void	move_d(t_game *g);
void	set_game(t_game *g);
int		exit_game(t_game *g);
void	set_open_exit(t_game *game);
void	set_img(t_game *game, char direction);
void	set_player(t_game *game, int w, int h, char direction);

#endif
