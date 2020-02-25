/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:35:47 by rmonserr          #+#    #+#             */
/*   Updated: 2019/11/14 16:35:49 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE 100

int				ft_valid(char *tetramin);

typedef struct	s_tetris
{
	char			tetramino_id;
	int				x[4];
	int				y[4];
}				t_tetris;

void			ft_input(char *buf, t_tetris *tetraminoes);
int				ft_board_size(t_tetris *tetraminoes);
void			ft_solution(t_tetris *tetraminoes);
char			**ft_insert_tetri
				(char **map, t_tetris *tet, int size, int index);
char			**ft_new_map(char **tetri_map, int size);
char			**ft_remove_tetri
				(char **map, t_tetris *tetraminoes, int size, int index);
void			ft_out_map(char **result, int size);
int				ft_count_tetraminoes(t_tetris *list);
void			ft_recursion_exit(t_tetris **head);
void			ft_recursion_exit(t_tetris **head);
void			ft_set_zero(t_tetris *tetraminoes);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *s);
void			ft_clear_map(char **tetri_map, int size);

#endif
