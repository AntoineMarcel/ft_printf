/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 07:58:42 by amarcel           #+#    #+#             */
/*   Updated: 2019/07/05 07:58:44 by amarcel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef GET_NEXT_LINE_H
#	define GET_NEXT_LINE_H

#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include "../libft/libft.h"

#define BUFF_SIZE 3

int	get_next_line(const int fd, char **line);

#	endif
