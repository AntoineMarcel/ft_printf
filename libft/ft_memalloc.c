/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 09:39:48 by amarcel           #+#    #+#             */
/*   Updated: 2018/11/16 09:45:39 by amarcel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *renvoie;

	renvoie = (char *)malloc(sizeof(char) * size);
	if (!renvoie)
		return (NULL);
	while (size-- > 0)
		renvoie[size] = '\0';
	return ((void *)renvoie);
}
