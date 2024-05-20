#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (str[i] > 8 && str[i] < 14 || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr *= 10;
		nbr = nbr + str[i] - '0';
		i++;
	}
	return (nbr * sign);
}
/*
#include <stdio.h>
int	main()
{
	printf("%d\n", ft_atoi("-2147483648"));
}
*/
