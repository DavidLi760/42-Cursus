#include "libft.h"

char	*ft_strdup(const char *s)
{
	int	i;
	char	*dup;

	i = 0;
	dup = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!dup)
		return (NULL);
	while (s[i])
		dup[i++] = s[i];
	dup[i] = '\0';
	return (dup);
}
/*
int	main()
{
	printf("%s\n", ft_strdup("Yo les gars"));
}
*/
