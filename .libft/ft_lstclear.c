#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;
	t_list	*swap;

	next = *lst;
	while (next)
	{
		del(next->content);
		swap = next->next;
		free(next);
		next = swap;
	}
	*lst = NULL;
}
