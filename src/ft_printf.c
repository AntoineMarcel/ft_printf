/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:05:36 by amarcel           #+#    #+#             */
/*   Updated: 2019/09/09 13:11:35 by amarcel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		printoptions(printf_list *list)
{
	if (ft_strchr(list->options, ' ') != NULL)
		printspace(list);
	if (ft_strchr(list->options, '#') != NULL)
		printdiez(list);
	if (ft_strchr(list->options, '+') != NULL)
		printplus(list);
	if (ft_strchr(list->options, '-') != NULL)
		ft_putstrf(list->strprint, list);
	printminl(list);
	if (ft_strchr(list->options, '-') == NULL)
		ft_putstrf(list->strprint, list);
	list->i++;
	return (0);
}

int		initlist(printf_list *list)
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
	if (ft_strchr("discouxXpf%", list->str[list->i]) != NULL &&\
			list->str[list->i])
		printoptions(list);
	return (0);
}

int		ft_printf(char *string, ...)
{
	printf_list *list;

	list = NULL;
	if (!(list = (printf_list*)malloc(sizeof(printf_list))))
		return (0);
	list->str = ft_strdup(string);
	va_start(list->va, string);
	list->read = 0;
	list->i = 0;
	while (list->str[list->i])
	{
		if (list->str[list->i] == '%')
		{
			initlist(list);
			free(list->options);
			free(list->lenght);
			free(list->strprint);
		}
		else if (list->str[list->i])
			ft_putcharf(list->str[list->i++], list);
	}
	va_end(list->va);
	free(list->str);
	free(list);
	return (list->read);
}
