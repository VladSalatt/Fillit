/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:35:19 by rmonserr          #+#    #+#             */
/*   Updated: 2019/11/14 16:35:23 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*ft_my_read(int fd)
{
	size_t		read_result;
	char		buf[BUFF_SIZE + 1];
	char		*str;
	char		*tmp;

	str = ft_strnew(0);
	if (!str)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	read_result = 1;
	while ((read_result = read(fd, buf, BUFF_SIZE != 0)))
	{
		buf[read_result] = '\0';
		tmp = str;
		if (!(str = ft_strjoin(tmp, buf)))
		{
			write(1, "error\n", 6);
			exit(1);
		}
		ft_strdel(&tmp);
	}
	return (str);
}

void		ft_fillit(t_tetris *tetraminoes, char **argv)
{
	int			fd;
	char		*buf;
	int			check;

	fd = (open(argv[1], O_RDONLY));
	if (fd < 0)
	{
		write(1, "nonexistent file\n", 17);
		exit(1);
	}
	buf = ft_my_read(fd);
	if (((check = ft_strlen(buf))) > 545)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	ft_set_zero(tetraminoes);
	ft_input(buf, tetraminoes);
	ft_solution(tetraminoes);
	close(fd);
	ft_strdel(&buf);
}

int			main(int argc, char **argv)
{
	t_tetris tetraminoes[27];

	if (argc == 2)
		ft_fillit(tetraminoes, argv);
	else
	{
		write(1, "usage: ./Fillit [tetraminoes]\n", 31);
		exit(1);
	}
	return (0);
}
