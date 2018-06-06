/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:31:43 by gzagura           #+#    #+#             */
/*   Updated: 2017/12/05 17:31:53 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	int		i;
	int		n;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	dst += dst_len;
	i = 0;
	if ((n = (size - dst_len)) <= 0)
		return (src_len + size);
	while (src[i] != 0 && --n > 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst_len + src_len);
}
