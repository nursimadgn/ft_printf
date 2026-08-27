/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seldogan <seldogan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 17:38:18 by seldogan          #+#    #+#             */
/*   Updated: 2026/08/27 17:47:44 by seldogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char * args_printf, ...)
{

    int i;
    i = 0;
    va_list args;
    
    va_start(args, args_printf);

    if (args_printf[i] == '%' && args_printf[i + 1] == 'd')
    {
        int a;
        a = va_arg(args, int);
        ft_putnbr(a);
    }
    return()
}

#include <stdio.h>

int main()
{
    int a = 33;
 
    ft_printf("argümanlar deneme %d", a);
    printf("bla bla %d", a);

}