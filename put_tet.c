/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tet.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrady <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 21:11:24 by gabrady           #+#    #+#             */
/*   Updated: 2019/05/16 16:03:15 by gabrady          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define X (i % 5)
#define Y (i / 5)

int	put_tet(char *square, t_tet *tet, int offset)
{
	int i;
	int len;

	if (tet->on_square || tet == NULL || square == NULL ||\
			tet->block == NULL || tet == NULL)
		return (0);
	len = 0;
	while (square[len] && square[len] != '\n')
		len++;
	len++;
	i = 0;
	while (tet->block[i])
	{
		if (tet->block[i] == '#' && square[offset + (len * Y) + X] != '.')
			return (0);
		i++;
	}
	i = 0;
	while (tet->block[i])
	{
		if (tet->block[i] == '#')
			square[offset + (len * Y) + X] = tet->letter;
		i++;
	}
	return ((tet->on_square = 1));
}
