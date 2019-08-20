/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:07:19 by amarcel           #+#    #+#             */
/*   Updated: 2018/11/22 15:16:25 by amarcel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		count;
	char	c;
	int		nb;

	count = ft_strlen(str) - 1;
	nb = 0;
	while (nb <= count)
	{
		c = str[nb];
		str[nb] = str[count];
		str[count] = c;
		count--;
		nb++;
	}
	return (str);
}
