/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:36:14 by rmonserr          #+#    #+#             */
/*   Updated: 2019/09/17 14:36:15 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*newstr;

	newstr = (char *)malloc(size + 1);
	if (newstr == NULL)
		return (NULL);
	ft_memset(newstr, 0, size + 1);
	return (newstr);
}
