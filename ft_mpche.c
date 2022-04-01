/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mpche.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:47:13 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/03/28 14:47:15 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	check_objects(char **str)
{
	if (!check_object(str, 'P'))
		return (0);
	if (!check_object(str, 'C'))
		return (0);
	if (!check_object(str, 'E'))
		return (0);
	return (1);
}

int	check_map(char **str)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	while (str[i])
		i++;
	i--;
	while (str[0][i2] && str[i][i2] && str[0][i2] != '\n' && str[i][i2] != '\n')
	{
		if (str[0][i2] != '1' || str[i][i2] != '1')
			return (0);
		i2++;
	}
	while (i > 0)
	{
		if (str[i][0] != '1' || str[i][ft_strlen(str[i]) - 2] != '1')
			return (0);
		i--;
	}
	if (!check_objects(str))
		return (0);
	return (1);
}

int	check_length(char **str)
{
	int	i;

	i = 0;
	if (ft_xlen(str[i]) < 6)
		return (0);
	i = 1;
	while (str[i])
	{
		if (ft_xlen(str[i]) != ft_xlen(str[i - 1]))
			return (0);
		i++;
	}
	return (1);
}

int	map_y(char *name)
{
	char	c[2];
	int		fd;
	int		i;

	i = 0;
	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (0);
	while (read(fd, c, 1))
	{
		if (c[0] == '\n' || c[0] == '\0')
		{
			i++;
			c[1] = '\n';
		}
		else
			c[1] = '\0';
	}
	if (c[1] == '\0')
		i++;
	close(fd);
	return (i);
}

int	ft_checkname(char *name)
{
	int	i;
	int	j;

	j = 0;
	i = 4;
	while (name[j] != '\0')
		j++;
	if (name[j - 1] != 'r' || name[j - 2] != 'e'
		|| name[j - 3] != 'b' || name[j - 4] != '.')
		return (0);
	return (1);
}
