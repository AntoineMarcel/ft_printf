#include "printf.h"


int printoptions(printf_list *list)
{
    if (ft_strchr(list->options,' ') != NULL)
        printspace(list);
    if (ft_strchr(list->options,'#') != NULL)
        printdiez(list);
    if (ft_strchr(list->options,'+') != NULL)
        printplus(list);
    if (ft_strchr(list->options,'-') != NULL)
        ft_putstrf(list->strprint, list);
    printminl(list);
    if (ft_strchr(list->options,'-') == NULL)
        ft_putstrf(list->strprint, list);
    list->i++;
    return(0);
}

int initlist(printf_list *list)
{
    list->strprint = ft_strdup("");
    list->remp = ' ';
    list->options = ft_strdup("");
    list->minl = 0;
    list->prec = -1;
    list->lenght = ft_strdup("");
    list->i++;
    if (list->str[list->i])
    { 
        ft_parseoption(list);
        ft_parseminl(list);
        ft_parseprec(list);
        ft_parselenght(list);
        ft_parseconv(list);
    }
    return(0);
}

int ft_printf(char *string, ...)
{
    printf_list *list;
    
    list = NULL;
	if (!(list = (printf_list*)malloc(sizeof(printf_list))))
		return (0);
    list->str = ft_strdup(string);
    va_start (list->va, string);
    list->read = 0;
    list->i = 0;
    while(list->str[list->i])
    {
        if(list->str[list->i] == '%')
        {
            initlist(list);
            if (ft_strchr("discouxXpf%", list->str[list->i]) != NULL && list->str[list->i])
                printoptions(list);
            free(list->options);
            free(list->lenght);
            free(list->strprint);
        }
        else if(list->str[list->i])
        {
            ft_putcharf(list->str[list->i], list);
            list->i++;
        }
    }
    va_end (list->va);
    free(list->str);
    free(list);
    return (list->read);

    
    // char *test;
    // char *tmp;
    // test = ft_strdup("test");
    // tmp = ft_strdup("test");
    // free(test);
    // test = ft_strnew(4);
    // ft_strcat(test, tmp);
    // ft_strcat(test, "po");
    // ft_putendl(test);
    // free(tmp);
    // free(test);
    // return (0);
}


// int main(int argc, char **argv)
// {

//  char c;
//     // ft_printf("%-5d %+12d % 9d %02d %s %c %o %u %x %X\n", 12, -25, 89, 125, "bonjou", 'c', -9, -87, 12, 89);
//     //    printf("%-5d %+12d % 9d %02d %s %c %o %u %x %X\n", 12, -25, 89, 125, "bonjou", 'c', -9, -87, 12, 89);
//     // ft_printf("%% \n", 14562.123456489);
//        c = printf("%hhd \n", 4);   
//     return (0);
// }
//https://perso.liris.cnrs.fr/raphaelle.chaine/COURS/LIFAP6/printf_form.html
//https://www.ibisc.univ-evry.fr/~petit/Enseignement/Modelisation-en-C/printf-conversions-format.pdf