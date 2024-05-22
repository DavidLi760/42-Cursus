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
