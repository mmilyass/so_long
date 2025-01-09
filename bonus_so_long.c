/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_so_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:10:18 by imeftah-          #+#    #+#             */
/*   Updated: 2025/01/08 16:22:39 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static t_window_data	*do_the_half(char *map_file)
{
	t_window_data	*data;

	data = inistialize_one();
	data = map_holder_bonus(data, map_file);
	if (data == NULL)
	{
		clean_up(data);
		return (NULL);
	}
	data = player_position_bonus(data);
	if (map_checker_bonus(data) == 2)
	{
		clean_up(data);
		return (NULL);
	}
	data = window_size_bonus(data);
	data = window_maker_bonus(data);
	if (data == NULL)
	{
		clean_up(data);
		return (NULL);
	}
	return (data);
}

static t_window_data	*do_the_other_half(t_window_data *data)
{
	data = allocation(data);
	if (data == NULL)
	{
		clean_up(data);
		return (NULL);
	}
	data = load_images_bonus(data);
	if (data == NULL)
	{
		clean_up(data);
		return (NULL);
	}
	return (data);
}

int	main(int argc, char **argv)
{
	t_window_data	*data;

	if (argc == 2)
	{
		data = do_the_half(argv[1]);
		if (data == NULL)
			return (0);
		data = do_the_other_half(data);
		if (data == NULL)
			return (0);
		background_bonus(data);
		data = display_boxes_bonus(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img,
			data->position_width, data->position_height);
		mlx_hook(data->win, KeyPress, KeyPressMask, key_down, data);
		mlx_hook(data->win, KeyRelease, KeyReleaseMask, key_up, data);
		mlx_loop_hook(data->mlx, game_loop_bonus, data);
		mlx_hook(data->win, 17, 0L, exit_window_bonus, data);
		mlx_loop(data->mlx);
	}
	ft_printf("enter please a valid argument or just one argument!\n");
}
