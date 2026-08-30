/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seldogan <seldogan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 15:41:58 by seldogan          #+#    #+#             */
/*   Updated: 2026/08/30 19:11:58 by seldogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int			ft_printf(const char *first, ...);
int			ft_findformat(char format, va_list *args);

int			ft_putchar(char c);
int			ft_putnbr(int n);
int			ft_unsigned_putnbr(unsigned int n);
int			ft_putstr(char *s);

long int	ft_strlen(char *str);
int			ft_putnbr_base(unsigned long int nbr, char *base);
int			ft_putadress(void *nbr);
#endif