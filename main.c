/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrady <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:47:21 by gabrady           #+#    #+#             */
/*   Updated: 2019/05/23 20:11:46 by gabrady          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	t_tet	*arr;
	char	*square;

	if (!(error_put(argc, argv)))
		return (0);
	arr = read_tetri(open(argv[1], O_RDONLY));
	if (!arr)
	{
		ft_putstr("error\n");
		return (0);
	}
	find_length_height(arr);
	square = make_square(arr);
	while (1)
	{
		if (recursive_solve(arr, square))
			break ;
		square = embiggen_square(&square);
	}
	ft_putstr(square);
	return (0);
}
