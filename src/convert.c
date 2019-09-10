/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:12:11 by amarcel           #+#    #+#             */
/*   Updated: 2019/09/09 14:31:01 by amarcel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_dectoct(unsigned long long int n, t_printf_list *list)
{
	if (n / 8 > 0)
		ft_dectoct(n / 8, list);
	list->strprint = ft_stradd(list->strprint, ft_itoa(n % 8), 3);
}

char	*convertctos(char c)
{
	char *string;
	char *tmp;

	tmp = (char *)malloc(sizeof(char) * 2);
	string = ft_strdup(tmp);
	string[0] = c;
	string[1] = '\0';
	free(tmp);
	return (string);
}

void	ft_dectohex(unsigned long long int n, t_printf_list *list)
{
	int debut;

	debut = list->str[list->i] != 'p' ? list->str[list->i] - 23 : 'a';
	if (n / 16 > 0)
		ft_dectohex(n / 16, list);
	n = n % 16;
	if (n >= 10)
	{
		while (n-- > 10)
			debut++;
		list->strprint = ft_stradd(list->strprint, convertctos(debut), 3);
	}
	else
		list->strprint = ft_stradd(list->strprint, ft_itoa(n), 3);
}

char	*ft_ftoa(long double f, unsigned int prec)
{
	char			*res;
	char			*tmp;
	long double		nb;
	long double		dec;
	char			*tmp2;

	nb = (f < 0 ? -f : f);
	if (!(tmp = ft_itoa((intmax_t)f)))
		return (NULL);
	if (!(res = ft_strcat(ft_strnew(ft_strlen(tmp) + prec +\
						(prec ? 1 : 0)), tmp)))
		return (NULL);
	free(tmp);
	if (prec)
	{
		ft_strcat(res, ".");
		dec = ft_pow(10, prec + 1) * (nb - (unsigned long)nb);
		dec = (((dec / 10) - ((intmax_t)dec / 10)) * 10) >= 5 ?\
				(dec / 10) + 1 : dec / 10;
		tmp2 = ft_itoa((intmax_t)dec);
		ft_strcat(res, tmp2);
		free(tmp2);
	}
	return (res);
}
