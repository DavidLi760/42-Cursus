#include "libft.h"

int		count_words(const char *s, char c)
{
	int last;
	int count;

	last = 1;
	count = 0;
	while (*s)
	{
		if (*s != c && last)
			++count;
		last = *s == c;
		++s;
	}
	return (count);
}

int		add_array(const char *s, char c, char **arr)
{
	size_t len;

	len = 0;
	while (s[len] && s[len] != c)
		++len;
	if (!(*arr = malloc(len + 1)))
		return (0);
	ft_memcpy(*arr, s, len);
	(*arr)[len] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	size_t	i;
	int		last;
	char	**arr;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	if (!(arr = malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	arr[words] = 0;
	last = 1;
	i = 0;
	while (*s)
	{
		if (*s != c && last && !add_array(s, c, arr + i++))
			return (NULL);
		last = *s == c;
		++s;
	}
	return (arr);
}
