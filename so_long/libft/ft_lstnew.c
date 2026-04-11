/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:23:49 by davli             #+#    #+#             */
/*   Updated: 2024/05/24 11:52:53 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*head;

	head = malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head->content = content;
	head->next = NULL;
	return (head);
}
/*
int	main()
{
	t_list	*elem1 = ft_lstnew("Salut");
	t_list	*elem2 = ft_lstnew("Je m'appelle");
	t_list	*elem3 = ft_lstnew("David");

	if (!elem1 || !elem2 || !elem3)
		return (0);
	elem1->next = elem2;
	elem2->next = elem3;

	t_list *current = elem1;
	while (current)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}

	free(elem1);
	free(elem2);
	free(elem3);
	return (0);
}
*/
