/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seldogan <seldogan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 15:41:58 by seldogan          #+#    #+#             */
/*   Updated: 2026/08/29 19:07:30 by seldogan         ###   ########.fr       */
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

void	ft_putnbr_base(int nbr, char *base);
int     check_base(char *str2);



#endif