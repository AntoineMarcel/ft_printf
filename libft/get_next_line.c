/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 07:58:36 by amarcel           #+#    #+#             */
/*   Updated: 2019/07/05 07:58:38 by amarcel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"

static int	nposition(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

static char	*endstr(char *str)
{
	size_t	len;
	size_t	i;
	char	*ret;

	ret = NULL;
	len = ft_strlen(str);
	i = nposition(str);
	if (!len || (len == 1 && i == 0))
		return (ft_strnew(0));
	if (len == i)
		ret = ft_strdup(str + i);
	if (len != i)
		ret = ft_strdup(str + (i + 1));
	return (ret);
}

static int	readline(char **str, int fd)
{
	char	buffer[BUFF_SIZE + 1];
	int		ret;
	char	*tempo;
	int		flag;

	ret = 1;
	flag = 0;
	while (flag == 0 && (ret = read(fd, buffer, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buffer[ret] = '\0';
		tempo = *str;
		if (!*str)
			*str = ft_strdup(buffer);
		else
			*str = ft_strjoin(*str, buffer);
		if (ft_strlen(*str) == 0)
			return (-1);
		free(tempo);
		if (ft_strchr(*str, '\n') != NULL)
			flag++;
	}
	return (ret);
}

int			get_next_line(const int fd, char **line)
{
	int				ret;
	static char		*str;
	char			*tempo;

	tempo = NULL;
	ret = 0;
	if (fd < 0 || !line)
		return (-1);
	if (str && (ft_strchr(str, '\n') != NULL))
		ret = 1;
	if ((str && ft_strchr(str, '\n') == NULL) || !str)
		ret = readline(&str, fd);
	if (ret == -1)
		return (-1);
	if (!str)
		return (0);
	*line = ft_strsub(str, 0, nposition(str));
	tempo = str;
	str = endstr(str);
	free(tempo);
	return (ft_strlen(*line) == 0 && ret == 0 ? 0 : 1);
}
