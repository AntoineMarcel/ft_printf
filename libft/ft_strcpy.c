/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:48:09 by amarcel           #+#    #+#             */
/*   Updated: 2018/11/14 10:04:41 by amarcel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*temp;
	int		i;

	temp = (char *)src;
	i = 0;
	while (temp[i])
	{
		dest[i] = temp[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
