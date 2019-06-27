/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrady <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 17:37:04 by gabrady           #+#    #+#             */
/*   Updated: 2019/05/23 20:03:55 by gabrady          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*move_tetri_vertically(char *block)
{
	int i;
	int shift;

	i = 0;
	shift = 0;
	while (block[i] && block[i] != '#')
		i++;
	if (i >= 5)
		shift = i / 5;
	i = 0;
	while (block[i])
	{
		if (block[i] == '#' && shift > 0)
		{
			block[i - (shift * 5)] = '#';
			block[i] = '.';
		}
		i++;
	}
	return (block);
}

static char	*move_tetri_horizontally(char *block)
{
	int i;
	int shift;

	i = 0;
	shift = -1;
	while (block[i])
	{
		if (block[i] == '#')
		{
			if (shift == -1 || i % 5 < shift)
				shift = i % 5;
		}
		i++;
	}
	i = 0;
	while (block[i])
	{
		if (block[i] == '#' && shift > 0)
		{
			block[i - shift] = '#';
			block[i] = '.';
		}
		i++;
	}
	return (block);
}

static char	*move_tetri_to_corner(char *block)
{
	block = move_tetri_vertically(block);
	block = move_tetri_horizontally(block);
	return (block);
}

char		*check_tetri(char *tet)
{
	tet = move_tetri_to_corner(tet);
	if (ft_strlen(tet) != 21 || tet[20] != '\n' || tet[19] != '\n')
	{
		return (NULL);
	}
	if (!compare_tetri(tet))
	{
		return (NULL);
	}
	return (tet);
}
