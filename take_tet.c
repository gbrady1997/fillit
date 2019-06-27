/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_tet.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrady <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 15:03:54 by gabrady           #+#    #+#             */
/*   Updated: 2019/05/03 21:17:27 by gabrady          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	take_tet(char *square, t_tet *tet)
{
	int i;

	i = 0;
	if (square == NULL || tet == NULL)
		return (0);
	while (square[i])
	{
		if (square[i] == tet->letter)
			square[i] = '.';
		i++;
	}
	tet->on_square = 0;
	return (1);
}
