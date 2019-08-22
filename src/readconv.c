#include "printf.h"

void ft_read_di(printf_list *list)
{
	free(list->strprint);
	if (ft_strcmp(list->lenght,"hh") == 0)
		list->strprint = ft_itoa((char)va_arg(list->va, int));
	else if (ft_strcmp(list->lenght, "h") == 0) 
		list->strprint = ft_itoa((short int)va_arg(list->va, int));
	else if (ft_strcmp(list->lenght, "ll") == 0) 
		list->strprint = ft_itoa(va_arg(list->va, long long int));
	else if (ft_strcmp(list->lenght, "l") == 0) 
		list->strprint = ft_itoa(va_arg(list->va, long int));
	else 
		list->strprint = ft_itoa(va_arg(list->va, int));
	if (list->prec > 0 && ft_strlen(list->strprint) < list->prec)
	{
		if (ft_atoi(list->strprint) < 0)
		{
			list->strprint[0] = '0';
			while (ft_strlen(list->strprint) < list->prec)
				list->strprint = ft_stradd("0", list->strprint, 2);	
			list->strprint = ft_stradd("-", list->strprint, 2);		
		}
		else
			while (ft_strlen(list->strprint) < list->prec)
				list->strprint = ft_stradd("0", list->strprint,2);
	}
}

char	*ft_cut(char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (i >= n)
		 s[i] = '\0';
		 i++;
	}
	return (s);
}

void	precint(printf_list *list)
{
	if (list->prec > 0)
	{
		while (ft_strlen(list->strprint) < list->prec)
			list->strprint = ft_stradd("0", list->strprint, 2);
	}
	if (list->str[list->i] == 'p')
	{
		if (ft_atoi(list->strprint) == 0 && list->prec == 0)
			list->strprint = ft_strdup("0x");
		else
			list->strprint = ft_stradd("0x", list->strprint, 2);
	}
}



void ft_read_s(printf_list *list)
{
	char *tmp;
	
    tmp = (char *)(va_arg(list->va, char *));
	free(list->strprint);
	list->strprint = ft_strjoin("", tmp);
	if (list->strprint == NULL)
	{
		free(list->strprint);
		list->strprint = ft_strdup("(null)");
	}
	if (list->prec != -1)
		list->strprint = ft_cut(list->strprint, list->prec);
}

void ft_read_c(printf_list *list)
{
	free(list->strprint);
    list->strprint = convertctos(va_arg(list->va, int));
}

void ft_read_o(printf_list *list)
{
    if (ft_strcmp(list->lenght,"hh") == 0)
		ft_dectoct((unsigned char)va_arg(list->va, unsigned int), list);
	else if (ft_strcmp(list->lenght,"h") == 0)
		ft_dectoct((unsigned short int)va_arg(list->va, unsigned int), list);
	else if (ft_strcmp(list->lenght,"ll") == 0)
		ft_dectoct(va_arg(list->va, unsigned long long int), list);
	else if (ft_strcmp(list->lenght,"l") == 0)
		ft_dectoct(va_arg(list->va, unsigned long int), list);
	else
		ft_dectoct(va_arg(list->va, unsigned int), list);
	precint(list);
}

void ft_read_u(printf_list *list)
{
	free(list->strprint);
	if (ft_strcmp(list->lenght,"hh") == 0)
		list->strprint = ft_uitoa((unsigned char)va_arg(list->va, unsigned int));
	else if (ft_strcmp(list->lenght,"h") == 0)
		list->strprint = ft_uitoa((unsigned short int)va_arg(list->va, unsigned int));
	else if (ft_strcmp(list->lenght,"ll") == 0)
		list->strprint = ft_uitoa(va_arg(list->va, unsigned long long int));
	else if (ft_strcmp(list->lenght,"l") == 0)
		list->strprint = ft_uitoa(va_arg(list->va, unsigned long int));
	else
		list->strprint = ft_uitoa(va_arg(list->va, unsigned int));
	precint(list);
}

void ft_read_xXp(printf_list *list)
{
	if (list->str[list->i] == 'p')
		ft_dectohex(va_arg(list->va, unsigned long int), list);
	else if (ft_strcmp(list->lenght,"hh") == 0)
		ft_dectohex((unsigned char)va_arg(list->va, unsigned int), list);
	else if (ft_strcmp(list->lenght,"h") == 0)
		ft_dectohex((unsigned short int)va_arg(list->va, unsigned int), list);
	else if (ft_strcmp(list->lenght,"ll") == 0)
		ft_dectohex(va_arg(list->va, unsigned long long int), list);
	else if (ft_strcmp(list->lenght,"l") == 0)
		ft_dectohex(va_arg(list->va, unsigned long int), list);
	else
		ft_dectohex(va_arg(list->va, unsigned int), list);
	precint(list);
}

void ft_read_f(printf_list *list)
{

	free(list->strprint);
	if(list->prec <= 0)
		list->prec = 6;
	if (ft_strcmp(list->lenght,"L") == 0)
		list->strprint = ft_ftoa(va_arg(list->va, long double), list->prec);
	else
		list->strprint = ft_ftoa(va_arg(list->va, double), list->prec);
}

void ft_read_perc(printf_list *list)
{
	free(list->strprint);
   list->strprint = ft_strdup("%");
}

