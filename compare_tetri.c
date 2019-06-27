/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_tetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrady <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 19:55:04 by gabrady           #+#    #+#             */
/*   Updated: 2019/05/23 20:07:06 by gabrady          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	compare_tetri2(char *tet)
{
	if (ft_strstr("###.\n.#..\n....\n....\n\n", tet))
		return (1);
	else if (ft_strstr(".#..\n##..\n.#..\n....\n\n", tet))
		return (1);
	else if (ft_strstr(".#..\n###.\n....\n....\n\n", tet))
		return (1);
	else if (ft_strstr("#...\n#...\n##..\n....\n\n", tet))
		return (1);
	else if (ft_strstr(".#..\n.#..\n##..\n....\n\n", tet))
		return (1);
	else if (ft_strstr("##..\n.#..\n.#..\n....\n\n", tet))
		return (1);
	else if (ft_strstr("##..\n#...\n#...\n....\n\n", tet))
		return (1);
	else if (ft_strstr("#...\n##..\n.#..\n....\n\n", tet))
		return (1);
	else if (ft_strstr("##..\n##..\n....\n....\n\n", tet))
		return (1);
	return (0);
}

int	compare_tetri(char *tet)
{
	if (ft_strstr("####\n....\n....\n....\n\n", tet))
		return (1);
	else if (ft_strstr("###.\n#...\n....\n....\n\n", tet))
		return (1);
	else if (ft_strstr("###.\n..#.\n....\n....\n\n", tet))
		return (1);
	else if (ft_strstr("#...\n###.\n....\n....\n\n", tet))
		return (1);
	else if (ft_strstr("..#.\n###.\n....\n....\n\n", tet))
		return (1);
	else if (ft_strstr("##..\n.##.\n....\n....\n\n", tet))
		return (1);
	else if (ft_strstr(".#..\n##..\n#...\n....\n\n", tet))
		return (1);
	else if (ft_strstr(".##.\n##..\n....\n....\n\n", tet))
		return (1);
	else if (ft_strstr("#...\n##..\n#...\n....\n\n", tet))
		return (1);
	else if (ft_strstr("#...\n#...\n#...\n#...\n\n", tet))
		return (1);
	return (compare_tetri2(tet));
}
