#include "libft.h"

int	ft_atoi(const char *str)
{
	int		negative;
	long	nbr;

	nbr = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' ||
		*str == '\v' || *str == '\f' || *str == '\r')
		++str;
	if ((negative = 1) && (*str == '+' || *str == '-'))
	{
		negative = *str == '-' ? -1 : 1;
		++str;
	}
	--str;
	while (++str && ft_isdigit(*str))
		nbr = nbr * 10 + (*str - '0');
	return ((int)(nbr * negative));
}
