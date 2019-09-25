/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readconv2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:07:45 by amarcel           #+#    #+#             */
/*   Updated: 2019/09/10 16:59:08 by abelkhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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

void	ft_read_s(t_printf_list *list)
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

int	ft_read_f(t_printf_list *list)
{
	char	*tmp;
	double f;
	
	free(list->strprint);
	f = 0.0;
	if (list->prec < 0)
		list->prec = 6;
	if (ft_strcmp(list->lenght, "L") == 0)
		list->strprint = ft_ftoa(va_arg(list->va, long double), list->prec);
	else
	{
		f = va_arg(list->va, double);
		if (checkindf(f, list) == 0)
			return (0);
		list->strprint = ft_ftoa(f, list->prec);
	}
	if (list->prec == 0 && ft_strchr(list->options, '#') != NULL)
		list->strprint = ft_stradd(list->strprint, ".", 1);
	tmp = ft_strchr(list->strprint, '.');
	if (list->prec > 0)
	{
		while (ft_strlen(tmp + 1) < list->prec)
			list->strprint = ft_stradd(list->strprint, "0", 1);
	}
	return (1);
}

void	ft_read_perc(t_printf_list *list)
{
	free(list->strprint);
	list->strprint = ft_strdup("%");
}

void	ft_read_c(t_printf_list *list)
{
	free(list->strprint);
	list->strprint = convertctos(va_arg(list->va, int));
}
