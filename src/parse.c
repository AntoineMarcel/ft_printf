#include "printf.h"

int ft_parseoption(printf_list *list)
{
    while (ft_strchr("+-#0 ",list->str[list->i]) != NULL)
    {
        list->options = ft_strjoin(list->options, convertctos(list->str[list->i]));
        if (list->str[list->i] == '0')
            list->remp = '0';
        list->i++;
    }
    if (list->remp == '0' && ft_strchr(list->options,'-') != NULL)
            list->remp = ' ';
    return (0);
}

int ft_parseminl(printf_list *list)
{
    if (list->str[list->i] >= '0' && list->str[list->i] <= '9')
    {
        list->minl = ft_atoi(list->str + list->i);
        while (list->str[list->i] >= '0' && list->str[list->i] <= '9' )
            list->i++;
    }
    return (0);
}

void    ft_parseprec(printf_list *list)
{
    if (list->str[list->i] == '.')
    {
        list->i++;
        if(list->str[list->i] >= '1' && list->str[list->i] <= '9')
        {
            list->prec = ft_atoi(list->str + list->i);

            list->i = list->i + ft_strlen(ft_itoa(list->prec));
        }
        else
        {
            if(list->str[list->i] =='0')
                list->i++;
            list->prec = 0;
        }
    }
}

void    ft_parselenght(printf_list *list)
{
    if (list->str[list->i] == 'h')
    {
        list->lenght = ft_strdup("h");
        list->i++;
        if (list->str[list->i] == 'h')
        {
            list->lenght = ft_strjoin(list->lenght, "h");
            list->i++;
        }
    }
    else if (list->str[list->i] == 'l')
    {
        list->lenght = ft_strdup("l");
        list->i++;
        if (list->str[list->i] == 'l')
        {
            list->lenght = ft_strjoin(list->lenght, "l");
            list->i++;
        }
    } 
    else if (list->str[list->i] == 'L')
    {
        list->lenght = ft_strdup("L");
        list->i++;
    }
}

int    ft_parseconv(printf_list *list)
{
    if (list->str[list->i] == 'd' || list->str[list->i] == 'i')
        ft_read_di(list);
    else if (list->str[list->i] == 's')
        ft_read_s(list);
    else if (list->str[list->i] == 'c')
        ft_read_c(list);
    else if (list->str[list->i] == 'o')
        ft_read_o(list); 
    else if (list->str[list->i] == 'u')
        ft_read_u(list);
    else if (list->str[list->i] == 'x' || list->str[list->i] == 'X' || list->str[list->i] == 'p')
        ft_read_xXp(list);
    else if (list->str[list->i] == 'f')
        ft_read_f(list);
    else if (list->str[list->i] == '%')
        ft_read_perc(list);
    if (ft_strchr("xXuodi", list->str[list->i]) && ft_atoi(list->strprint) == 0 && list->prec == 0)
        list->strprint = ft_strdup("");
    return (0);
}