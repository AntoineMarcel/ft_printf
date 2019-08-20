/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:09:38 by amarcel           #+#    #+#             */
/*   Updated: 2018/11/22 14:38:42 by amarcel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char *tmp;

	tmp = ft_strnew(len);
	if (tmp)
	{
		tmp = ft_memcpy(tmp, src, len);
		dest = ft_memcpy(dest, tmp, len);
	}
	free(tmp);
	return (dest);
}
