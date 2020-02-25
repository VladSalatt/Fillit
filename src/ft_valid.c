/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:10:16 by rmonserr          #+#    #+#             */
/*   Updated: 2019/11/18 13:10:17 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_connection_check(char *tetramino, int position)
{
	int		connections;
	int		pos;

	connections = 0;
	pos = position;
	if (pos <= 18 && tetramino[++pos] == '#')
		connections++;
	pos = position;
	if (pos <= 13 && tetramino[pos + 5] == '#')
		connections++;
	pos = position;
	if (pos >= 1 && tetramino[--pos] == '#')
		connections++;
	pos = position;
	if (pos > 4 && tetramino[position - 5] == '#')
		connections++;
	return (connections);
}

int		ft_check_nl(char *tetramino)
{
	if (((tetramino[4] == '\n' && tetramino[9] == '\n' &&
		tetramino[14] == '\n' && tetramino[19] == '\n')) &&
		((tetramino[4 - 1] != '\n' && tetramino[9 - 1] != '\n' &&
		tetramino[14 - 1] != '\n' && tetramino[19 - 1] != '\n'))
		&& (((tetramino[4 + 1] != '\n' && tetramino[9 + 1] != '\n' &&
		tetramino[14 + 1] != '\n'))))
		return (1);
	else
		return (0);
}

int		ft_valid(char *tetramino)
{
	int ret;
	int connections;
	int	sharp_counter;
	int position;

	position = 0;
	sharp_counter = 0;
	connections = 0;
	if (!(ft_check_nl(tetramino)))
		return (0);
	while (tetramino[position])
	{
		if (tetramino[position] == '#')
		{
			ret = ft_connection_check(tetramino, position);
			connections += ret;
			sharp_counter++;
		}
		position++;
	}
	if ((connections == 8 || connections == 6) && sharp_counter == 4)
		return (1);
	else
		return (0);
}
