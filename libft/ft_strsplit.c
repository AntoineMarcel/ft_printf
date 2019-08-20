/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:09:26 by amarcel           #+#    #+#             */
/*   Updated: 2018/11/21 10:56:28 by amarcel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(const char *str, char c)
{
	int i;
	int nb_word;

	i = 0;
	nb_word = 0;
	if (!str || !*str)
		return (0);
	if (str[0] != c)
		nb_word = 1;
	while (str[i])
	{
		if (str[i] == c)
		{
			if (str[i + 1] != c && str[i + 1] != '\0')
			{
				nb_word++;
				i++;
			}
		}
		i++;
	}
	return (nb_word);
}

static char	**ft_strdup_split(char const *str, int i, char **tab, char c)
{
	int j;
	int nb_char;

	j = 0;
	nb_char = 0;
	while (!(str[j] == c) && str[j] != '\0')
	{
		nb_char++;
		j++;
	}
	tab[i] = (char *)malloc(sizeof(char) * nb_char + 1);
	if (tab == NULL)
		return (NULL);
	j = 0;
	while (str[j] != c && str[j] != '\0')
	{
		tab[i][j] = str[j];
		j++;
	}
	tab[i][j] = '\0';
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		k;
	char	**tab;

	i = 0;
	if (!s)
		return (NULL);
	k = ft_count_word(s, c);
	tab = (char **)malloc(sizeof(char *) * (k + 1));
	if (tab == NULL)
		return (NULL);
	while (i < k)
	{
		while (*s == c)
			s++;
		ft_strdup_split(s, i, tab, c);
		while (*s != c && *s != '\0')
			s++;
		i++;
	}
	tab[i] = 0;
	return (tab);
}
