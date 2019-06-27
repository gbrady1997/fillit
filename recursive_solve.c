/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrady <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 15:46:09 by gabrady           #+#    #+#             */
/*   Updated: 2019/05/16 15:46:38 by gabrady          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	recursive_solve(t_tet *arr, char *square)
{
	int i;
	int len;

	len = 0;
	while (square[len] != '\n')
		len++;
	i = 0;
	if (!(arr->block))
		return (1);
	while (square[i])
	{
		if (put_tet(square, arr, i))
		{
			if (recursive_solve(arr + 1, square))
				return (1);
			take_tet(square, arr);
		}
		i++;
	}
	return (0);
}
