#include "libft.h"

char	*ft_itoa(int n)
{
	long	nb;
	int		neg;
	char	*ret;
	int		len;

	neg = n > 0 ? 0 : 1;
	nb = n < 0 ? -((long)n) : n;
	len = n == 0 ? 0 : 1;
	while (nb /= 10)
		++len;
	if (!(ret = malloc(len + neg + 1)))
		return (NULL);
	ret[len + neg] = 0;
	nb = (n < 0 ? -((long)n) : n) * 10;
	while ((len + 1) && (nb /= 10))
		ret[neg + --len] = '0' + nb % 10;
	if (neg)
		ret[0] = n == 0 ? '0' : '-';
	return (ret);
}
