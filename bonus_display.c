/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:35:34 by imeftah-          #+#    #+#             */
/*   Updated: 2025/01/08 12:35:35 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_window_data	*background_bonus(t_window_data *data)
{
	int	width;
	int	height;
	int	i;
	int	j;

	height = 0;
	i = 0;
	while (data->map[i] != NULL)
	{
		if (data->map[i] == NULL)
			break ;
		j = 0;
		width = 0;
		while (data->map[i][j] != '\0')
		{
			mlx_put_image_to_window(data->mlx, data->win, data->back, width,
				height);
			width = width + BOX_SIZE;
			j++;
		}
		height = height + BOX_SIZE;
		i++;
	}
	return (data);
}

static void	get_position(t_window_data *data, int width, int height, char c)
{
	if (c == '1')
	{
		data->box_x[data->xy_box] = width;
		data->box_y[data->xy_box] = height;
		data->xy_box++;
	}
	else if (c == 'C')
	{
		data->coin_x[data->xy_coin] = width;
		data->coin_y[data->xy_coin] = height;
		data->xy_coin++;
	}
	else if (c == 'M')
	{
		data->enemy_x[data->xy_enemy] = width;
		data->enemy_y[data->xy_enemy] = height;
		data->xy_enemy++;
	}
	else if (c == 'E')
	{
		data->exit_x = width;
		data->exit_y = height;
	}
}

void	display(t_window_data *data, char map_char, int width, int height)
{
	if (map_char == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->stone, width,
			height);
	else if (map_char == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->coins[1], width,
			height);
	else if (map_char == 'M')
		mlx_put_image_to_window(data->mlx, data->win, data->enemy[0], width,
			height);
	else if (map_char == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->door, width,
			height);
}

t_window_data	*display_boxes_bonus(t_window_data *data)
{
	int	width;
	int	height;
	int	i;
	int	j;

	i = 0;
	height = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		width = 0;
		while (data->map[i][j] != '\0')
		{
			display(data, data->map[i][j], width, height);
			get_position(data, width, height, data->map[i][j++]);
			width = width + BOX_SIZE;
		}
		height = height + BOX_SIZE;
		i++;
	}
	return (data);
}
