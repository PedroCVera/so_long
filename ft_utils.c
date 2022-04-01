/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:45:16 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/04/01 11:45:18 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	***map(void)
{
	static char	**map;

	return (&map);
}

int	ft_xlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (*str && str[i - 1] != '\n')
		i++;
	return (i);
}

void	free_matrix(char ***str)
{
	int	i;

	i = 0;
	while ((*str)[i])
	{
		free((*str)[i]);
		i++;
	}
	free(*str);
}

int	check_object(char **str, char c)
{
	int	i;
	int	i2;

	i = 0;
	while (str[i])
	{
		i2 = 0;
		while (str[i][i2] != '\n' && str[i][i2] != c)
			i2++;
		if (str[i][i2] == c)
			return (1);
		i++;
	}
	return (0);
}

int	check_invalid(char **str)
{
	int	i;
	int	i2;

	i = 0;
	while (str[i])
	{
		i2 = 0;
		while (str[i] && str[i][i2])
		{
			if (str[i][i2] == '\n')
				i2++;
			if (str[i][i2] && (str[i][i2] != '0' && str[i][i2] != '1'
			&& str[i][i2] != 'P' && str[i][i2] != 'C'
			&& str[i][i2] != 'E'))
				return (0);
			i2++;
			if (str[i][i2])
				return (1);
		}
		i++;
	}
	return (1);
}
