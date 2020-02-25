/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solution.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:34:33 by rmonserr          #+#    #+#             */
/*   Updated: 2019/11/27 14:34:35 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_tetri(char **tetri_map, t_tetris *tet, int size, int index)
{
	int counter;
	int x;
	int y;

	counter = 0;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (tet[index].y[counter] < size && tet[index].x[counter] < size &&
				tetri_map[tet[index].y[counter]][tet[index].x[counter]] == '.')
			{
				counter++;
				if (counter == 4)
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_change_tetri(t_tetris *tet, int x, int y, int index)
{
	int		pos_x;
	int		pos_y;
	int		counter;

	pos_x = 100;
	pos_y = 100;
	counter = 0;
	while (counter < 4)
	{
		if (tet[index].x[counter] < pos_x)
			pos_x = tet[index].x[counter];
		if (tet[index].y[counter] < pos_y)
			pos_y = tet[index].y[counter];
		counter++;
	}
	counter--;
	while (counter >= 0)
	{
		tet[index].x[counter] = tet[index].x[counter] - pos_x + x;
		tet[index].y[counter] = tet[index].y[counter] - pos_y + y;
		counter--;
	}
}

char	**ft_algo(char **tetri_map, t_tetris *tet, int size, int index)
{
	int		x;
	int		y;
	char	**map;

	if (tet[index].tetramino_id == '0')
		return (tetri_map);
	map = NULL;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			ft_change_tetri(tet, x, y, index);
			if (ft_check_tetri(tetri_map, tet, size, index))
				map = ft_algo(ft_insert_tetri(tetri_map, tet, size, index),
					tet, size, (index + 1));
			if (map)
				return (map);
			tetri_map = ft_remove_tetri(tetri_map, tet, size, index);
			x++;
		}
		y++;
	}
	return (NULL);
}

void	ft_solution(t_tetris *tetraminoes)
{
	char		**result;
	char		**tetri_map;
	int			size;
	int			index;

	tetri_map = NULL;
	index = 0;
	size = ft_board_size(tetraminoes) - 1;
	result = NULL;
	tetri_map = ft_new_map(tetri_map, size);
	while (!(result = ft_algo(tetri_map, tetraminoes, size, index)))
	{
		ft_clear_map(tetri_map, size);
		size++;
		tetri_map = ft_new_map(tetri_map, size);
	}
	ft_out_map(result, size);
}
