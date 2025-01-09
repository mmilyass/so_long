/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_animation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:47:18 by imeftah-          #+#    #+#             */
/*   Updated: 2025/01/08 17:13:29 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_run(t_window_data *data)
{
	int	movement;

	movement = PLAYER_SIZE;
	mlx_put_image_to_window(data->mlx, data->win, data->back,
		data->position_width, data->position_height);
	if (data->derection == 'r'
		&& if_bce(data, data->position_width, data->position_height) == 1)
		data->position_width += movement;
	else if (data->derection == 'l'
		&& if_bce(data, data->position_width, data->position_height) == 1)
		data->position_width -= movement;
	else if (data->derection == 'w'
		&& if_bce(data, data->position_width, data->position_height) == 1)
		data->position_height -= movement;
	else if (data->derection == 's'
		&& if_bce(data, data->position_width, data->position_height) == 1)
		data->position_height += movement;
	else if (if_bce(data, data->position_width, data->position_height) == 2)
	{
		clean_up(data);
		exit(0);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img,
		data->position_width, data->position_height);
}
