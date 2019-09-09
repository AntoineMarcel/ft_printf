/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readconv2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:07:45 by amarcel           #+#    #+#             */
/*   Updated: 2019/09/09 14:08:37 by amarcel          ###   ########.fr       */
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

void	ft_read_s(printf_list *list)
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

void	ft_read_f(printf_list *list)
{
	free(list->strprint);
	if (list->prec <= 0)
		list->prec = 6;
	if (ft_strcmp(list->lenght, "L") == 0)
		list->strprint = ft_ftoa(va_arg(list->va, long double), list->prec);
	else
		list->strprint = ft_ftoa(va_arg(list->va, double), list->prec);
}

void	ft_read_perc(printf_list *list)
{
	free(list->strprint);
	list->strprint = ft_strdup("%");
}

void	ft_read_c(printf_list *list)
{
	free(list->strprint);
	list->strprint = convertctos(va_arg(list->va, int));
}
