/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:44:12 by davli             #+#    #+#             */
/*   Updated: 2024/05/24 14:50:17 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}
/*
int	main()
{
	t_list	*lst = ft_lstnew("first");
//	ft_lstadd_back(&lst, ft_lstnew("second"));
//	ft_lstadd_back(&lst, ft_lstnew("third"));

	t_list	*current = lst;
	while (current)
	{
		printf("Element content: %s\n", (char *)current->content);
		current = current->next;
	}
	return (0);
}
*/
