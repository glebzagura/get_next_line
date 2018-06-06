/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 05:55:44 by gzagura           #+#    #+#             */
/*   Updated: 2017/12/13 05:55:45 by gzagura          ###   ########.fr       */
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

void			ft_putnbr_fd(int n, int fd)
{
	int	del;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n == 0)
	{
		ft_putstr_fd("0", fd);
		return ;
	}
	del = get_del(n);
	while (del != 0)
	{
		ft_putchar_fd((n / del) + '0', fd);
		n -= del * (n / del);
		del /= 10;
	}
}
