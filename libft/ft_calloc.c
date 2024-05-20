#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *mem;

	mem = malloc(count * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, count * size);
	return (mem);
}
/*
int	main()
{
	printf("%p", ft_calloc(5, 1));
}
*/
