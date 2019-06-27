/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrady <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 14:51:53 by gabrady           #+#    #+#             */
/*   Updated: 2019/05/23 20:07:51 by gabrady          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_tet
{
	char	*block;
	char	on_square;
	char	letter;
	int		height;
	int		length;
}				t_tet;

int				error_put(int ac, char **av);
int				recursive_solve(t_tet *arr, char *square);
int				solved(char *square, t_tet *arr, int offset);
int				put_tet(char *square, t_tet *tet, int offset);
int				take_tet(char *square, t_tet *tet);
int				compare_tetri(char *tet);
int				check_file(int fd);
char			*check_tetri(char *tet);
void			find_length_height(t_tet *arr);
t_tet			*read_tetri(int fd);
int				check_arr(t_tet *arr);
char			*make_square(t_tet *tets);
char			*embiggen_square(char **square);

#endif
