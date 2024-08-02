/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 22:39:52 by arakotom          #+#    #+#             */
/*   Updated: 2024/08/02 13:54:17 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1,
}					t_bool;

typedef enum e_direction
{
	UP = 0,
	DOWN = 1,
	LEFT = 2,
	RIGHT = 3,
}					t_direction;

typedef struct s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct s_map_data
{
	int				x;
	int				y;
	int				empty;
	int				wall;
	int				item;
	int				exit;
	int				player;
}					t_map_data;

typedef struct s_player_img
{
	void			*up;
	void			*down;
	void			*left;
	void			*right;
	void			*up_e;
	void			*down_e;
	void			*left_e;
	void			*right_e;
}					t_player_img;

typedef struct s_exit_img
{
	void			*close;
	void			*open;
}					t_exit_img;
typedef struct s_wall_img
{
	void			*wall_i;
	void			*wall_e;
}					t_wall_img;

typedef struct s_map
{
	char			**map;
	t_map_data		map_data;
	t_coord			player;
	t_coord			exit;
}					t_map;

typedef struct s_assets
{
	void			*ground;
	void			*collect;
	t_wall_img		wall;
	t_exit_img		exit;
	t_player_img	player;
}					t_assets;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	int				win_w;
	int				win_h;
	int				ratio;
	t_map			map;
	t_assets		assets;
	t_direction		player_direction;
}					t_game;

#endif
