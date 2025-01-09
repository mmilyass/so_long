/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_clean_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:34:50 by imeftah-          #+#    #+#             */
/*   Updated: 2025/01/08 15:22:06 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	clean_up_zero(t_window_data *data)
{
	if (data->back)
		mlx_destroy_image(data->mlx, data->back);
	if (data->door)
		mlx_destroy_image(data->mlx, data->door);
	if (data->coin)
		mlx_destroy_image(data->mlx, data->coin);
	if (data->stone)
		mlx_destroy_image(data->mlx, data->stone);
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
}

static void	clean_up_one(t_window_data *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (data->map[i])
			free(data->map[i++]);
		free(data->map);
	}
	if (data->run_frames)
	{
		i = 0;
		while (i < FRAME_PLAYER_RIGHT)
			mlx_destroy_image(data->mlx, data->run_frames[i++]);
		free(data->run_frames);
	}
}

static void	clean_up_two(t_window_data *data)
{
	int	i;

	i = 0;
	if (data->run_frames_left)
	{
		while (i < FRAME_PLAYER_LEFT)
			mlx_destroy_image(data->mlx, data->run_frames_left[i++]);
		free(data->run_frames_left);
	}
	i = 0;
	if (data->idle)
	{
		while (i < FRAME_PLAYER_IDLE)
			mlx_destroy_image(data->mlx, data->idle[i++]);
		free(data->idle);
	}
	i = 0;
	if (data->animation_back)
	{
		while (i < FRAME_PLAYER_UP)
			mlx_destroy_image(data->mlx, data->animation_back[i++]);
		free(data->animation_back);
	}
}

static void	clean_up_three(t_window_data *data)
{
	int	i;

	i = 0;
	if (data->coins)
	{
		while (i < FRAME_COINS)
			mlx_destroy_image(data->mlx, data->coins[i++]);
		free(data->coins);
	}
	i = 0;
	if (data->enemy)
	{
		while (i < FRAME_ENEMY)
			mlx_destroy_image(data->mlx, data->enemy[i++]);
		free(data->enemy);
	}
	if (data->coin_x)
		free(data->coin_x);
	if (data->coin_y)
		free(data->coin_y);
	if (data->enemy_x)
		free(data->enemy_x);
	if (data->enemy_y)
		free(data->enemy_y);
}

void	clean_up(t_window_data *data)
{
	clean_up_zero(data);
	clean_up_one(data);
	clean_up_two(data);
	clean_up_three(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->box_x)
		free(data->box_x);
	if (data->box_y)
		free(data->box_y);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free(data);
}
