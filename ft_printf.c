/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seldogan <seldogan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 17:38:18 by seldogan          #+#    #+#             */
/*   Updated: 2026/08/30 17:25:55 by seldogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_findformat(char format, va_list *args)
{
	if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(*args, int));
	else if (format == 'c')
		ft_putchar((va_arg(*args, int)));
	else if (format == 's')
		ft_putstr(va_arg(*args, char *));
    else if(format == 'u')
        ft_unsigned_putnbr(va_arg(*args, int));      
    else if(format == '%')
        ft_putchar('%');
    else if(format == 'x')
        ft_putnbr_base(va_arg(*args, unsigned long int), "0123456789abcdef");
	else if (format == 'X')
		ft_putnbr_base(va_arg(*args, unsigned long int), "0123456789ABCDEF");
	else if(format == 'p')
		ft_putadress(va_arg(*args, void *));
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
	ft_printf("d: %d, c: %c, s: %s, %%...,%x sonuçlar, adres: %p", b, a, s, 300, &b);

	printf("\nd: %d, c: %c, s: %s, %%...,%x sonuçlar, adres: %p", b, a, s, 300, &b);
}