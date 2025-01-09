/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_allocation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:56:22 by imeftah-          #+#    #+#             */
/*   Updated: 2025/01/08 12:33:28 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static t_window_data	*allocation_one(t_window_data *data)
{
	data->run_frames = malloc(FRAME_PLAYER_RIGHT * sizeof(void *));
	if (data->run_frames == NULL)
		return (NULL);
	data->run_frames_left = malloc(FRAME_PLAYER_LEFT * sizeof(void *));
	if (data->run_frames_left == NULL)
		return (NULL);
	data->idle = malloc(FRAME_PLAYER_IDLE * sizeof(void *));
	if (data->idle == NULL)
		return (NULL);
	data->coins = malloc(FRAME_COINS * sizeof(void *));
	if (data->coins == NULL)
		return (NULL);
	data->animation_back = malloc(FRAME_PLAYER_UP * sizeof(void *));
	if (data->animation_back == NULL)
		return (NULL);
	data->enemy = malloc(FRAME_ENEMY * sizeof(void *));
	if (data->enemy == NULL)
		return (NULL);
	return (data);
}

t_window_data	*allocation(t_window_data *data)
{
	data->box_x = malloc(data->box_count * sizeof(int));
	if (data->box_x == NULL)
		return (NULL);
	data->box_y = malloc(data->box_count * sizeof(int));
	if (data->box_y == NULL)
		return (NULL);
	data->coin_x = malloc(data->coin_count * sizeof(int));
	if (data->coin_x == NULL)
		return (NULL);
	data->coin_y = malloc(data->coin_count * sizeof(int));
	if (data->coin_y == NULL)
		return (NULL);
	data->enemy_x = malloc(data->enemy_count * sizeof(int));
	if (data->enemy_x == NULL)
		return (NULL);
	data->enemy_y = malloc(data->enemy_count * sizeof(int));
	if (data->enemy_y == NULL)
		return (NULL);
	data = allocation_one(data);
	if (data == NULL)
		return (NULL);
	return (data);
}
