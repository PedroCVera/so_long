/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solong.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:57:25 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/03/16 14:59:15 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_print(void)
{
	mlx_string_put((*megalx()).mlx, (*megalx()).mlx_win,
		10, 10, 0x00000000, ft_itoa((*megalx()).moves));
}

int	key(int keycode)
{
	if (keycode == 53)
		exit (0);
	if (keycode == 13)
		ft_move(0, -1);
	if (keycode == 0)
		ft_move(-1, 0);
	if (keycode == 1)
		ft_move(0, 1);
	if (keycode == 2)
		ft_move(1, 0);
	mlx_clear_window((*megalx()).mlx, (*megalx()).mlx_win);
	ft_putwindow((*megalx()).mlx, (*megalx()).mlx_win);
	ft_print();
	return (0);
}

void	im_init(int i)
{
	(*images()).parede = mlx_xpm_file_to_image((*megalx()).mlx,
			"./images/water.xpm", &i, &i);
	(*images()).cole = mlx_xpm_file_to_image((*megalx()).mlx,
			"./images/maca.xpm", &i, &i);
	(*images()).chao = mlx_xpm_file_to_image((*megalx()).mlx,
			"./images/grass.xpm", &i, &i);
	(*images()).player = mlx_xpm_file_to_image((*megalx()).mlx,
			"./images/slime.xpm", &i, &i);
	(*images()).exit = mlx_xpm_file_to_image((*megalx()).mlx,
			"./images/buraco.xpm", &i, &i);
	(*images()).enemy = mlx_xpm_file_to_image((*megalx()).mlx,
			"./images/enemy.xpm", &i, &i);
}

void	im_fin(void)
{
	mlx_destroy_image((*megalx()).mlx, (*images()).parede);
	mlx_destroy_image((*megalx()).mlx, (*images()).chao);
	mlx_destroy_image((*megalx()).mlx, (*images()).player);
	mlx_destroy_image((*megalx()).mlx, (*images()).cole);
	mlx_destroy_image((*megalx()).mlx, (*images()).exit);
	mlx_destroy_image((*megalx()).mlx, (*images()).enemy);
}

int	main(int argc, char *argv[])
{
	int		ysize;
	int		xsize;

	if (argc != 2)
		return (0);
	if (!map_checker(argv[1], map()))
		ft_error();
	ysize = map_y(argv[1]) * 64;
	xsize = (ft_xlen((*map())[0]) - 1) * 64;
	ft_playerlimit();
	(*megalx()).mlx = mlx_init();
	(*megalx()).mlx_win = mlx_new_window((*megalx()).mlx,
			xsize, ysize, "so_long!");
	if (!(*megalx()).mlx)
		ft_error();
	im_init(64);
	ft_coles();
	ft_putwindow((*megalx()).mlx, (*megalx()).mlx_win);
	ft_print();
	mlx_hook((*megalx()).mlx_win, 17, 0, ft_exit, 0);
	mlx_key_hook((*megalx()).mlx_win, key, 0);
	mlx_loop((*megalx()).mlx);
	im_fin();
	free_map(map());
}
