/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_loader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:44:21 by imeftah-          #+#    #+#             */
/*   Updated: 2025/01/07 22:44:24 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	display(t_window_data *data, char c, int width, int height)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->stone, width, height);
	else if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->win,
			data->coin, width, height);
	else if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->win,
			data->door, width, height);
}

t_window_data	*display_boxes(t_window_data *data)
{
	int	width;
	int	height;
	int	j;
	int	i;

	i = 0;
	height = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		width = 0;
		while (data->map[i][j] != '\0')
		{
			display(data, data->map[i][j], width, height);
			width = width + BOX_SIZE;
			j++;
		}
		height = height + BOX_SIZE;
		i++;
	}
	return (data);
}

t_window_data	*load_images(t_window_data *data)
{
	int	w;
	int	h;

	data->coin = mlx_xpm_file_to_image(data->mlx, "textures/d1.xpm", &w, &h);
	if (data->coin == NULL)
		return (NULL);
	data->stone = mlx_xpm_file_to_image(data->mlx, "textures/stone.xpm",
			&w, &h);
	if (data->stone == NULL)
		return (NULL);
	data->door = mlx_xpm_file_to_image(data->mlx, "textures/door.xpm", &w, &h);
	if (data->door == NULL)
		return (NULL);
	data->back = mlx_xpm_file_to_image(data->mlx, "textures/back.xpm", &w, &h);
	if (data->back == NULL)
		return (NULL);
	data->img = mlx_xpm_file_to_image(data->mlx, "textures/idle1.xpm", &w, &h);
	if (data->img == NULL)
		return (NULL);
	return (data);
}

t_window_data	*background(t_window_data *data)
{
	int	width;
	int	height;
	int	i;
	int	j;

	height = 0;
	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		width = 0;
		while (data->map[i][j] != '\0')
		{
			mlx_put_image_to_window(data->mlx, data->win, data->back,
				width, height);
			width = width + BOX_SIZE;
			j++;
		}
		height = height + BOX_SIZE;
		i++;
	}
	return (data);
}
