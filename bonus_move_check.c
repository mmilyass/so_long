/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_move_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:44:56 by imeftah-          #+#    #+#             */
/*   Updated: 2025/01/08 17:23:44 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_window_data	*player_position_bonus(t_window_data *data)
{
	int	j;
	int	i;

	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'P')
			{
				data->position_width = j * PLAYER_SIZE;
				data->position_height = i * PLAYER_SIZE;
			}
			j++;
		}
		i++;
	}
	data->map_check_height = i;
	return (data);
}

int	check_collision_wall(t_window_data *data, int width, int height)
{
	int	step;

	step = 0;
	while (step < data->box_count)
	{
		if ((width < data->box_x[step] + PLAYER_SIZE && width
				+ PLAYER_SIZE > data->box_x[step] && height < data->box_y[step]
				+ PLAYER_SIZE && height + PLAYER_SIZE > data->box_y[step])
			|| (width < data->exit_x + PLAYER_SIZE && width
				+ PLAYER_SIZE > data->exit_x && height < data->exit_y
				+ PLAYER_SIZE && height + PLAYER_SIZE > data->exit_y))
		{
			return (1);
		}
		step++;
	}
	return (0);
}

int	check_collision_coin(t_window_data *data, int width, int height)
{
	int	step;

	step = 0;
	while (step < data->coin_count)
	{
		if (width < data->coin_x[step] + MV && width + MV > data->coin_x[step]
			&& height < data->coin_y[step] + MV && height
			+ MV > data->coin_y[step])
		{
			data->map[data->coin_y[step] / MV][data->coin_x[step] / MV] = '0';
			mlx_put_image_to_window(data->mlx, data->win, data->back,
				data->coin_x[step], data->coin_y[step]);
			data->count_for_coin_count++;
			data->coin_x[step] = 0;
			data->coin_y[step] = 0;
			return (1);
		}
		if (width < data->exit_x + MV && width + MV > data->exit_x
			&& height < data->exit_y + MV && height + MV > data->exit_y
			&& data->count_for_coin_count == data->coin_count)
			return (2);
		step++;
	}
	return (0);
}

int	check_collision_enemy(t_window_data *data, int width, int height)
{
	int	step;

	step = 0;
	while (step < data->enemy_count)
	{
		if (width < data->enemy_x[step] + PLAYER_SIZE && width
			+ PLAYER_SIZE > data->enemy_x[step] && height < data->enemy_y[step]
			+ PLAYER_SIZE && height + PLAYER_SIZE > data->enemy_y[step])
			return (1);
		step++;
	}
	return (0);
}
