/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:47:36 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/04/08 15:29:16 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	map_checker(char *name, char ***str)
{
	int		fd;
	int		i;

	i = map_y(name);
	if (ft_checkname(name) == 0)
		return (0);
	(*str) = malloc((i + 1) * sizeof(char *));
	if (!(*str))
		return (0);
	i = 0;
	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (0);
	(*str)[i] = get_next_line(fd);
	while ((*str)[i])
		(*str)[++i] = get_next_line(fd);
	if (!check_map((*str)) || !check_length((*str)) || !check_invalid((*str)))
	{
		free_matrix((str));
		return (0);
	}
	return (1);
}

void	ft_playerlimit(void)
{
	int	x;
	int	y;
	int	p;

	p = 0;
	y = 0;
	while ((*map())[y])
	{
		x = 0;
		while ((*map())[y][x])
		{
			if ((*map())[y][x] == 'P')
			{
				p++;
				if (p != 1)
				{
					(*map())[y][x] = '0';
				}
			}
			x++;
		}
		y++;
	}
}

void	acudam(int x, int y, void *mlx, void *mlx_win)
{
	if ((*map())[y][x] == '1')
		mlx_put_image_to_window(mlx, mlx_win,
			(*images()).parede, x * 64, y * 64);
	if ((*map())[y][x] == '0')
		mlx_put_image_to_window(mlx, mlx_win,
			(*images()).chao, x * 64, y * 64);
	if ((*map())[y][x] == 'C')
		mlx_put_image_to_window(mlx, mlx_win,
			(*images()).cole, x * 64, y * 64);
	if ((*map())[y][x] == 'P')
		mlx_put_image_to_window(mlx, mlx_win,
			(*images()).player, x * 64, y * 64);
	if ((*map())[y][x] == 'E')
		mlx_put_image_to_window(mlx, mlx_win,
			(*images()).exit, x * 64, y * 64);
	if ((*map())[y][x] == 'O')
		mlx_put_image_to_window(mlx, mlx_win,
			(*images()).enemy, x * 64, y * 64);
}

int	ola(int xx, int yy, int x, int y)
{
	if ((*map())[yy + y][xx + x] == 'C')
		(*megalx()).coles--;
	if ((*map())[yy + y][xx + x] == 'O')
		perdeste();
	if ((*map())[yy + y][xx + x] == 'E')
	{
		if ((*megalx()).coles == 0)
			helping1();
		else
			return (100);
	}
	return (1);
}
