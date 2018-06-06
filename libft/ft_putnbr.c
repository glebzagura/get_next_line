/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 05:54:52 by gzagura           #+#    #+#             */
/*   Updated: 2017/12/13 05:54:53 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_del(int nn)
{
	int			del;

	del = 1000000000;
	while ((nn / del) == 0)
		del /= 10;
	return (del);
}

void			ft_putnbr(int n)
{
	int			del;

	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n == 0)
	{
		ft_putstr("0");
		return ;
	}
	del = get_del(n);
	while (del != 0)
	{
		ft_putchar((n / del) + '0');
		n -= del * (n / del);
		del /= 10;
	}
}
