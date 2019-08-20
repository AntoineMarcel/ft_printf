/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:40:23 by amarcel           #+#    #+#             */
/*   Updated: 2018/11/22 14:40:35 by amarcel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlist;

	if (lst)
	{
		newlist = (t_list*)malloc(sizeof(lst));
		if (!newlist)
			return (NULL);
		newlist = f(lst);
		newlist->next = ft_lstmap(lst->next, f);
		return (newlist);
	}
	return (NULL);
}
