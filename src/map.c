/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 19:21:09 by rmonserr          #+#    #+#             */
/*   Updated: 2019/12/16 19:21:16 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_new_map(char **tetri_map, int size)
{
	int	x;
	int	y;

	y = -1;
	if (size <= 0)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	if (!(tetri_map = ft_memalloc(sizeof(char *) * size + 1)))
		return (NULL);
	while (++y < size)
	{
		if (!(tetri_map[y] = ft_memalloc(sizeof(char ) * size + 1)))
			return (NULL);
		x = -1;
		while (++x < size)
			tetri_map[y][x] = '.';
		tetri_map[y][x] = '\0';
	}
	return (tetri_map);
}

char	**ft_remove_tetri(char **map, t_tetris *tet, int size, int index)
{
	int x;
	int y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (map[y][x] == tet[index].tetramino_id)
				map[y][x] = '.';
			x++;
		}
		y++;
	}
	return (map);
}

char	**ft_insert_tetri(char **map, t_tetris *tet, int size, int index)
{
	int x;
	int y;
	int counter;

	counter = 0;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (tet[index].y[counter] == y && tet[index].x[counter] == x)
			{
				map[y][x] = tet[index].tetramino_id;
				counter++;
			}
			x++;
		}
		y++;
	}
	return (map);
}
