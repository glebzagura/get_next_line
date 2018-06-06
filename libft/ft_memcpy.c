/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 19:09:12 by gzagura           #+#    #+#             */
/*   Updated: 2017/12/01 19:09:16 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char *d;
	unsigned char *sr;

	d = (unsigned char*)dst;
	sr = (unsigned char*)src;
	while (len > 0)
	{
		*d = *sr;
		d++;
		sr++;
		len--;
	}
	return (dst);
}
