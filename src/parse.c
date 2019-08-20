#include "printf.h"

int ft_parseoption(printf_list *list)
{
    while (ft_strchr("+-#0 ",*list->str) != NULL)
    {
        list->options = ft_strjoin(list->options, convertctos(*list->str));
        if (*list->str == '0')
            list->remp = '0';
        list->str++;
    }
    if (list->remp == '0' && ft_strchr(list->options,'-') != NULL)
            list->remp = ' ';
    return (0);
}

int ft_parseminl(printf_list *list)
{
    if (*list->str >= '0' && *list->str <= '9')
    {
        list->minl = ft_atoi(list->str);
        while (*list->str >= '0' && *list->str <= '9' )
            list->str++;
    }
    return (0);
}

void    ft_parseprec(printf_list *list)
{
    if (*list->str == '.')
    {
        list->str++;
        if(*list->str >= '1' && *list->str <= '9')
        {
            list->prec = ft_atoi(list->str);
            list->str = list->str + ft_strlen(ft_itoa(list->prec));
        }
        else
        {
            if(*list->str =='0')
                list->str++;
            list->prec = 0;
        }
        
    }
}
void    ft_parselenght(printf_list *list)
{
    if (*list->str == 'h')
    {
        list->lenght = "h";
        list->str++;
        if (*list->str == 'h')
        {
            list->lenght = ft_strjoin(list->lenght, "h");
            list->str++;
        }
    }
    else if (*list->str == 'l')
    {
        list->lenght = "l";
        list->str++;
        if (*list->str == 'l')
        {
            list->lenght = ft_strjoin(list->lenght, "l");
            list->str++;
        }
    } 
    else if (*list->str == 'L')
    {
        list->lenght = "L";
        list->str++;
    }
}

int    ft_parseconv(printf_list *list)
{
    if (*list->str == 'd' || *list->str == 'i')
        ft_read_di(list);
    else if (*list->str == 's')
        ft_read_s(list);
    else if (*list->str == 'c')
        ft_read_c(list);
    else if (*list->str == 'o')
        ft_read_o(list); 
    else if (*list->str == 'u')
        ft_read_u(list);
    else if (*list->str == 'x' || *list->str == 'X' || *list->str == 'p')
        ft_read_xXp(list);
    else if (*list->str == 'f')
        ft_read_f(list);
    else if (*list->str == '%')
        ft_read_perc(list);
    if (ft_strchr("xXuodi", *list->str) && ft_atoi(list->strprint) == 0 && list->prec == 0)
        list->strprint = "";
    return (0);
}