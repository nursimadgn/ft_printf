/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seldogan <seldogan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 15:41:58 by seldogan          #+#    #+#             */
/*   Updated: 2026/08/30 17:22:08 by seldogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>

int     ft_printf(const char *first, ...);
void    ft_findformat(char format, va_list *args);

void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_unsigned_putnbr(unsigned int n);
void	ft_putstr(char *s);

long int	ft_strlen(char *str);
void	ft_putnbr_base(unsigned long int nbr, char *base);
int     check_base(char *str2);

void	ft_putadress(void *nbr);



#endif