/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:32:46 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/04/01 12:32:48 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

t_image	*images(void)
{
	static t_image	welp;

	return (&welp);
}

t_mlx	*megalx(void)
{
	static t_mlx	aaa;

	return (&aaa);
}
