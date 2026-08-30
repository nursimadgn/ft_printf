/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seldogan <seldogan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 17:38:21 by seldogan          #+#    #+#             */
/*   Updated: 2026/08/30 19:01:41 by seldogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c)
{
	int i;
	i = 0;
	write (1, &c, 1);
	i++;
	return(i);
}

int		ft_putnbr(int n)
{
	long	number;
	int i;
	i = 0;
	number = n;
	if (number < 0)
	{
		ft_putchar('-');
		number = -number;
		i++;	
	}
	if (number >= 10)
	{
		i += ft_putnbr(number / 10);
	}
	ft_putchar((number % 10) + '0');
	i++;
	return(i);
}

int		ft_unsigned_putnbr(unsigned int n)
{
	long	number;
	int i;
	number = n;
	i = 0;
	if (number >= 10)
	{
		i += ft_putnbr(number / 10);
	}
	ft_putchar((number % 10) + '0');
	i++;
	return(i);
}

int		ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return(ft_putstr("(null)"));
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return(i);
}

long int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int		ft_putnbr_base(unsigned long int nbr, char *base)
{
	unsigned long int	base_len;
	int i;
	i = 0;
	
	base_len = ft_strlen(base);
	
	if (nbr < base_len)
	{
		ft_putchar(base[nbr]);
		i++;
	}
	else
	{
		i += ft_putnbr_base(nbr/ base_len, base);
		i += ft_putnbr_base(nbr % base_len, base);
	}
	return(i);
}

int		ft_putadress(void *nbr)
{
	int i;
	i = 0;
	if(!nbr)
		return(ft_putstr("(nil)"));
	ft_putchar('0');
	ft_putchar('x');
	i = ft_putnbr_base((unsigned long int)nbr, "0123456789abcdef");
	i = i + 2;
	return(i);
}