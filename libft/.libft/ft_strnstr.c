#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	if (*needle == 0)
		return ((char *)(haystack));
	i = 0;
	while (i < len && haystack[i])
	{
		j = 0;
		while ((i + j) < len && needle[j] == haystack[i + j])
		{
			j++;
			if (needle[j] == 0)
				return ((char *)(haystack + i));
		}
		++i;
	}
	return (NULL);
}
