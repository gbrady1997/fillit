/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   embiggen_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrady <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 21:09:20 by gabrady           #+#    #+#             */
/*   Updated: 2019/05/03 21:09:53 by gabrady          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*embiggen_square(char **square)
{
	int len;
	int i;

	len = 0;
	while ((*square)[len] != '\n')
	{
		len++;
	}
	len++;
	free(*square);
	*square = malloc(sizeof(char) * len * ((len + 1) + 1));
	i = 0;
	while (i < (len * (len + 1)))
	{
		(*square)[i] = ((i + 1) % (len + 1)) ? '.' : '\n';
		i++;
	}
	(*square)[i] = '\0';
	return (*square);
}
