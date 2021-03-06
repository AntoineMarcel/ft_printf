/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readconv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:57:19 by amarcel           #+#    #+#             */
/*   Updated: 2019/09/10 17:01:28 by abelkhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	precint(t_printf_list *list)
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

void	ft_read_di(t_printf_list *list)
{
	int size;

	free(list->strprint);
	if (ft_strcmp(list->lenght, "hh") == 0)
		list->strprint = ft_itoa((char)va_arg(list->va, int));
	else if (ft_strcmp(list->lenght, "h") == 0)
		list->strprint = ft_itoa((short int)va_arg(list->va, int));
	else if (ft_strcmp(list->lenght, "ll") == 0)
		list->strprint = ft_itoa(va_arg(list->va, long long int));
	else if (ft_strcmp(list->lenght, "l") == 0)
		list->strprint = ft_itoa(va_arg(list->va, long int));
	else
		list->strprint = ft_itoa(va_arg(list->va, int));
	size = ft_atoi(list->strprint) < 0 ?\
			ft_strlen(list->strprint) - 1 : ft_strlen(list->strprint);
	ft_read_di_prec(list, size);
}

void	ft_read_di_prec(t_printf_list *list, int size)
{
	if (list->prec > 0 && size < list->prec)
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
				list->strprint = ft_stradd("0", list->strprint, 2);
	}
}

void	ft_read_o(t_printf_list *list)
{
	if (ft_strcmp(list->lenght, "hh") == 0)
		ft_dectoct((unsigned char)va_arg(list->va, unsigned int), list);
	else if (ft_strcmp(list->lenght, "h") == 0)
		ft_dectoct((unsigned short int)va_arg(list->va, unsigned int), list);
	else if (ft_strcmp(list->lenght, "ll") == 0)
		ft_dectoct(va_arg(list->va, unsigned long long int), list);
	else if (ft_strcmp(list->lenght, "l") == 0)
		ft_dectoct(va_arg(list->va, unsigned long int), list);
	else
		ft_dectoct(va_arg(list->va, unsigned int), list);
	precint(list);
}

void	ft_read_u(t_printf_list *list)
{
	free(list->strprint);
	if (ft_strcmp(list->lenght, "hh") == 0)
		list->strprint = ft_uitoa((unsigned char)va_arg(list->va,\
					unsigned int));
	else if (ft_strcmp(list->lenght, "h") == 0)
		list->strprint = ft_uitoa((unsigned short int)va_arg(list->va,\
					unsigned int));
	else if (ft_strcmp(list->lenght, "ll") == 0)
		list->strprint = ft_uitoa(va_arg(list->va, unsigned long long int));
	else if (ft_strcmp(list->lenght, "l") == 0)
		list->strprint = ft_uitoa(va_arg(list->va, unsigned long int));
	else
		list->strprint = ft_uitoa(va_arg(list->va, unsigned int));
	precint(list);
}
