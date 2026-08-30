/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seldogan <seldogan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 17:38:21 by seldogan          #+#    #+#             */
/*   Updated: 2026/08/30 19:12:02 by seldogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	i;

	i = 0;
	write(1, &c, 1);
	i++;
	return (i);
}

int	ft_putnbr(int n)
{
	long	number;
	int		i;

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
	return (i);
}

int	ft_unsigned_putnbr(unsigned int n)
{
	long	number;
	int		i;

	number = n;
	i = 0;
	if (number >= 10)
	{
		i += ft_putnbr(number / 10);
	}
	ft_putchar((number % 10) + '0');
	i++;
	return (i);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}
