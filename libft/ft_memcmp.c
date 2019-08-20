/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:41:22 by amarcel           #+#    #+#             */
/*   Updated: 2018/11/16 15:23:20 by amarcel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1cpy;
	unsigned char	*s2cpy;

	i = 0;
	s1cpy = (unsigned char *)s1;
	s2cpy = (unsigned char *)s2;
	while (i < n)
	{
		if (s1cpy[i] != s2cpy[i])
			return (s1cpy[i] - s2cpy[i]);
		i++;
	}
	return (0);
}
