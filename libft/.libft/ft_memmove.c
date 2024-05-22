#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (!src && !dst)
		return (dst);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	if (d > s)
		while (len--)
			d[len] = s[len];
	else
		while (i < len)
		{
			d[i] = s[i];
			++i;
		}
	return (dst);
}
