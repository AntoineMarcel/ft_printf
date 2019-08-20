/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:12:05 by amarcel           #+#    #+#             */
/*   Updated: 2018/11/14 11:51:46 by amarcel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*dest2;
	char	*src2;
	char	c2;

	i = 0;
	dest2 = (char *)dest;
	src2 = (char *)src;
	c2 = (char)c;
	while (i < n)
	{
		dest2[i] = src2[i];
		if (src2[i] == c2)
			return (dest2 + i + 1);
		i++;
	}
	return (NULL);
}
