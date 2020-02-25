/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 17:18:46 by rmonserr          #+#    #+#             */
/*   Updated: 2019/12/26 17:18:48 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_clear_map(char **tetri_map, int size)
{
	int i;

	i = -1;
	while (++i < size)
		ft_memdel((void **)&tetri_map[i]);
	ft_memdel((void **)&tetri_map);
}
