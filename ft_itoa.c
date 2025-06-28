#include "libft.h"

static int	count_len(int n)
{
	int	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	unsigned int	nbr;

	len = count_len(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		nbr = -n;
	}
	else
		nbr = n;
	if (nbr == 0)
		str[0] = '0';
	while (nbr)
	{
		str[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}
