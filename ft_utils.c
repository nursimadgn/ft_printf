/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seldogan <seldogan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 17:38:21 by seldogan          #+#    #+#             */
/*   Updated: 2026/08/30 17:24:36 by seldogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int n)
{
	long	number;

	number = n;
	if (number < 0)
	{
		ft_putchar('-');
		number = -number;
	}
	if (number >= 10)
	{
		ft_putnbr(number / 10);
	}
	ft_putchar((number % 10) + '0');
}

void	ft_unsigned_putnbr(unsigned int n)
{
	long	number;

	number = n;
	if (number >= 10)
	{
		ft_putnbr(number / 10);
	}
	ft_putchar((number % 10) + '0');
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
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

int	check_base(char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(str2) < 2)
		return (0);
	while (str2[i])
	{
		j = i + 1;
		while (str2[j])
		{
			if (str2[i] == str2[j])
				return (0);
			j++;
		}
		if ((str2[i] >= 9 && str2[i] <= 13) || str2[i] == 32 || str2[i] == '-'
			|| str2[i] == '+')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(unsigned long int nbr, char *base)
{
	unsigned long int	base_len;

	if (!check_base(base))
	{
		return ;
	}
	base_len = ft_strlen(base);
	
	if (nbr < base_len)
	{
		ft_putchar(base[nbr]);
	}
	else
	{
		ft_putnbr_base(nbr/ base_len, base);
		ft_putnbr_base(nbr % base_len, base);
	}
}

void	ft_putadress(void *nbr)
{
	
	ft_putchar('0');
	ft_putchar('x');
	ft_putnbr_base((unsigned long int)nbr, "0123456789abcdef");
}