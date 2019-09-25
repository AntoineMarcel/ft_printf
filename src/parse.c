/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkhay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:16:53 by abelkhay          #+#    #+#             */
/*   Updated: 2019/09/25 14:38:54 by amarcel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_parseoption(t_printf_list *list)
{
	while (ft_strchr("+-#0 ", list->str[list->i]) != NULL && list->str[list->i])
	{
		list->options = ft_stradd(list->options,\
				convertctos(list->str[list->i]), 3);
		if (list->str[list->i] == '0' && ft_strchr("discouxXpf%",\
					list->str[list->i + 1]) == NULL)
			list->remp = '0';
		list->i++;
	}
	if (list->remp == '0' && ft_strchr(list->options, '-') != NULL)
		list->remp = ' ';
	return (0);
}

int		ft_parseminl(t_printf_list *list)
{
	if (list->str[list->i] >= '0' && list->str[list->i] <= '9')
	{
		list->minl = ft_atoi(list->str + list->i);
		while (list->str[list->i] >= '0' && list->str[list->i] <= '9')
			list->i++;
	}
	return (0);
}

void	ft_parseprec(t_printf_list *list)
{
	char *tmp;

	if (list->str[list->i] == '.')
	{
		while (list->str[list->i] == '.')
			list->i++;
		if (list->str[list->i] >= '1' && list->str[list->i] <= '9')
		{
			list->prec = ft_atoi(list->str + list->i);
			tmp = ft_itoa(list->prec);
			list->i = list->i + ft_strlen(tmp);
			free(tmp);
		}
		else
		{
			if (list->str[list->i] == '0')
				list->i++;
			list->prec = 0;
		}
	}
}

void	ft_parselenght(t_printf_list *list)
{
	free(list->lenght);
	if (list->str[list->i] == 'h')
	{
		list->lenght = ft_strdup("h");
		if (list->str[list->i + 1] == 'h')
			list->lenght = ft_stradd(list->lenght, "h", 1);
	}
	else if (list->str[list->i] == 'l')
	{
		list->lenght = ft_strdup("l");
		if (list->str[list->i + 1] == 'l')
			list->lenght = ft_stradd(list->lenght, "l", 1);
	}
	else if (list->str[list->i] == 'L')
		list->lenght = ft_strdup("L");
	else
		list->lenght = ft_strdup("");
	list->i = list->i + ft_strlen(list->lenght);
}

int		ft_parseconv(t_printf_list *list)
{
	if (list->str[list->i] == 'd' || list->str[list->i] == 'i')
		ft_read_di(list);
	else if (list->str[list->i] == 's')
		ft_read_s(list);
	else if (list->str[list->i] == 'c')
		ft_read_c(list);
	else if (list->str[list->i] == 'o')
		ft_read_o(list);
	else if (list->str[list->i] == 'u')
		ft_read_u(list);
	else if (list->str[list->i] == 'x' || list->str[list->i] == 'X' ||\
			list->str[list->i] == 'p')
		ft_read_xp(list);
	else if (list->str[list->i] == 'f')
		ft_read_f(list);
	else if (list->str[list->i] == '%')
		ft_read_perc(list);
	if (ft_strchr("xXuodi", list->str[list->i]) != NULL &&\
			ft_atoi(list->strprint) ==\
			0 && list->prec == 0)
	{
		free(list->strprint);
		list->strprint = ft_strdup("");
	}
	return (0);
}
