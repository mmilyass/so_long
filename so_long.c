/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:54:49 by imeftah-          #+#    #+#             */
/*   Updated: 2025/01/09 11:13:02 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_window_data	*do_the_half_job(char *map_file)
{
	t_window_data	*data;

	data = map_holder(map_file);
	data = player_position(data);
	if (map_checker(data) == 2)
	{
		ft_printf("Error\ninvalid map !!\n");
		clean_up(data);
		return (NULL);
	}
	if (data == NULL)
	{
		clean_up(data);
		return (NULL);
	}
	data = window_size(data);
	data = window_maker(data);
	return (data);
}

int	main(int argc, char **argv)
{
	t_window_data	*data;

	if (argc == 2)
	{
		data = do_the_half_job(argv[1]);
		if (data == NULL)
			return (0);
		data = load_images(data);
		if (data == NULL)
		{
			clean_up(data);
			return (0);
		}
		background(data);
		data = display_boxes(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img,
			data->position_width, data->position_height);
		mlx_hook(data->win, 2, KeyPressMask, keys_move, data);
		mlx_loop_hook(data->mlx, game_loop, data);
		mlx_hook(data->win, 17, 0, exit_window, data);
		mlx_loop(data->mlx);
	}
	ft_printf("Error\nenter please a valid argument or just one argument!\n");
}
