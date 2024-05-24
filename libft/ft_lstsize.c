/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:07:31 by davli             #+#    #+#             */
/*   Updated: 2024/05/24 14:28:41 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
/*
int main(int argc, char **argv)
{
	(void)argc;

	t_list	*lst = NULL;
	t_list	*current = NULL;

	int	i = 1;
	while (i < argc)
	{
		i++;
		t_list *new_elem = ft_lstnew(argv[i]);
		if (!new_elem)
			return (1);
		if (lst == NULL)
		{
			lst = new_elem;
			current = lst;
		}
		else
		{
			current->next = new_elem;
			current = current->next;
		}
	}

	int size = ft_lstsize(lst);
	printf("Size of the list: %d\n", size);
	return (0);
}
*/
