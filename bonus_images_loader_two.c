/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_images_loader_two.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:50:43 by imeftah-          #+#    #+#             */
/*   Updated: 2025/01/09 11:21:14 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static t_window_data	*load_images_bonus_help(t_window_data *data)
{
	int	w;
	int	h;

	data->enemy[0] = mlx_xpm_file_to_image(data->mlx, "textures/enemy10.xpm", &w,
			&h);
	if (data->enemy[0] == NULL)
		return (NULL);
	data->enemy[1] = mlx_xpm_file_to_image(data->mlx, "textures/enemy2.xpm", &w,
			&h);
	if (data->enemy[1] == NULL)
		return (NULL);
	data->enemy[2] = mlx_xpm_file_to_image(data->mlx, "textures/enemy3.xpm", &w,
			&h);
	if (data->enemy[2] == NULL)
		return (NULL);
	data->enemy[3] = mlx_xpm_file_to_image(data->mlx, "textures/enemy2.xpm", &w,
			&h);
	if (data->enemy[3] == NULL)
		return (NULL);
	return (data);
}

static t_window_data	*load_images_bonus_help1(t_window_data *data)
{
	int	w;
	int	h;

	data->stone = mlx_xpm_file_to_image(data->mlx, "textures/stone.xpm", &w,
			&h);
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
	data->run_frames_left[0] = mlx_xpm_file_to_image(data->mlx,
			"textures/2-1.xpm", &w, &h);
	if (data->run_frames_left[0] == NULL)
		return (NULL);
	data->run_frames_left[1] = mlx_xpm_file_to_image(data->mlx,
			"textures/2-2.xpm", &w, &h);
	if (data->run_frames_left[1] == NULL)
		return (NULL);
	return (data);
}

static t_window_data	*load_images_bonus_help2(t_window_data *data)
{
	int	w;
	int	h;

	data->run_frames_left[2] = mlx_xpm_file_to_image(data->mlx,
			"textures/2-3.xpm", &w, &h);
	if (data->run_frames_left[2] == NULL)
		return (NULL);
	data->run_frames_left[3] = mlx_xpm_file_to_image(data->mlx,
			"textures/2-4.xpm", &w, &h);
	if (data->run_frames_left[3] == NULL)
		return (NULL);
	data->run_frames_left[4] = mlx_xpm_file_to_image(data->mlx,
			"textures/2-5.xpm", &w, &h);
	if (data->run_frames_left[4] == NULL)
		return (NULL);
	data->run_frames_left[5] = mlx_xpm_file_to_image(data->mlx,
			"textures/2-6.xpm", &w, &h);
	if (data->run_frames_left[5] == NULL)
		return (NULL);
	return (data);
}

t_window_data	*load_image_bonus_helper(t_window_data *data)
{
	int	w;
	int	h;

	data->animation_back[0] = mlx_xpm_file_to_image(data->mlx,
			"textures/back1.xpm", &w, &h);
	if (data->animation_back[0] == NULL)
		return (NULL);
	data->animation_back[1] = mlx_xpm_file_to_image(data->mlx,
			"textures/back2.xpm", &w, &h);
	if (data->animation_back[1] == NULL)
		return (NULL);
	data = load_images_bonus_help(data);
	if (data == NULL)
		return (NULL);
	data = load_images_bonus_help1(data);
	if (data == NULL)
		return (NULL);
	data = load_images_bonus_help2(data);
	if (data == NULL)
	{
		return (NULL);
	}
	return (data);
}
