#include "printf.h"

void    ft_dectoct(unsigned long long int n, printf_list *list)
{
    if (n / 8 > 0)
        ft_dectoct(n / 8, list);
    list->strprint = ft_strjoin(list->strprint, ft_itoa(n % 8));
}

char    *convertctos(char c)
{
    char *string;

    string = (char *)malloc(sizeof(char) * 2);
    string[0] = c;
    string[1] = '\0';
    return(string);
}

void    ft_dectohex(unsigned long long int n, printf_list *list)
{
    int debut;

    debut = *list->str != 'p' ? *list->str - 23 : 'a';
    if (n / 16 > 0)
        ft_dectohex(n / 16, list);
    n = n % 16;
    if (n >= 10)
    {
        while(n-- > 10)
            debut++;
        list->strprint = ft_strjoin(list->strprint, convertctos(debut));
    }
    else
        list->strprint = ft_strjoin(list->strprint, ft_itoa(n));
}