/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:00:51 by amarcel           #+#    #+#             */
/*   Updated: 2018/11/22 15:05:14 by amarcel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_recursive_factorial(int nb)
{
	if (nb == 0)
		return (1);
	if (nb >= 1 && nb <= 12)
		return (nb * ft_recursive_factorial(nb - 1));
	else
		return (0);
}
