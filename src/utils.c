#include "printf.h"

char *ft_stradd(char *src, char *add, int n)
{
    char *tmp;
    char *tmp2;

    tmp = ft_strdup(src);
    tmp2 = ft_strdup(add);
    if (n == 1 || n == 3)
        free(src);
    if (n == 2 || n == 3)
        free(add);
    src = ft_strnew(ft_strlen(tmp) + ft_strlen(tmp2));
    ft_strcat(src, tmp);
    ft_strcat(src, tmp2);
    free(tmp);
    free(tmp2);
    return (src);
}

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
    if (s[0] == '\0' && ft_strchr("c", list->str[list->i]) != NULL) 
        ft_putcharf('\0', list);
}

char					*ft_ftoa(long double f, unsigned int prec)
{
	char			*res;
	char			*tmp;
	long double		nb;
	long double		dec;
	long double		test;
    char *tmp2;

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
        tmp2 = ft_itoa((intmax_t)dec);
		ft_strcat(res, tmp2);
        free(tmp2);
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
