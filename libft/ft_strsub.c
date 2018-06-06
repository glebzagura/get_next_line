/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 18:13:20 by gzagura           #+#    #+#             */
/*   Updated: 2017/12/12 18:13:23 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*string;
	int		i;

	if (!s || start + len > ft_strlen(s))
		return (NULL);
	i = -1;
	string = (char *)malloc(sizeof(char) * (len + 1));
	if (!string)
		return (NULL);
	while (++i < (int)len)
		*(string + i) = *(s + start + i);
	*(string + i) = '\0';
	return (string);
}
