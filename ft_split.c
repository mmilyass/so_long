/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:10:39 by imeftah-          #+#    #+#             */
/*   Updated: 2025/01/05 11:25:53 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_words(char *str, char c)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (str[i])
	{
		if ((str[i] != c && (str[i + 1] == c || str[i + 1] == '\0')))
			x++;
		i++;
	}
	return (x);
}

static void	fill_index_array(char *str, char *src, int start, int end)
{
	int	x;

	x = 0;
	while (x < end)
	{
		str[x] = src[start];
		x++;
		start++;
	}
	str[x] = '\0';
}

static void	*free_array(char **array, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(array[i]);
		i++;
	}
	array[index] = NULL;
	return (NULL);
}

static char	**fill_array(char **array, char *s, char c, int words)
{
	int	i;
	int	end;
	int	index;

	index = 0;
	i = 0;
	while (index < words)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		end = 0;
		while (s[i] != c && s[i] != '\0')
		{
			end++;
			i++;
		}
		array[index] = malloc((end + 1) * sizeof(char));
		if (array[index] == NULL)
			return (free_array(array, index));
		fill_index_array(array[index], s, i - end, end);
		index++;
	}
	array[index] = NULL;
	return (array);
}

char	**ft_split(char *s1, char c)
{
	int		words;
	char	**array;
	char	*s;

	if (s1 == NULL)
		return (NULL);
	if (s1[0] == '\0')
	{
		array = malloc(1 * sizeof(char *));
		if (array == NULL)
			return (NULL);
		array[0] = NULL;
		return (array);
	}
	s = (char *)s1;
	words = count_words(s, c);
	array = malloc((words + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	if (fill_array(array, s, c, words) == NULL)
	{
		free(array);
		return (NULL);
	}
	return (array);
}
