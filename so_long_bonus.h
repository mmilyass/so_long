/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:03:09 by imeftah-          #+#    #+#             */
/*   Updated: 2025/01/09 10:18:01 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "./ft_printf/ft_printf.h"
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BOX_SIZE 42
# define PLAYER_SIZE 42
# define MV 42
# define FRAME_WAIT 70000
# define FRAME_PLAYER_RIGHT 6
# define FRAME_PLAYER_LEFT 6
# define FRAME_PLAYER_UP 2
# define FRAME_PLAYER_DOWN 6
# define FRAME_PLAYER_IDLE 3
# define FRAME_COINS 4
# define FRAME_ENEMY 4

typedef struct s_window_data
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*stone;
	void		*door;
	void		*back;
	void		*coin;
	void		**coins;
	void		**run_frames;
	void		**run_frames_left;
	void		**animation_back;
	void		**enemy;
	void		**idle;
	char		**map;
	int			*box_x;
	int			*box_y;
	int			*coin_x;
	int			*coin_y;
	int			*enemy_x;
	int			*enemy_y;
	int			position_width;
	int			position_height;
	int			exit_x;
	int			exit_y;
	int			width;
	int			height;
	int			box_count;
	int			enemy_count;
	int			derection[256];
	int			s;
	int			count;
	int			coin_count;
	int			count_for_coin_count;
	int			count_movements;
	int			run_right_count;
	int			run_left_count;
	int			run_up_count;
	int			frame_coins_count;
	int			frame_enemy_count;
	int			time_for_frame;
	int			count_eat_coin;
	int			frame_idle;
	int			time_wait_idle;
	int			xy_box;
	int			xy_coin;
	int			xy_enemy;
	int			map_check_height;
	char		c;

}				t_window_data;

t_window_data	*map_holder_bonus(t_window_data *data, char *map_file);
t_window_data	*window_size_bonus(t_window_data *data);
t_window_data	*window_maker_bonus(t_window_data *data);
t_window_data	*allocation(t_window_data *data);
t_window_data	*load_images_bonus(t_window_data *data);
t_window_data	*background_bonus(t_window_data *data);
t_window_data	*display_boxes_bonus(t_window_data *data);
t_window_data	*player_position_bonus(t_window_data *data);
t_window_data	*load_image_bonus_helper(t_window_data *data);
void			idle_player(t_window_data *data);
void			player_run_bonus(t_window_data *data);
void			clean_up(t_window_data *data);
void			display_string_win(t_window_data *data);
t_window_data	*inistialize_one(void);
int				game_loop_bonus(t_window_data *data);
int				key_down(int key_press, t_window_data *data);
int				key_up(int key_press, t_window_data *data);
int				coins_anim(t_window_data *data);
int				exit_window_bonus(t_window_data *data);
int				ft_strlen(char *str);
int				check_collision_coin(t_window_data *data, int width,
					int height);
int				check_collision_wall(t_window_data *data, int width,
					int height);
int				check_collision_enemy(t_window_data *data, int width,
					int height);
int				flood_fill_checker(t_window_data *data, int width, int height);
char			**ft_split(char *s1, char c);
char			*ft_strdup(char *string);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_itoa(int n);
int				map_checker_bonus(t_window_data *data);

#endif