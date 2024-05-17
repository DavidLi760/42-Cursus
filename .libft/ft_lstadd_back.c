#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*next;

	next = *alst;
	while (next)
	{
		if (next->next == NULL)
		{
			next->next = new;
			return ;
		}
		next = next->next;
	}
	*alst = new;
}
