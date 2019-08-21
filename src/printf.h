/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:58:14 by amarcel           #+#    #+#             */
/*   Updated: 2019/07/04 13:58:17 by amarcel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#		ifndef PRINTF_H
#		define PRINTF_H

#include <stdarg.h> 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include "../libft/libft.h"

typedef struct		printf_list
{
    char *str;
    char *strprint;
    int minl;
    char *options;
    int prec;
    char remp;
    int read;
    char *lenght;
    int i;
    va_list	    va;

}					printf_list;

intmax_t		ft_pow(int n, unsigned int p);
void	ft_putcharf(char c, printf_list *list);
void	ft_putstrf(char const *s, printf_list *list);
char					*ft_ftoa(long double f, unsigned int prec);
int    ft_strcount(char *string, int c);
void	precminl(printf_list *list);
int initlist(printf_list *list);
int ft_printf(char *string, ...);

void ft_read_di(printf_list *list);
void ft_read_s(printf_list *list);
void ft_read_c(printf_list *list);
void ft_read_o(printf_list *list);
void ft_read_u(printf_list *list);
void ft_read_xXp(printf_list *list);
void ft_read_f(printf_list *list);
void ft_read_perc(printf_list *list);

int ft_parseoption(printf_list *list);
int ft_parseminl(printf_list *list);
void    ft_parseprec(printf_list *list);
int    ft_parseconv(printf_list *list);
void    ft_parselenght(printf_list *list);

int     printoptions(printf_list *list);
void    printdiez(printf_list *list);
void    printspace(printf_list *list);
void    printplus(printf_list *list);
void    printminl(printf_list *list);

char    *convertctos(char c);
void    ft_dectoct(unsigned long long int n, printf_list *list);
void    ft_dectohex(unsigned long long int n, printf_list *list);

#		endif
