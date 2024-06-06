/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:32:08 by davli             #+#    #+#             */
/*   Updated: 2024/05/24 14:43:37 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
/*
int	main()
{
	t_list	*lst = ft_lstnew("Premier");
	lst->next = ft_lstnew("Second");
	lst->next->next = ft_lstnew("Troisieme");

	t_list	*last = ft_lstlast(lst);
	if (last)
		printf("Dernier element : %s\n", (char *)last->content);
	return (0);
}
*/
