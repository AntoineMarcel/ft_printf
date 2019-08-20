/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:01:28 by amarcel           #+#    #+#             */
/*   Updated: 2018/11/17 14:29:51 by amarcel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*s2;

	s2 = (char *)s;
	i = ft_strlen(s);
	while (s2[i] != (char)c)
	{
		if (i == 0)
			return (NULL);
		i--;
	}
	return (s2 + i);
}
