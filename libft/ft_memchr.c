/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:46:30 by amarcel           #+#    #+#             */
/*   Updated: 2018/11/21 11:11:29 by amarcel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*src2;

	i = 0;
	src2 = (char *)s;
	while (n-- > 0)
	{
		if (src2[i] == (char)c)
			return (src2 + i);
		i++;
	}
	return (NULL);
}
