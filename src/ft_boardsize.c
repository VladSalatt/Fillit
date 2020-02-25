/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boardsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 20:42:48 by rmonserr          #+#    #+#             */
/*   Updated: 2019/12/02 20:42:49 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_count_tetraminoes(t_tetris *tetramines)
{
	int			index;

	index = 0;
	while (tetramines[index].tetramino_id != '0')
		index++;
	return (index);
}

int		ft_sqrt(t_tetris *tetraminoes)
{
	int nb;
	int i;

	nb = (ft_count_tetraminoes(tetraminoes) * 4);
	i = 1;
	if (nb > 0)
	{
		while (nb >= (i * i))
		{
			if (nb == i)
				return (0);
			i++;
		}
		return (i);
	}
	else
		return (0);
}

int		ft_board_size(t_tetris *tetraminoes)
{
	int		board_size;

	board_size = ft_sqrt(tetraminoes);
	return (board_size);
}
