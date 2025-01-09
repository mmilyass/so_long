/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:40:09 by imeftah-          #+#    #+#             */
/*   Updated: 2025/01/08 21:32:00 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_window_data	*player_position(t_window_data *data)
{
	int	width;
	int	height;
	int	j;
	int	i;

	i = 0;
	height = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		width = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'P')
			{
				data->position_width = width;
				data->position_height = height;
			}
			width = width + BOX_SIZE;
			j++;
		}
		height = height + BOX_SIZE;
		i++;
	}
	return (data);
}

void	idle_player(t_window_data *data)
{
	if (data->time_wait_idle < FRAME_WAIT)
	{
		data->time_wait_idle++;
		return ;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->idle[data->frame_idle],
		data->position_width, data->position_height);
	data->frame_idle++;
	data->time_wait_idle = 0;
	if (data->frame_idle == 2)
		data->frame_idle = 0;
}

static void	draw_animation(t_window_data *data, int frame_coins,
		int frame_enemy)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win,
					data->coins[frame_coins], j * PLAYER_SIZE, i * PLAYER_SIZE);
			if (data->map[i][j] == 'M')
				mlx_put_image_to_window(data->mlx, data->win,
					data->enemy[frame_enemy], j * PLAYER_SIZE, i * PLAYER_SIZE);
			j++;
		}
		i++;
	}
}

int	coins_anim(t_window_data *data)
{
	if (data->time_for_frame < 50000)
	{
		data->time_for_frame++;
		return (0);
	}
	draw_animation(data, data->frame_coins_count, data->frame_enemy_count);
	data->frame_coins_count++;
	data->frame_enemy_count++;
	data->time_for_frame = 0;
	if (data->frame_coins_count == 2)
		data->frame_coins_count = 0;
	if (data->frame_enemy_count == 3)
		data->frame_enemy_count = 0;
	return (0);
}

int	game_loop_bonus(t_window_data *data)
{
	coins_anim(data);
	if ((data->derection[XK_d] || data->derection[XK_a] || data->derection[XK_w]
			|| data->derection[XK_s]) && data->s <= 0)
	{
		display_string_win(data);
		player_run_bonus(data);
		data->s = 1;
	}
	else
		idle_player(data);
	return (0);
}
