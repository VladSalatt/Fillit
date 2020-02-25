/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_zero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 22:26:54 by rmonserr          #+#    #+#             */
/*   Updated: 2019/12/22 22:53:42 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_set_zero(t_tetris *tetraminoes)
{
	int		counter;
	int		xy_counter;

	counter = -1;
	while (++counter < 27)
	{
		tetraminoes[counter].tetramino_id = '0';
		xy_counter = -1;
		while (++xy_counter < 4)
		{
			tetraminoes[counter].x[xy_counter] = 0;
			tetraminoes[counter].y[xy_counter] = 0;
		}
	}
}
