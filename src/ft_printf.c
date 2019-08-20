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
	size_t i;

	i = 0;
	while (s[i])
	{
		ft_putcharf(s[i], list);
		i++;
	}
    i = 0;
    if (s[i] == '\0' && ft_strchr("c", *list->str) != NULL) // cette condition cest pour un cas precis du char avec /0.
        ft_putcharf('\0', list); //Comme tu convertis les char en string , on avait des problemes sur certains test de char.
}

char					*ft_ftoa(double f, unsigned int prec)
{
	char			*res;
	char			*tmp;
	long double		nb;
	long double		dec;
	long double		test;
	unsigned int	size;

	nb = (f < 0 ? -f : f);
    if (!(tmp = ft_itoa((intmax_t)f)))
		return (NULL);
	size = ft_strlen(tmp) + prec + (prec ? 1 : 0);
	if (!(res = ft_strcat(ft_strnew(size), tmp)))
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


void	precminl(printf_list *list)
{
    if (list->minl > 2 && list->remp != ' ')
        while(ft_strlen(list->strprint) < list->minl - 2)
            list->strprint = ft_strjoin("0", list->strprint);
}

int initlist(printf_list *list)
{
    list->strprint = "";
    list->remp = ' ';
    list->options = "";
    list->minl = 0;
    list->prec = -1;
    list->lenght = "";
    list->str++;
    ft_parseoption(list);
    ft_parseminl(list);
    ft_parseprec(list);
    ft_parselenght(list);
    //if (list->prec > 0 || list->prec == -1 || *list->str == '%')
        ft_parseconv(list);
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
    while(*list->str)
    {
        if(*list->str == '%')
        {
            initlist(list);
            if (ft_strchr("discouxXp%", *list->str) != NULL) 
                printoptions(list);
            list->str++;   
        }
        else if(*list->str)
        {
            ft_putcharf(*list->str, list);
            list->str++;
        }
    }
    va_end (list->va);
    return (list->read);
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