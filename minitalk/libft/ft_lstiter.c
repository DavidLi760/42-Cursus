/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:28:43 by davli             #+#    #+#             */
/*   Updated: 2024/05/24 15:34:21 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f || !lst)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
void    rot13_char(char *c)
{
    if ('a' <= *c && *c <= 'z')
    {
        *c = (*c - 'a' + 13) % 26 + 'a';
    }
    else if ('A' <= *c && *c <= 'Z')
    {
        *c = (*c - 'A' + 13) % 26 + 'A';
    }
}

void    rot13_str(void *content)
{
    char    *str = (char *)content;
    while (*str)
    {
        rot13_char(str);
        str++;
    }
}

int     main()
{
    t_list  *elem = malloc(sizeof(t_list));
    elem->content = strdup("Ynetr pbjf trarebfvgl pbzrf jvgu punegf");
    elem->next = NULL;

    printf("Original: %s\n", (char *)elem->content);
    ft_lstiter(elem, rot13_str);
    printf("ROT13: %s\n", (char *)elem->content);

    free(elem->content);
    free(elem);

    return 0;
}
*/
