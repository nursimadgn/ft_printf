/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nursimadogan <nursimadogan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 17:38:21 by seldogan          #+#    #+#             */
/*   Updated: 2026/08/30 14:24:02 by nursimadoga      ###   ########.fr       */
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

void	ft_putnbr_base(unsigned int nbr, char *base)
{
	long int	base_len;
	long int	long_nbr;

	putchar('0x');
	if (!check_base(base))
	{
		return ;
	}
	base_len = ft_strlen(base);
	long_nbr = nbr;
	if (long_nbr < 0)
	{
		ft_putchar('-');
		long_nbr *= -1;
	}
	if (long_nbr < base_len)
	{
		ft_putchar(base[long_nbr]);
	}
	else
	{
		ft_putnbr_base(long_nbr / base_len, base);
		ft_putnbr_base(long_nbr % base_len, base);
	}
}