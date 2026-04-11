/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:05:41 by davli             #+#    #+#             */
/*   Updated: 2024/05/24 15:12:15 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*stock;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		stock = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = stock;
	}
	*lst = NULL;
}
/*
void del(void *content)
{
	free(content);
}

int main()
{
	t_list *lst = NULL;
	t_list *new_elem;

	int	i = 0;
	while (i < 3)
	{
		char *content = malloc(20 * sizeof(char));
		if (!content)
			return (1);
		snprintf(content, 20, "Element %d", i);
		new_elem = ft_lstnew(content);
		if (!new_elem)
		{
			ft_lstclear(&lst, del);
			return (1);
		}
		new_elem->next = lst;
		lst = new_elem;
		i++;
	}

//	ft_lstclear(&lst, del);

	while (lst)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
	return (0);
}
*/
