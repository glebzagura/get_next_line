/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 19:19:32 by gzagura           #+#    #+#             */
/*   Updated: 2017/12/15 19:19:34 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int i;
	int result;

	if (nb == 0 || nb == 1)
		return (nb);
	if (nb < 0)
		return (0);
	i = 1;
	result = 1;
	while (result < nb)
	{
		i++;
		result = i * i;
		if (result == nb)
			return (i);
		if (result > nb)
			return (0);
	}
	return (i);
}
