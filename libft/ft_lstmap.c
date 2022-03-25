/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:14:51 by aait-oma          #+#    #+#             */
/*   Updated: 2021/11/20 15:56:57 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*last;
	t_list	*new;

	first = NULL;
	last = NULL;
	while (lst && f)
	{
		new = ft_lstnew(f(lst->content));
		if (new == NULL)
			break ;
		if (first == NULL)
			first = new;
		else
			last->next = new;
		last = new;
		lst = lst->next;
	}
	if (lst != NULL)
		ft_lstclear(&first, del);
	return (first);
}
