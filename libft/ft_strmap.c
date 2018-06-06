/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:47:57 by gzagura           #+#    #+#             */
/*   Updated: 2017/12/12 17:47:59 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*string;
	int		i;

	i = -1;
	if (s && f)
	{
		string = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (!string)
			return (NULL);
		while (*(s + ++i) != '\0')
			*(string + i) = f(*(s + i));
		*(string + i) = '\0';
		return (string);
	}
	return (NULL);
}
