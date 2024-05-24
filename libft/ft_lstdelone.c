/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:50:37 by davli             #+#    #+#             */
/*   Updated: 2024/05/24 15:54:40 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
int main()
{
	t_list  *elem = ft_lstnew("Hello tout le mondo1");
	t_list  *elem2 = ft_lstnew(ft_strdup("Hello tout le mondo2"));
	t_list  *elem3 = ft_lstnew("Hello tout le mondo3");
	elem->next = elem2;
	elem2->next = elem3;

//	elem->next = elem2->next;
//	ft_lstdelone(elem2, free);

	t_list *current = elem;
	while (current)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
}
*/
