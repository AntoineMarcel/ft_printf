/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:51:19 by amarcel           #+#    #+#             */
/*   Updated: 2018/11/21 10:51:38 by amarcel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	lendst;
	size_t	lensrc;
	char	*ptrdst;

	lendst = ft_strlen(dest);
	lensrc = ft_strlen(src);
	ptrdst = dest;
	ptrdst = ptrdst + lendst;
	if (lendst >= size)
		return (size + lensrc);
	size = size - lendst;
	while (*src && size > 1)
	{
		*ptrdst = *src;
		ptrdst++;
		src++;
		size--;
	}
	*ptrdst = '\0';
	return (lendst + lensrc);
}
