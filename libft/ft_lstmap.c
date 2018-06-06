/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 05:57:26 by gzagura           #+#    #+#             */
/*   Updated: 2017/12/13 05:57:27 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*temp;

	if (!f || !lst)
		return (NULL);
	list = f(lst);
	temp = list;
	while (lst->next)
	{
		temp->next = f(lst->next);
		if (!temp->next)
		{
			free(temp->next);
			return (NULL);
		}
		temp = temp->next;
		lst = lst->next;
	}
	return (list);
}
