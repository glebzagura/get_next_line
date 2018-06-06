/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 19:43:43 by gzagura           #+#    #+#             */
/*   Updated: 2017/12/01 19:43:46 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memchr(const void *src, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char*)src;
	while (len)
	{
		if (*ptr == (unsigned char)c)
			return (ptr);
		ptr++;
		len--;
	}
	return (NULL);
}
