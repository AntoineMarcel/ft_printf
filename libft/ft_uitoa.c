#include "libft.h"

static char	*ft_cpyitoa(char *strint, unsigned long long int len, uintmax_t n2)
{
	int i;

	i = 0;
	while (len >= 1)
	{
		strint[i++] = (n2 / len) + '0';
		n2 = n2 % len;
		len = len / 10;
	}
	strint[i] = '\0';
	return (strint);
}

char		*ft_uitoa(uintmax_t n)
{
	int			i;
	uintmax_t	n2;
	char		*strint;
	unsigned long long int	len;

	i = 0;
    n2 = n;
	len = 1;
	while (n2 / len >= 10 )
	{
		i++;
		len = len * 10;
	}
	if (!(strint = (char *)malloc(sizeof(char) * i + 2)))
		return (NULL);
	strint = ft_cpyitoa(strint, len, n2);
	return (strint);
}