#include "printf.h"

void    printminl(printf_list *list)
{
    list->minl = ft_strlen(list->strprint) == 0 && (ft_strchr("c", list->str[list->i]) != NULL) ? list->minl - (ft_strlen(list->strprint) + 1) : list->minl - ft_strlen(list->strprint);
    // la encore , on avait des problemes de largeur minimal avec certain cas de char . Jai trouve une formule qui permet de faire passer ces cas la.
    if((*list->options == '+' || *list->options == ' ') && ft_atoi(list->strprint) > 0)
        list->minl--;
    if (list->str[list->i] == 'd' && list->prec > 0 && ft_strchr(list->options,'0') != NULL && *list->strprint != '-')
        list->remp = ' ';
    if (*list->strprint == '-' && ft_strchr(list->options,'-') == NULL && ft_strchr(list->options,' ') == NULL && list->remp == '0')
    {
        list->strprint++;
        ft_putcharf('-', list);
    }
    while (list->minl > 0)
    {
        ft_putcharf(list->remp, list);
        list->minl--;
    }
}

void    printplus(printf_list *list)
{
    if(ft_atoi(list->strprint) >= 0)
    {
        if (list->prec > 0 && ft_strchr(list->options,'-') == NULL)
        {
            list->strprint = ft_strjoin("+", list->strprint);
            list->minl++;
        }
        else
        {
            ft_putcharf('+', list); //j'affiche juste le + et on print la suite, plutot que de strjoin le + au string.
            list->minl--;
        }
    }
}

void    printspace(printf_list *list)
{
    if ((ft_strcount(list->options, ' ') >= 1)  && (ft_strchr("di", list->str[list->i]) != NULL) && (ft_strchr(list->options,'+') == NULL) && (ft_strchr(list->strprint,'-') == NULL))/*(list->strprint[0] != '-' && list->strprint[0] != '+'))*/
    {
        ft_putcharf(' ', list);
        list->minl--;
    }
}

void    printdiez(printf_list *list)
{
    if(ft_strchr("oxXp",list->str[list->i]) != NULL && ft_atoi(list->strprint) >= 0)
    {
        if (ft_strchr("xXp",list->str[list->i]) != NULL && ft_atoi(list->strprint) > 0)
        {
            precminl(list);
            list->strprint = ft_strjoin((list->str[list->i] != 'X' ? "0x" : "0X"), list->strprint);
        }
        else if (ft_strchr("o",list->str[list->i]) != NULL && list->strprint[0] != '0')
        {
            list->strprint = ft_strjoin("0", list->strprint);
        }
    }
}

void	precminl(printf_list *list)
{
    if (list->minl > 2 && list->remp != ' ')
        while(ft_strlen(list->strprint) < list->minl - 2)
            list->strprint = ft_strjoin("0", list->strprint);
}