/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrady <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 20:48:52 by gabrady           #+#    #+#             */
/*   Updated: 2019/05/16 21:18:12 by gabrady          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	error_put(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr("usage: ./fillit file\n");
		return (0);
	}
	if (!check_file(open(av[1], O_RDONLY)))
	{
		ft_putstr("error\n");
		return (0);
	}
	return (1);
}
