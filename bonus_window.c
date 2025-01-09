/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:11:34 by imeftah-          #+#    #+#             */
/*   Updated: 2025/01/09 11:15:11 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_window_data	*window_size_bonus(t_window_data *data)
{
	int	width_len;
	int	height_len;

	width_len = 0;
	height_len = 0;
	while (data->map[0][width_len])
		width_len++;
	while (data->map[height_len])
		height_len++;
	data->width = width_len * BOX_SIZE;
	data->height = height_len * BOX_SIZE;
	if (data->width > 1920 || data->height > 1080)
	{
		ft_printf("Error\nthe map is too large !!\n");
		clean_up(data);
		exit(0);
	}
	return (data);
}

t_window_data	*window_maker_bonus(t_window_data *data)
{
	int	i;

	i = 0;
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (NULL);
	data->win = mlx_new_window(data->mlx, data->width, data->height, "ilyass");
	if (data->win == NULL)
		return (NULL);
	while (i < 256)
	{
		data->derection[i] = 0;
		i++;
	}
	return (data);
}
