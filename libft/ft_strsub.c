/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:45:42 by amarcel           #+#    #+#             */
/*   Updated: 2018/11/21 11:33:49 by amarcel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	if (!s)
		return (NULL);
	s2 = (char *)malloc(sizeof(char) * len + 1);
	if (!s2)
		return (NULL);
	i = 0;
	while (s[start] && len-- > 0)
		s2[i++] = s[start++];
	s2[i] = '\0';
	return (s2);
}
