/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_images_loader.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:36:08 by imeftah-          #+#    #+#             */
/*   Updated: 2025/01/08 15:50:16 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static t_window_data	*load_images_bonus_1(t_window_data *data)
{
	int	w;
	int	h;

	data->run_frames[0] = mlx_xpm_file_to_image(data->mlx, "textures/1.xpm", &w,
			&h);
	if (data->run_frames[0] == NULL)
		return (NULL);
	data->run_frames[1] = mlx_xpm_file_to_image(data->mlx, "textures/2.xpm", &w,
			&h);
	if (data->run_frames[1] == NULL)
		return (NULL);
	data->run_frames[2] = mlx_xpm_file_to_image(data->mlx, "textures/3.xpm", &w,
			&h);
	if (data->run_frames[2] == NULL)
		return (NULL);
	data->run_frames[3] = mlx_xpm_file_to_image(data->mlx, "textures/4.xpm", &w,
			&h);
	if (data->run_frames[3] == NULL)
		return (NULL);
	return (data);
}

static t_window_data	*load_images_bonus_2(t_window_data *data)
{
	int	w;
	int	h;

	data->run_frames[4] = mlx_xpm_file_to_image(data->mlx, "textures/5.xpm", &w,
			&h);
	if (data->run_frames[4] == NULL)
		return (NULL);
	data->run_frames[5] = mlx_xpm_file_to_image(data->mlx, "textures/6.xpm", &w,
			&h);
	if (data->run_frames[5] == NULL)
		return (NULL);
	data->idle[0] = mlx_xpm_file_to_image(data->mlx, "textures/idle1.xpm", &w,
			&h);
	if (data->idle[0] == NULL)
		return (NULL);
	data->idle[1] = mlx_xpm_file_to_image(data->mlx, "textures/idle2.xpm", &w,
			&h);
	if (data->idle[1] == NULL)
		return (NULL);
	data->idle[2] = mlx_xpm_file_to_image(data->mlx, "textures/idle3.xpm", &w,
			&h);
	if (data->idle[2] == NULL)
		return (NULL);
	return (data);
}

static t_window_data	*load_images_bonus_3(t_window_data *data)
{
	int	w;
	int	h;

	data->coins[0] = mlx_xpm_file_to_image(data->mlx, "textures/d1.xpm", &w,
			&h);
	if (data->coins[0] == NULL)
		return (NULL);
	data->coins[1] = mlx_xpm_file_to_image(data->mlx, "textures/d2.xpm", &w,
			&h);
	if (data->coins[1] == NULL)
		return (NULL);
	data->coins[2] = mlx_xpm_file_to_image(data->mlx, "textures/d3.xpm", &w,
			&h);
	if (data->coins[2] == NULL)
		return (NULL);
	data->coins[3] = mlx_xpm_file_to_image(data->mlx, "textures/d4.xpm", &w,
			&h);
	if (data->coins[3] == NULL)
		return (NULL);
	return (data);
}

t_window_data	*load_images_bonus(t_window_data *data)
{
	data = load_images_bonus_1(data);
	if (data == NULL)
		return (NULL);
	data = load_images_bonus_2(data);
	if (data == NULL)
		return (NULL);
	data = load_images_bonus_3(data);
	if (data == NULL)
		return (NULL);
	data = load_image_bonus_helper(data);
	if (data == NULL)
		return (NULL);
	return (data);
}
