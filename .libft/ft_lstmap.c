#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *temp;

	new = NULL;
	while (lst)
	{
		if (!(temp = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&new, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&new, temp);
	}
	return (new);
}
