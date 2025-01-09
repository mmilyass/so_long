/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:45:37 by imeftah-          #+#    #+#             */
/*   Updated: 2025/01/08 17:10:35 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	clean_up_one(t_window_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
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

void	clean_up(t_window_data *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (data->map[i])
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
	}
	free(data->holder_map);
	clean_up_one(data);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free(data);
}

int	exit_window(t_window_data *data)
{
	clean_up(data);
	exit(0);
	return (0);
}

int	keys_move(int key_press, t_window_data *data)
{
	if (key_press == XK_Escape)
	{
		clean_up(data);
		exit(0);
		return (0);
	}
	if (key_press == XK_w)
		data->derection = 'w';
	else if (key_press == XK_s)
		data->derection = 's';
	else if (key_press == XK_d)
		data->derection = 'r';
	else if (key_press == XK_a)
		data->derection = 'l';
	else
		return (0);
	data->s = 0;
	return (0);
}
