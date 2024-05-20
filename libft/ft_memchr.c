#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
		if (str[i++] == (unsigned char)c)
			return ((void *)(str + i));
	return (NULL);
}
/*
int main(void)
{
    const char str[] = "Hello, world!";
    int c = 'H';
    char *result = ft_memchr(str, c, 1);

    if (result)
        printf("Character '%c' found at position: %ld\n", c, result - str);
    else
        printf("Character '%c' not found.\n", c);

    return 0;
}
*/
