/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:58:14 by amarcel           #+#    #+#             */
/*   Updated: 2019/09/10 11:59:30 by amarcel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#		ifndef PRINTF_H
#		define PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include "../libft/libft.h"



// A SUPP
#include <stdio.h>
typedef	struct		s_printf_list
{
	char		*str;
	char		*strprint;
	int			minl;
	char		*options;
	int			prec;
	char		remp;
	int			read;
	char		*lenght;
	int			i;
	va_list		va;
}					t_printf_list;

int		checkindf(double f, t_printf_list *list);
intmax_t			ft_pow(int n, unsigned int p);
void				ft_putcharf(char c, t_printf_list *list);
void				ft_putstrf(char const *s, t_printf_list *list);
char				*ft_ftoa(long double f, unsigned int prec);
int					ft_strcount(char *string, int c);
void				precminl(t_printf_list *list);
void				precint(t_printf_list *list);
int					initlist(t_printf_list *list);
int					ft_printf(char *string, ...);
char				*ft_stradd(char *src, char *add, int n);
void				ft_read_di(t_printf_list *list);
void				ft_read_di_prec(t_printf_list *list, int size);
void				ft_read_s(t_printf_list *list);
void				ft_read_c(t_printf_list *list);
void				ft_read_o(t_printf_list *list);
void				ft_read_u(t_printf_list *list);
void				ft_read_xp(t_printf_list *list);
int					ft_read_f(t_printf_list *list);
void				ft_read_perc(t_printf_list *list);
int					ft_parseoption(t_printf_list *list);
int					ft_parseminl(t_printf_list *list);
void				ft_parseprec(t_printf_list *list);
int					ft_parseconv(t_printf_list *list);
void				ft_parselenght(t_printf_list *list);
int					printoptions(t_printf_list *list);
void				printdiez(t_printf_list *list);
void				printspace(t_printf_list *list);
void				printplus(t_printf_list *list);
void				printminl(t_printf_list *list);
char				*convertctos(char c);
void				ft_dectoct(unsigned long long int n, t_printf_list *list);
void				ft_dectohex(unsigned long long int n, t_printf_list *list);

#		endif
