/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solved.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrady <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 21:06:32 by gabrady           #+#    #+#             */
/*   Updated: 2019/05/16 20:38:27 by gabrady          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	count_empty_squares(char *square, int offset, int i, t_tet *arr)
{
	int len;
	int empty_squares;
	int count;

	count = 0;
	empty_squares = 0;
	while (arr[count].block)
		count++;
	len = 0;
	while (square[len] != '\n')
	{
		if (square[len] == '.' && len < offset)
			empty_squares += 1;
		len++;
	}
	i = len - 1;
	while (i < offset)
	{
		if (square[++i] == '.')
			empty_squares += 1;
	}
	if (empty_squares > len * len - count * 4)
		return (1);
	return (0);
}

static int	unsolvable(char *square, t_tet *arr, int offset)
{
	int count;
	int len;
	int empty_squares;
	int i;

	count = 0;
	len = 0;
	empty_squares = 0;
	i = 0;
	if (square[offset] == '\n' && square[offset + 1] == '\n')
		return (1);
	return (count_empty_squares(square, offset, i, arr));
}

int			solved(char *square, t_tet *arr, int offset)
{
	int i;

	if (unsolvable(square, arr, offset))
		return (1);
	i = 0;
	while (arr[i].block)
	{
		if (arr[i++].on_square == 0)
			return (0);
	}
	return (2);
}
