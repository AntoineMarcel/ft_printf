#include "printf.h"

intmax_t		ft_pow(int n, unsigned int p)
{
	if (!p)
		return (1);
	return (n * ft_pow(n, --p));
}

void	ft_putcharf(char c, printf_list *list)
{
	write(1, &c, 1);
    list->read = list->read + 1;
}

void	ft_putstrf(char const *s, printf_list *list)
{
    size_t size;

    size = ft_strlen(s);
    write(1, s, size);
    list->read = list->read + size;
    if (s[0] == '\0' && ft_strchr("c", list->str[list->i]) != NULL) // cette condition cest pour un cas precis du char avec /0.
        ft_putcharf('\0', list); //Comme tu convertis les char en string , on avait des problemes sur certains test de char.
}

char					*ft_ftoa(long double f, unsigned int prec)
{
	char			*res;
	char			*tmp;
	long double		nb;
	long double		dec;
	long double		test;

	nb = (f < 0 ? -f : f);
    if (!(tmp = ft_itoa((intmax_t)f)))
		return (NULL);
	if (!(res = ft_strcat(ft_strnew(ft_strlen(tmp) + prec + (prec ? 1 : 0)), tmp)))
		return (NULL);
	free(tmp);
	if (prec)
	{
		ft_strcat(res, ".");
		dec = ft_pow(10, prec + 1) * (nb - (unsigned long)nb);
        test = ((dec / 10) - ((intmax_t)dec / 10)) * 10;
        dec = test >=5 ? (dec / 10) + 1 : dec / 10;
		ft_strcat(res, ft_itoa((intmax_t)dec));
	}
	return (res);
}

int    ft_strcount(char *string, int c)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while(string[i])
    {
        if (string[i] == c)
            count++;
        i++;
    }
    return(count);
}