/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrady <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 18:18:16 by gabrady           #+#    #+#             */
/*   Updated: 2019/05/16 16:00:44 by gabrady          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_characters(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	if (i == 0)
		return (0);
	i--;
	if (str[i] == '\n' && str[i - 1] == '\n')
	{
		ft_strdel(&str);
		return (0);
	}
	ft_strdel(&str);
	return (1);
}

int			check_file(int fd)
{
	int		len;
	char	*str;
	char	*tmp;
	char	buf[2];

	str = NULL;
	if ((len = read(fd, buf, 1)) < 1)
		return (0);
	while ((len = read(fd, buf, 1)) > 0)
	{
		if (str == NULL)
			str = ft_strnew(1);
		buf[len] = '\0';
		tmp = ft_strjoin(str, buf);
		free(str);
		str = tmp;
	}
	return (str ? check_characters(str) : 0);
}
