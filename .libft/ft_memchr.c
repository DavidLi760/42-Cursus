#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*b;
	size_t			i;

	b = (unsigned char *)s;
	i = 0;
	while (i < n)
		if (b[i++] == (unsigned char)c)
			return (b + i - 1);
	return (NULL);
}
