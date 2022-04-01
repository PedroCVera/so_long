/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 09:38:37 by pcoimbra          #+#    #+#             */
/*   Updated: 2021/10/22 14:45:19 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_strlenasd(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strduper(const char *s1)
{
	int		ind;
	char	*dest;

	ind = 0;
	dest = malloc((ft_strlenasd(s1) + 1) * sizeof(char));
	if (dest == NULL)
		return (0);
	while (s1[ind] != '\0')
	{
		dest[ind] = s1[ind];
		ind++;
	}
	dest[ind] = '\0';
	return (dest);
}
