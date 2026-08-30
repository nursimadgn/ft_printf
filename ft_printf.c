/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seldogan <seldogan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 17:38:18 by seldogan          #+#    #+#             */
/*   Updated: 2026/08/30 18:07:49 by seldogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_findformat(char format, va_list *args)
{
	int i;
	i = 0;
	if (format == 'd' || format == 'i')
		i = ft_putnbr(va_arg(*args, int));
	else if (format == 'c')
		i = ft_putchar((va_arg(*args, int)));
	else if (format == 's')
		i = ft_putstr(va_arg(*args, char *));
    else if(format == 'u')
        i = ft_unsigned_putnbr(va_arg(*args, int));      
    else if(format == '%')
        i = ft_putchar('%');
    else if(format == 'x')
       	i =	ft_putnbr_base(va_arg(*args, unsigned long int), "0123456789abcdef");
	else if (format == 'X')
		i = ft_putnbr_base(va_arg(*args, unsigned long int), "0123456789ABCDEF");
	else if(format == 'p')
		i = ft_putadress(va_arg(*args, void *));
	return(i);
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
			   len += ft_findformat(first[i], &args);
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

// #include <stdio.h>

// int	main(void)
// {
// 	char a = 'a';
// 	int b = 5;
// 	char s[] = "hello";
// 	ft_printf("d: %d, c: %c, s: %s, %%...,%x sonuçlar, adres: %p", b, a, s, 300, -1);
// 	printf("\nd: %d, c: %c, s: %s, %%...,%x sonuçlar, adres: %p", b, a, s, 300, -1);
// 	int count = ft_printf("\n%s cevap", s);
// 	printf("\n%d\n", count);
// 	ft_printf("%d", count);
// }