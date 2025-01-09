/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:51:16 by imeftah-          #+#    #+#             */
/*   Updated: 2025/01/08 17:01:40 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_coins(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == 'C')
			count++;
		i++;
	}
	return (count);
}

static t_window_data	*inisialize(t_window_data *data, char *map_file)
{
	data->mlx = NULL;
	data->win = NULL;
	data->door = NULL;
	data->back = NULL;
	data->stone = NULL;
	data->coin = NULL;
	data->img = NULL;
	data->count = 0;
	data->c = '\0';
	data->movement_counter = 0;
	data->holder_map = malloc(1);
	if (data->holder_map == NULL)
		return (NULL);
	data->holder_map[0] = '\0';
	data->fd_map = open(map_file, O_RDONLY);
	if (data->fd_map < 0)
		return (NULL);
	return (data);
}

static char	*fill_holder(t_window_data *data)
{
	char	*buffer;
	int		t;

	while (1)
	{
		buffer = malloc(2);
		if (buffer == NULL)
			return (NULL);
		t = read(data->fd_map, buffer, 1);
		if (t < 0)
			return (free(buffer), NULL);
		if (t == 0)
		{
			free(buffer);
			break ;
		}
		buffer[1] = '\0';
		data->new_holder = ft_strjoin(data->holder_map, buffer);
		if (data->new_holder == NULL)
			return (free(buffer), NULL);
		free(buffer);
		free(data->holder_map);
		data->holder_map = data->new_holder;
	}
	return (data->holder_map);
}

t_window_data	*map_holder(char *map_file)
{
	t_window_data	*data;

	data = malloc(sizeof(t_window_data));
	if (data == NULL)
		return (NULL);
	data = inisialize(data, map_file);
	if (data == NULL)
		return (NULL);
	data->holder_map = fill_holder(data);
	if (data->holder_map == NULL)
		return (NULL);
	data->coin_count = count_coins(data->holder_map);
	data->map = ft_split(data->holder_map, '\n');
	if (data->map == NULL)
		return (NULL);
	return (data);
}
