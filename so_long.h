/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 09:41:35 by imeftah-          #+#    #+#             */
/*   Updated: 2025/01/08 22:09:17 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "./ft_printf/ft_printf.h"
// # include "libft.h"
// # include "libft/libft.h"

# define BOX_SIZE 42
# define PLAYER_SIZE 42
# define FRAME_WAIT 40000

typedef struct s_window_data
{
	void		*mlx;
	void		*win;
	void		*stone;
	void		*door;
	void		*back;
	void		*coin;
	void		*img;
	int			s;
	int			width;
	int			height;
	int			map_check_height;
	int			coin_count;
	int			movement_counter;
	int			position_width;
	int			position_height;
	int			fd_map;
	char		**map;
	char		*holder_map;
	char		*new_holder;
	char		derection;
	int			count;
	char		c;
}	t_window_data;

t_window_data	*map_holder(char *map_file);
t_window_data	*window_size(t_window_data *data);
t_window_data	*window_maker(t_window_data *data);
t_window_data	*load_images(t_window_data *data);
t_window_data	*display_boxes(t_window_data *data);
t_window_data	*background(t_window_data *data);
t_window_data	*player_position(t_window_data *data);
int				exit_window(t_window_data *data);
int				keys_move(int key_press, t_window_data *param);
int				if_bce(t_window_data *data, int width, int height);
int				map_checker(t_window_data *data);
int				flood_fill_checker(t_window_data *data, int width, int height);
char			**ft_split(char *s1, char c);
char			*ft_strdup(char *string);
char			*ft_strjoin(char *s1, char *s2);
void			player_run(t_window_data *data);
void			clean_up(t_window_data *data);
int				game_loop(t_window_data *data);
int				ft_strlen(char *str);

#endif
