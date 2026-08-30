/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nursimadogan <nursimadogan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 17:38:18 by seldogan          #+#    #+#             */
/*   Updated: 2026/08/30 14:21:42 by nursimadoga      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_findformat(char format, va_list *args)
{
	if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(*args, int));
	if (format == 'c')
		ft_putchar((va_arg(*args, int)));
	if (format == 's')
		ft_putstr(va_arg(*args, char *));
    if(format == 'u')
        ft_unsigned_putnbr(va_arg(*args, int));      
    if(format == '%')
        putchar('%');
    if(format == 'x')
        ft_putnbr_base(va_arg(*args, unsigned int), "0123456789abcdef");
	if (format == 'X')
		ft_putnbr_base(va_arg(*args, unsigned int), "0123456789ABCDEF");
}

int	ft_printf(const char *first, ...)
{
	int		i;
	int		len;
	va_list	args;

	len = 0;
	i = 0;
	va_start(args, first);
	while (first[i] != '\0')
	{
		if (first[i] == '%')
		{
			i++;
			if (first[i] != '\0')
			{
			    ft_findformat(first[i], &args);
			}
		}
		else
		{
			len += write(1, &first[i], 1);
		}
		i++;
	}
	va_end(args);
	return (len);
}

#include <stdio.h>

int	main(void)
{
	char a = 'a';
	int b = 5;
	char s[] = "hello";
	ft_printf("d: %d, c: %c, s: %s, adres: %p, %%", 0x10, a, s, &b);
}