/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:53:08 by davli             #+#    #+#             */
/*   Updated: 2024/05/24 12:07:14 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
int	main()
{
	t_list	*elem1 = ft_lstnew("Premier");
	t_list	*elem2 = ft_lstnew("Second");
	t_list	*elem3 = ft_lstnew("Troisieme");
	elem1->next = elem2;
	elem2->next = elem3;

//	t_list	*new = ft_lstnew("Zero");
//	ft_lstadd_front(&elem1, new);

	t_list	*current = elem1;
	while (current)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
}
*/
