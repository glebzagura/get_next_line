/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:16:21 by gzagura           #+#    #+#             */
/*   Updated: 2017/12/05 15:16:24 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned len1;
	unsigned len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ft_strncpy(&s1[len1], s2, ((len2 < n) ? len2 : n));
	s1[len1 + ((len2 < n) ? len2 : n)] = '\0';
	return (s1);
}
