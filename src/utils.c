/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:08:44 by amarcel           #+#    #+#             */
/*   Updated: 2019/09/09 14:16:38 by amarcel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*ft_stradd(char *src, char *add, int n)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strdup(src);
	tmp2 = ft_strdup(add);
	if (n == 1 || n == 3)
		free(src);
	if (n == 2 || n == 3)
		free(add);
	src = ft_strnew(ft_strlen(tmp) + ft_strlen(tmp2));
	ft_strcat(src, tmp);
	ft_strcat(src, tmp2);
	free(tmp);
	free(tmp2);
	return (src);
}

intmax_t	ft_pow(int n, unsigned int p)
{
	if (!p)
		return (1);
	return (n * ft_pow(n, --p));
}

void		ft_putcharf(char c, t_printf_list *list)
{
	write(1, &c, 1);
	list->read = list->read + 1;
}

void		ft_putstrf(char const *s, t_printf_list *list)
{
	size_t size;

	size = ft_strlen(s);
	write(1, s, size);
	list->read = list->read + size;
	if (s[0] == '\0' && ft_strchr("c", list->str[list->i]) != NULL)
		ft_putcharf('\0', list);
}

int			ft_strcount(char *string, int c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (string[i])
	{
		if (string[i] == c)
			count++;
		i++;
	}
	return (count);
}
