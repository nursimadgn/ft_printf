/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seldogan <seldogan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 19:11:22 by seldogan          #+#    #+#             */
/*   Updated: 2026/08/30 19:13:24 by seldogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_putnbr_base(unsigned long int nbr, char *base)
{
	unsigned long int	base_len;
	int					i;

	i = 0;
	base_len = ft_strlen(base);
	if (nbr < base_len)
	{
		ft_putchar(base[nbr]);
		i++;
	}
	else
	{
		i += ft_putnbr_base(nbr / base_len, base);
		i += ft_putnbr_base(nbr % base_len, base);
	}
	return (i);
}

int	ft_putadress(void *nbr)
{
	int	i;

	i = 0;
	if (!nbr)
		return (ft_putstr("(nil)"));
	ft_putchar('0');
	ft_putchar('x');
	i = ft_putnbr_base((unsigned long int)nbr, "0123456789abcdef");
	i = i + 2;
	return (i);
}
