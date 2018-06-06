/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 18:13:58 by gzagura           #+#    #+#             */
/*   Updated: 2017/12/12 18:14:00 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;

	if (!s1 || !s2)
		return (NULL);
	string = (char *)malloc(sizeof(char) * (ft_strlen(s1) +
											ft_strlen(s2) + 1));
	if (!string)
		return (NULL);
	ft_strcpy(string, s1);
	ft_strcpy(string + ft_strlen(s1), s2);
	return (string);
}
