/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:45:41 by user42            #+#    #+#             */
/*   Updated: 2021/03/29 16:45:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_atof(char *nptr)
{
	float	ent;
	float	dec;
	int		size;
	char	tmp;

	tmp = nptr[0];
	ent = (float)ft_atoi(nptr);
	while (*nptr && *nptr != '.')
		nptr++;
	if (*nptr == '.')
		nptr++;
	dec = (float)(ft_atoi(nptr));
	size = ft_strlen(nptr);
	while (size--)
		dec /= 10;
	if (ent <= 0 && tmp == '-')
		return ((ent + -dec));
	return ((ent + dec) * 1);
}
