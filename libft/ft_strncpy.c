/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:47:10 by gzagura           #+#    #+#             */
/*   Updated: 2017/12/05 14:47:19 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *s;

	s = dst;
	while (len > 0 && *src != '\0')
	{
		*s++ = *src++;
		len--;
	}
	ft_bzero(s, len);
	return (dst);
}
