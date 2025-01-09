/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_animation_player.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:19:46 by imeftah-          #+#    #+#             */
/*   Updated: 2025/01/09 10:30:11 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_player(t_window_data *data, int width, int height)
{
	if (data->derection[XK_w] == 1)
		mlx_put_image_to_window(data->mlx, data->win,
			data->animation_back[data->run_up_count], width, height);
	else if (data->derection[XK_a] == 1)
		mlx_put_image_to_window(data->mlx, data->win,
			data->run_frames_left[data->run_left_count], width, height);
	else if (data->derection[XK_d] == 1 || data->derection[XK_s] == 1)
		mlx_put_image_to_window(data->mlx, data->win,
			data->run_frames[data->run_right_count], width, height);
	display_string_win(data);
	data->run_right_count = (data->run_right_count + 1) % 6;
	data->run_left_count = (data->run_left_count + 1) % 6;
	data->run_up_count = (data->run_up_count + 1) % 2;
}

t_window_data	*check_collision_display(t_window_data *data, int width,
		int height)
{
	if (check_collision_coin(data, width, height) == 1)
		ft_printf("coin collected : %d/%d\n", ++data->count_eat_coin,
			data->coin_count);
	if (check_collision_coin(data, width, height) == 2)
	{
		clean_up(data);
		exit(0);
		return (NULL);
	}
	if (check_collision_wall(data, width, height) == 1)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->idle[0],
			data->position_width, data->position_height);
		return (NULL);
	}
	if (check_collision_enemy(data, width, height) == 1)
	{
		clean_up(data);
		exit(0);
		return (NULL);
	}
	draw_player(data, width, height);
	data->position_width = width;
	data->position_height = height;
	return (data);
}

void	player_run_bonus(t_window_data *data)
{
	int	movement;
	int	width;
	int	height;

	movement = PLAYER_SIZE / 6;
	width = data->position_width;
	height = data->position_height;
	mlx_put_image_to_window(data->mlx, data->win, data->back, width, height);
	if (data->derection[XK_w] == 1)
		height -= movement;
	if (data->derection[XK_s] == 1)
		height += movement;
	if (data->derection[XK_a] == 1)
		width -= movement;
	if (data->derection[XK_d] == 1)
		width += movement;
	data = check_collision_display(data, width, height);
	if (data == NULL)
		return ;
}
