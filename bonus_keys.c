/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:39:09 by imeftah-          #+#    #+#             */
/*   Updated: 2025/01/09 10:46:33 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	exit_window_bonus(t_window_data *data)
{
	clean_up(data);
	exit(0);
	return (0);
}

int	key_down(int key_press, t_window_data *data)
{
	if (key_press == XK_Escape)
	{
		clean_up(data);
		exit(0);
		return (0);
	}
	if (key_press >= 0 && key_press < 256)
	{
		data->derection[key_press] = 1;
	}
	data->s = 0;
	return (0);
}

int	key_up(int key_press, t_window_data *data)
{
	if (key_press == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
		return (0);
	}
	if (key_press >= 0 && key_press < 256)
	{
		data->derection[key_press] = 0;
	}
	data->s = 0;
	return (0);
}

void	display_string_win(t_window_data *data)
{
	char	*str;
	char	*new;

	mlx_put_image_to_window(data->mlx, data->win, data->stone, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->stone, PLAYER_SIZE, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->stone, PLAYER_SIZE * 2,
		0);
	str = ft_itoa(++data->count_movements);
	new = ft_strjoin("movement: ", str);
	mlx_string_put(data->mlx, data->win, 10, 30, 0xFFFFFF, new);
	free(str);
	free(new);
}
