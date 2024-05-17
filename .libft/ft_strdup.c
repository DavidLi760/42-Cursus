#include "libft.h"

char	*ft_strdup(const char *s1)
{
	void	*s2;
	size_t	memlen;

	memlen = ft_strlen(s1) + 1;
	if (!(s2 = malloc(memlen)))
		return (NULL);
	ft_memcpy(s2, s1, memlen);
	return (s2);
}
