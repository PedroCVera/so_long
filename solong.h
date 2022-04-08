/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:19:50 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/04/08 15:30:22 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "./get_next_line/get_next_line.h"
# include <stdio.h>

//# define malloc(x) NULL

typedef struct s_image {
	void	*chao;
	void	*parede;
	void	*player;
	void	*cole;
	void	*exit;
	void	*enemy;
}				t_image;

typedef struct s_mlx {
	void	*mlx;
	void	*mlx_win;
	int		moves;
	int		coles;
}				t_mlx;

int		map_checker(char *name, char ***str);
int		ft_checkname(char *name);
int		map_y(char *name);
int		check_length(char **str);
int		check_map(char **str);
int		check_objects(char **str);
int		check_invalid(char **str);
int		check_object(char **str, char c);
void	free_matrix(char ***str);
int		ft_xlen(char *str);
char	***map(void);
char	*ft_strduper(const char *s1);
char	*ft_itoa(int n);
void	ft_playerlimit(void);
t_image	*images(void);
t_mlx	*megalx(void);
void	acudam(int x, int y, void *mlx, void *mlx_win);
int		ola(int xx, int yy, int x, int y);
void	perdeste(void);
void	helping1(void);
void	ft_move(int x, int y);
void	ft_coles(void);
void	ft_putwindow(void *mlx, void *mlx_win);
int		ft_exit(void);

#endif
