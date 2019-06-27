/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrady <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 13:59:23 by gabrady           #+#    #+#             */
/*   Updated: 2019/04/23 10:39:56 by gabrady          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

#define BLOCK ptrs[0]
#define LINE ptrs[1]
#define TMP ptrs[2]

static char	*get_next_block(int fd)
{
	char	*ptrs[3];
	int		ret;

	BLOCK = NULL;
	while ((ret = get_next_line2(fd, &LINE)) > 0)
	{
		if (BLOCK == NULL)
			BLOCK = ft_strnew(1);
		TMP = ft_strjoin(BLOCK, LINE);
		free(BLOCK);
		BLOCK = TMP;
		if (ft_strlen(LINE) == 1 && LINE[0] == '\n')
		{
			ft_strdel(&LINE);
			break ;
		}
		ft_strdel(&LINE);
	}
	if (BLOCK && !ret)
	{
		TMP = ft_strjoin(BLOCK, "\n");
		free(BLOCK);
		BLOCK = TMP;
	}
	return (BLOCK);
}

static char	**block_join(char **arr, char *block, int len)
{
	char **ret;

	ret = malloc(sizeof(char*) * (len + 1));
	ft_memcpy(ret, arr, sizeof(char *) * len - 1);
	ret[len - 1] = block;
	ret[len] = NULL;
	return (ret);
}

char		**arraymaker(int fd, char ***a, int *l, char **b)
{
	char **t;

	while (((*b) = get_next_block(fd)))
	{
		if (!(check_tetri((*b))))
		{
			free((*b));
			(*l) = 0;
			while ((*a)[(*l)])
				free((*a)[(*l)++]);
			return (NULL);
		}
		t = block_join((*a), (*b), ++(*l));
		free((*a));
		(*a) = t;
	}
	return (*a);
}

t_tet		*read_tetri(int fd)
{
	char	**arr;
	char	*block;
	t_tet	*ret;
	int		len;

	arr = malloc(sizeof(char*) * 1);
	arr[0] = NULL;
	len = 0;
	if (!arraymaker(fd, &arr, &len, &block))
		return (NULL);
	ret = malloc(sizeof(t_tet) * (len + 1));
	ft_bzero(ret + len, sizeof(t_tet));
	len = 0;
	while (arr[len])
	{
		ret[len].block = arr[len];
		ret[len].letter = 'A' + len;
		ret[len++].on_square = 0;
		if (len > 25)
			break ;
	}
	ft_bzero(ret + len, sizeof(t_tet));
	free(arr);
	return (ret);
}
