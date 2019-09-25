/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkhay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:15:39 by abelkhay          #+#    #+#             */
/*   Updated: 2019/09/10 16:15:52 by abelkhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	printminl(t_printf_list *list)
{
	char *tmp;

	list->minl = list->minl - ft_strlen(list->strprint);
	if (ft_strlen(list->strprint) == 0 && (ft_strchr("c",\
					list->str[list->i]) != NULL))
		list->minl = list->minl - 1;
	if (list->str[list->i] == 'd' && list->prec > 0 && ft_strchr(list->options,\
				'0') != NULL && *list->strprint != '-')
		list->remp = ' ';
	if (list->strprint[0] == '-' && ft_strchr(list->options, '-') == NULL &&\
			ft_strchr(list->options, ' ') == NULL && list->remp == '0')
	{
		tmp = ft_strdup(list->strprint + 1);
		free(list->strprint);
		list->strprint = ft_strdup(tmp);
		free(tmp);
		ft_putcharf('-', list);
	}
	while (list->minl > 0)
	{
		ft_putcharf(list->remp, list);
		list->minl--;
	}
}

void	printplus(t_printf_list *list)
{
	if (ft_atoi(list->strprint) >= 0)
	{
		if ((list->prec > 0 && ft_strchr(list->options, '-') ==\
					NULL) || (list->minl > ft_strlen(list->strprint) &&\
						ft_strchr(list->options, '0') == NULL))
			list->strprint = ft_stradd("+", list->strprint, 2);
		else
		{
			ft_putcharf('+', list);
			list->minl--;
		}
	}
}

void	printspace(t_printf_list *list)
{
	if ((ft_strcount(list->options, ' ') >= 1) &&\
			(ft_strchr(list->strprint, '-') == NULL))
	{
		if ((ft_strchr("di", list->str[list->i]) != NULL) &&\
				(ft_strchr(list->options, '+') == NULL))
		{
			ft_putcharf(' ', list);
			list->minl--;
		}
	}
}

void	printdiez(t_printf_list *list)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strdup(list->strprint);
	while (tmp[i] && !(tmp[i] >= '0' && tmp[i] <= '9'))
		i++;
	if (ft_strchr("oxXp", list->str[list->i]) != NULL &&\
			((ft_atoi(tmp + i) >= 0) || i > 0 || tmp[0]))
	{
		if (ft_strchr("xXp", list->str[list->i]) != NULL &&\
				((ft_atoi(tmp + i) > 0) || i > 0))
		{
			precminl(list);
			list->strprint = ft_stradd((list->str[list->i] !=\
						'X' ? "0x" : "0X"), list->strprint, 2);
		}
		else if (ft_strchr("o", list->str[list->i]) != NULL &&\
				list->strprint[0] != '0')
			list->strprint = ft_stradd("0", list->strprint, 2);
	}
	free(tmp);
}

void	precminl(t_printf_list *list)
{
	if (list->minl > 2 && list->remp != ' ')
		while (ft_strlen(list->strprint) < list->minl - 2)
			list->strprint = ft_stradd("0", list->strprint, 2);
}
