/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:57:24 by gzagura           #+#    #+#             */
/*   Updated: 2017/12/01 13:57:26 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ref1;
	unsigned char	*ref2;

	ref1 = (unsigned char *)dst;
	ref2 = (unsigned char *)src;
	if ((int)dst < (int)src)
		ft_memcpy(dst, src, len);
	else
		while (len--)
			*(ref1 + len) = *(ref2 + len);
	return (dst);
}
