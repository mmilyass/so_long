/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:44:43 by imeftah-          #+#    #+#             */
/*   Updated: 2025/01/08 14:48:49 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	count_coins(char *str)
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

static int	count_boxs(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '1')
			count++;
		i++;
	}
	return (count);
}

static int	count_enemy(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == 'M')
			count++;
		i++;
	}
	return (count);
}

static char	*fill_holder(char *new_holder, int fd, char *holder)
{
	char	*buffer;
	int		t;

	while (1)
	{
		buffer = malloc(2);
		if (buffer == NULL)
			return (NULL);
		t = read(fd, buffer, 1);
		if (t < 0)
			return (free(buffer), NULL);
		if (t == 0)
		{
			free(buffer);
			break ;
		}
		buffer[1] = '\0';
		new_holder = ft_strjoin(holder, buffer);
		if (new_holder == NULL)
			return (free(buffer), free(holder), NULL);
		free(buffer);
		free(holder);
		holder = new_holder;
	}
	return (holder);
}

t_window_data	*map_holder_bonus(t_window_data *data, char *map_file)
{
	char	*new_holder;
	char	*holder;
	int		fd;

	new_holder = NULL;
	holder = malloc(1);
	if (holder == NULL)
		return (NULL);
	holder[0] = '\0';
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (free(holder), NULL);
	holder = fill_holder(new_holder, fd, holder);
	if (holder == NULL)
		return (free(holder), NULL);
	data->coin_count = count_coins(holder);
	data->box_count = count_boxs(holder);
	data->enemy_count = count_enemy(holder);
	data->map = ft_split(holder, '\n');
	if (!data->map)
		return (free(holder), NULL);
	free(holder);
	close(fd);
	return (data);
}
