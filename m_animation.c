/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_animation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:47:18 by imeftah-          #+#    #+#             */
/*   Updated: 2025/01/09 10:49:21 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_movement(t_window_data *data)
{
	if (data->derection == 'r' && if_bce(data, data->position_width,
			data->position_height) == 1)
	{
		data->position_width += PLAYER_SIZE;
		ft_printf("movements : %d\n", ++data->movement_counter);
	}
	else if (data->derection == 'l' && if_bce(data, data->position_width,
			data->position_height) == 1)
	{
		data->position_width -= PLAYER_SIZE;
		ft_printf("movements : %d\n", ++data->movement_counter);
	}
	else if (data->derection == 'w' && if_bce(data, data->position_width,
			data->position_height) == 1)
	{
		data->position_height -= PLAYER_SIZE;
		ft_printf("movements : %d\n", ++data->movement_counter);
	}
	else if (data->derection == 's' && if_bce(data, data->position_width,
			data->position_height) == 1)
	{
		data->position_height += PLAYER_SIZE;
		ft_printf("movements : %d\n", ++data->movement_counter);
	}
}

void	player_run(t_window_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->back,
		data->position_width, data->position_height);
	update_movement(data);
	if (if_bce(data, data->position_width, data->position_height) == 2)
	{
		clean_up(data);
		exit(0);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img,
		data->position_width, data->position_height);
}
