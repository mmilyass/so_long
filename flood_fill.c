/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:13:26 by imeftah-          #+#    #+#             */
/*   Updated: 2025/01/08 22:02:33 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_holder(char **holder, int i)
{
	while (i >= 0)
	{
		free(holder[i]);
		i--;
	}
	free(holder);
}

static void	flood_fill(t_window_data *data, char **holder, int width,
		int height)
{
	if (holder[height][width] == '1' || data->map[height][width] == '1')
		return ;
	if (data->map[height][width] == 'E')
	{
		data->c = 'E';
		return ;
	}
	holder[height][width] = '1';
	flood_fill(data, holder, width - 1, height);
	flood_fill(data, holder, width + 1, height);
	flood_fill(data, holder, width, height - 1);
	flood_fill(data, holder, width, height + 1);
}

static char	**holder_to_zero(t_window_data *data)
{
	char	**holder;
	int		i;

	holder = malloc(data->map_check_height * sizeof(char *));
	if (holder == NULL)
		return (NULL);
	i = 0;
	while (data->map[i])
	{
		holder[i] = ft_strdup(data->map[i]);
		if (holder[i] == NULL)
		{
			free_holder(holder, i - 1);
			return (NULL);
		}
		i++;
	}
	return (holder);
}

int	flood_fill_checker(t_window_data *data, int width, int height)
{
	char	**holder;
	int		i;
	int		j;

	holder = holder_to_zero(data);
	if (holder == NULL)
		return (2);
	flood_fill(data, holder, width, height);
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if ((data->map[i][j] == 'C' && holder[i][j] != '1')
				|| (data->map[i][j] == 'E' && data->c != 'E'))
				return (free_holder(holder, i + 1), 2);
			j++;
		}
		i++;
	}
	free_holder(holder, i - 1);
	return (1);
}
