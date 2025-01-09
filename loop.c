/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:46:06 by imeftah-          #+#    #+#             */
/*   Updated: 2025/01/08 17:13:49 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_loop(t_window_data *data)
{
	if ((data->derection == 'r' || data->derection == 'l'
			|| data->derection == 'w' || data->derection == 's')
		&& data->s <= 0)
	{
		player_run(data);
		ft_printf("movements : %d\n", ++data->movement_counter);
		data->s++;
	}
	return (0);
}
