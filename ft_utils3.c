/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:30:47 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/04/01 12:30:49 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	perdeste(void)
{
	write(1, "RIP\n", 4);
	exit (0);
}

void	helping1(void)
{
	(*megalx()).moves++;
	exit (0);
}

void	ft_move(int x, int y)
{
	int	xx;
	int	yy;

	yy = 0;
	while ((*map())[yy])
	{
		xx = 0;
		while ((*map())[yy][xx])
		{
			if ((*map())[yy][xx] == 'P' && (*map())[yy + y][xx + x] != '1')
			{
				ola(xx, yy, x, y);
				(*map())[yy][xx] = '0';
				(*map())[yy + y][xx + x] = 'P';
				(*megalx()).moves++;
				return ;
			}
			xx++;
		}
		yy++;
	}
}

void	ft_coles(void)
{
	int	x;
	int	y;

	y = 0;
	while ((*map())[y])
	{
		x = 0;
		while ((*map())[y][x])
		{
			if ((*map())[y][x] == 'C')
				(*megalx()).coles++;
			x++;
		}
		y++;
	}
}

void	ft_putwindow(void *mlx, void *mlx_win)
{
	int	x;
	int	y;

	y = 0;
	while ((*map())[y])
	{
		x = 0;
		while ((*map())[y][x])
		{
			acudam(x, y, mlx, mlx_win);
			x++;
		}
		y++;
	}
}
