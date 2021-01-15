/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <cjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 10:07:34 by cjung             #+#    #+#             */
/*   Updated: 2020/12/26 17:35:10 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*cul;

	if (!lst || !f)
		return (NULL);
	if (!(newlst = ft_lstnew(f(lst->content))))
		return (NULL);
	lst = lst->next;
	cul = newlst;
	while (lst)
	{
		if (!(cul = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&newlst, cul);
	}
	return (newlst);
}
