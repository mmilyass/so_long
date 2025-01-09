/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:23:10 by imeftah-          #+#    #+#             */
/*   Updated: 2025/01/08 17:11:39 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_window_data	*player_position(t_window_data *data)
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
				data->position_width = j * BOX_SIZE;
				data->position_height = i * BOX_SIZE;
			}
			j++;
		}
		i++;
	}
	data->map_check_height = i;
	return (data);
}

int	if_bce(t_window_data *data, int width, int height)
{
	if (data->derection == 'w')
		height -= PLAYER_SIZE;
	else if (data->derection == 's')
		height += PLAYER_SIZE;
	else if (data->derection == 'l')
		width -= PLAYER_SIZE;
	else if (data->derection == 'r')
		width += PLAYER_SIZE;
	if (data->map[height / PLAYER_SIZE][width / PLAYER_SIZE] == '1'
		|| data->map[height / PLAYER_SIZE][width / PLAYER_SIZE] == 'E')
	{
		if (data->map[height / PLAYER_SIZE][width / PLAYER_SIZE] == 'E'
			&& data->count == data->coin_count)
			return (2);
		return (0);
	}
	else if (data->map[height / PLAYER_SIZE][width / PLAYER_SIZE] == 'C')
	{
		data->map[height / PLAYER_SIZE][width / PLAYER_SIZE] = '0';
		return (data->count++, 1);
	}
	else if (data->map[height / PLAYER_SIZE][width / PLAYER_SIZE] == 'E'
			&& data->count == data->coin_count)
		return (2);
	return (1);
}
