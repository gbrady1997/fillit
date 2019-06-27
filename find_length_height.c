/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_length_height.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrady <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:16:19 by gabrady           #+#    #+#             */
/*   Updated: 2019/05/16 15:23:13 by gabrady          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_colums(t_tet *tet, int i)
{
	int times;

	times = 0;
	while (times <= 4)
	{
		if (tet->block[i] == '#')
			return (1);
		times++;
		i += 5;
	}
	return (0);
}

static int	find_length(t_tet *tet)
{
	int i;

	i = 0;
	tet->length = 0;
	while (i <= 4)
	{
		if (check_colums(tet, i))
			tet->length++;
		i++;
	}
	return (tet->length);
}

static int	check_rows(t_tet *tet, int i)
{
	int times;

	times = 0;
	while (times <= 4)
	{
		if (tet->block[i] == '#')
			return (1);
		times++;
		i++;
	}
	return (0);
}

static int	find_height(t_tet *tet)
{
	int i;

	i = 0;
	tet->height = 0;
	while (i <= 15)
	{
		if (check_rows(tet, i))
			tet->height++;
		i += 5;
	}
	return (tet->height);
}

void		find_length_height(t_tet *tets)
{
	int i;

	i = 0;
	while (tets[i].block)
	{
		tets[i].length = find_length(&tets[i]);
		tets[i].height = find_height(&tets[i]);
		i++;
	}
}
