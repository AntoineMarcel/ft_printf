#include "printf.h"

void    ft_dectoct(unsigned long long int n, printf_list *list)
{
    if (n / 8 > 0)
        ft_dectoct(n / 8, list);
    list->strprint = ft_stradd(list->strprint, ft_itoa(n % 8), 3);
}

 char    *convertctos(char c)
{
    char *string;
    char *tmp;

    tmp = (char *)malloc(sizeof(char) * 2);
    string = ft_strdup(tmp);
    string[0] = c;
    string[1] = '\0';
    free(tmp);
    return(string);
} 


void    ft_dectohex(unsigned long long int n, printf_list *list)
{
    int debut;

    debut = list->str[list->i] != 'p' ? list->str[list->i] - 23 : 'a';
    if (n / 16 > 0)
        ft_dectohex(n / 16, list);
    n = n % 16;
    if (n >= 10)
    {
        while(n-- > 10)
            debut++;
        list->strprint = ft_stradd(list->strprint, convertctos(debut), 1);
    }
    else
        list->strprint = ft_stradd(list->strprint, ft_itoa(n), 3);
}