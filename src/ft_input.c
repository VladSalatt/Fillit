/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:09:39 by rmonserr          #+#    #+#             */
/*   Updated: 2019/11/18 13:09:41 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_tet(char *buf)
{
	int count;
	int result;

	count = 0;
	result = 0;
	while (buf[count])
	{
		if (buf[count] == '#')
			result++;
		count++;
	}
	return (result / 4);
}

int		check_valid_str(char *buf)
{
	int dot;
	int sharp;
	int ret;
	int index;

	dot = 0;
	sharp = 0;
	ret = ft_strlen(buf);
	index = -1;
	if ((ret + 1) % 21 == 0)
	{
		while (buf[++index])
		{
			if ((buf[index] != '.') && (buf[index] != '#') &&
				(buf[index] != '\n'))
				return (0);
			if (buf[index] == '.')
				dot++;
			if (buf[index] == '#')
				sharp++;
		}
		if ((dot % 12 == 0 && sharp % 4 == 0) && (dot != 0 && sharp != 0))
			return (1);
	}
	return (0);
}

void	coords(t_tetris *tetraminoes, char *str, char id, int index)
{
	int			pos;
	int			counter;

	pos = 0;
	counter = 0;
	while (str[pos])
	{
		if (str[pos] == '#')
		{
			tetraminoes[index].x[counter] = pos % 5;
			tetraminoes[index].y[counter] = pos / 5;
			counter++;
		}
		pos++;
	}
	tetraminoes[index].tetramino_id = id;
}

void	ft_to_coords(char *str, char id, t_tetris *tetraminoes)
{
	int		index;

	index = 0;
	if (ft_valid(str) == 0)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	while (tetraminoes[index].tetramino_id != '0')
		index++;
	coords(tetraminoes, str, id, index);
}

void	ft_input(char *buf, t_tetris *tetraminoes)
{
	int		index;
	char	id;
	char	*str;
	int		tet;
	int		start;

	index = 0;
	id = 'A';
	start = 0;
	if (!(check_valid_str(buf)))
	{
		write(1, "error\n", 6);
		exit(1);
	}
	tet = count_tet(buf);
	while (tet > 0)
	{
		ft_to_coords((str = ft_strsub(buf, 0 + start, 20)), id, tetraminoes);
		id += 1;
		tet--;
		start += 21;
		free(str);
	}
}
