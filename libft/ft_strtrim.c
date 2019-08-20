/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:16:14 by amarcel           #+#    #+#             */
/*   Updated: 2018/11/21 11:35:20 by amarcel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		lenfinale;
	int		len;
	int		n;
	char	*s2;
	char	*strcpy;

	if (!s)
		return (NULL);
	len = ft_strlen(s) - 1;
	n = 0;
	strcpy = (char *)s;
	while ((s[len] == ' ' || s[len] == '\n' || s[len] == '\t') && len != 0)
		len--;
	while ((s[n] == ' ' || s[n] == '\n' || s[n] == '\t') && s[n])
		n++;
	lenfinale = (len - n) + 2;
	if (lenfinale <= 0)
		lenfinale = 0;
	if (!(s2 = (char *)malloc(sizeof(char) * lenfinale)))
		return (NULL);
	len = 0;
	while (len < lenfinale - 1)
		s2[len++] = strcpy[n++];
	s2[len] = '\0';
	return (s2);
}
