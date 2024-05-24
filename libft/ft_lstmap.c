/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:28:50 by davli             #+#    #+#             */
/*   Updated: 2024/05/24 19:22:19 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*current;

	if (!lst || !f || !del)
		return (NULL);
	start = ft_lstnew(f(lst->content));
	current = start;
	while (lst && lst->next)
	{
		if (!current)
			return (NULL);
		current->next = ft_lstnew(f(lst->next->content));
		current = current->next;
		lst = lst->next;
	}
	return (start);
}
/*
void	*transform_string(void *content)
{
	char *str = content;
	char *modified_str = malloc(strlen(str) + strlen("-modified") + 1);
	strcpy(modified_str, str);
	strcat(modified_str, "-modified");
	return modified_str;
}

void print_string_list(t_list *lst)
{
	while (lst)
	{
		printf("%s -> ", (char *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

int main()
{
	t_list *lst = ft_lstnew(strdup("Hello"));
	lst->next = ft_lstnew(strdup("world"));

	print_string_list(lst);

	t_list *transformed_lst = ft_lstmap(lst, &transform_string, &free);

	print_string_list(transformed_lst);

	ft_lstclear(&lst, &free);
	ft_lstclear(&transformed_lst, &free);

	return 0;
}
*/
