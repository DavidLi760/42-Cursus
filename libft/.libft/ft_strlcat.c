#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t startlen;
	size_t retlen;

	startlen = 0;
	while (startlen < dstsize && dst[startlen])
		startlen++;
	retlen = ft_strlen(src) + startlen;
	dst += startlen;
	if (dstsize != startlen)
	{
		while (*src)
		{
			if (dstsize > startlen + 1)
			{
				*dst++ = *src;
				dstsize--;
			}
			src++;
		}
		*dst = 0;
	}
	return (retlen);
}
