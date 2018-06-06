/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:47:17 by gzagura           #+#    #+#             */
/*   Updated: 2017/12/06 14:47:18 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	len2;

	if (*str2 == '\0')
		return ((char *)str1);
	len2 = ft_strlen(str2);
	while (*str1 != '\0' && len-- >= len2)
	{
		if (*str1 == *str2 && (ft_memcmp(str1, str2, len2) == 0))
			return ((char *)str1);
		str1++;
	}
	return (NULL);
}
