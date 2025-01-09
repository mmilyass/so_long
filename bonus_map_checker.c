/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_map_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:43:23 by imeftah-          #+#    #+#             */
/*   Updated: 2025/01/08 17:23:29 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_one(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[0][j])
	{
		if (map[0][j] != '1')
			return (2);
		j++;
	}
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (2);
		i++;
	}
	j = 0;
	while (map[i - 1][j])
	{
		if (map[i - 1][j] != '1')
			return (2);
		j++;
	}
	return (1);
}

static int	incrementation(char *map, int *player, int *exit, int *coin)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == 'P')
			(*player)++;
		else if (map[i] == 'E')
			(*exit)++;
		else if (map[i] == 'C')
			(*coin)++;
		else if (map[i] != 'P' && map[i] != 'C' && map[i] != 'E'
			&& map[i] != '1' && map[i] != '0' && map[i] != 'M')
			return (2);
		i++;
	}
	return (1);
}

int	if_cwpe(char **map)
{
	int	i;
	int	wach;
	int	exit;
	int	player;
	int	coin;

	i = 0;
	player = 0;
	exit = 0;
	coin = 0;
	while (map[i])
	{
		wach = incrementation(map[i], &player, &exit, &coin);
		if (wach == 2)
			return (2);
		i++;
	}
	if (player != 1 || exit != 1 || coin <= 0)
		return (2);
	return (1);
}

int	map_checker_bonus(t_window_data *data)
{
	int	count;

	count = 0;
	while (data->map[count] != NULL)
	{
		if (ft_strlen(data->map[0]) != ft_strlen(data->map[count]))
			return (2);
		count++;
	}
	if (check_one(data->map) == 2)
		return (2);
	if (if_cwpe(data->map) == 2)
		return (2);
	if (flood_fill_checker(data, data->position_width / PLAYER_SIZE,
			data->position_height / PLAYER_SIZE) == 2)
		return (2);
	return (1);
}
