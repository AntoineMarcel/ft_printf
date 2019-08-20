/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:56:13 by amarcel           #+#    #+#             */
/*   Updated: 2018/11/21 10:56:53 by amarcel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_cpyitoa(char *strint, long int len, intmax_t n2, int neg)
{
	int i;

	i = 0;
	if (neg == 1)
		strint[i++] = '-';
	while (len >= 1)
	{
		strint[i++] = (n2 / len) >= 0 ? (n2 / len) + '0' : (n2 / len) * -1 + '0';
		n2 = n2 % len;
		len = len / 10;
	}
	strint[i] = '\0';
	return (strint);
}

char		*ft_itoa(intmax_t n)
{
	int			i;
	intmax_t	n2;
	char		*strint;
	int			neg;
	long int	len;

	i = 0;
    n2 = n;
	neg = (n2 < 0 ? 1 : 0); 
	len = 1;
	while (n2 / len >= 10 || n2 / len <= -10)
	{
		i++;
		len = len * 10;
	}
	if (!(strint = (char *)malloc(sizeof(char) * i + neg + 2)))
		return (NULL);
	strint = ft_cpyitoa(strint, len, n2, neg);
	return (strint);
}