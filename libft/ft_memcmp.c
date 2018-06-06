/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:55:12 by gzagura           #+#    #+#             */
/*   Updated: 2017/12/06 12:55:13 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	unsigned char	*cp1;
	unsigned char	*cp2;
	int				diff;

	cp1 = (unsigned char*)buf1;
	cp2 = (unsigned char*)buf2;
	while (count-- != 0)
	{
		diff = *cp1++ - *cp2++;
		if (diff != 0)
			return (diff);
	}
	return (0);
}
