/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:20:13 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/04/11 17:20:14 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit (1);
}

void	free_map(char ***ola)
{
	int	ind;

	ind = 0;
	while ((*ola)[ind] != NULL)
	{
		free((*ola)[ind]);
		ind++;
	}
	free (*ola);
}

void	ft_error(void)
{
	write(1, "Error\n", 6);
	free_map(map());
	exit (1);
}
