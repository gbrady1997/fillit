/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 11:33:18 by dgallagh          #+#    #+#             */
/*   Updated: 2019/05/16 15:48:59 by gabrady          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

char	*make_square(t_tet *tets)
{
	char	*square;
	int		count;
	int		len;
	int		i;

	if (!tets)
		return (NULL);
	i = 0;
	count = 0;
	while (tets[count].block)
		count++;
	len = 2;
	while ((len * len) < (count * 4))
	{
		len++;
	}
	square = malloc(sizeof(char) * ((len * (len + 1)) + 1));
	square[len * (len + 1)] = '\0';
	while (i < (len * (len + 1)))
	{
		square[i] = ((i + 1) % (len + 1)) ? '.' : '\n';
		i++;
	}
	return (square);
}
