#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*s1;

	i = 0;
	s1 = (char *)s;
	while (1)
		if (s1[i] == c)
			return (s1 + i);
		else if (s1[i++] == 0)
			break ;
	return (NULL);
}
