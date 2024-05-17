#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*s1;

	s1 = (char *)s;
	i = ft_strlen(s) + 1;
	while (i--)
		if (s1[i] == c)
			return (s1 + i);
	return (NULL);
}
