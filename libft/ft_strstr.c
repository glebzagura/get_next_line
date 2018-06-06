/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:15:16 by gzagura           #+#    #+#             */
/*   Updated: 2017/12/06 14:15:18 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*p;
	size_t	len;
	int		i;

	len = ft_strlen(needle);
	if (len == 0)
		return ((char*)haystack);
	p = (char*)haystack;
	i = 0;
	while (p[i] != 0)
	{
		if (ft_memcmp((p + i), needle, len) == 0)
			return (p + i);
		i++;
	}
	return (NULL);
}
