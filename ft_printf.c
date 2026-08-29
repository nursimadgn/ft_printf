/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seldogan <seldogan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 17:38:18 by seldogan          #+#    #+#             */
/*   Updated: 2026/08/29 17:25:59 by seldogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_findformat(char format, va_list *args);
    
    if(format == 'd')
    {
        int res_d;
        res_d = va_arg(*args, int);
        ft_putnbr(red_d);   
    }
    if(format == 'c')
    {
        char res_c;
        res_c = (char)va_arg(*args, int);
        wrie(1, &res_c, 1);
    }
    if(format == 's')
    {
        char *res_s;
        res_s = (char *)va_arg(*args, int);
        ft_putstr(res_s);
    }

int ft_printf(const char *first, ...)
{
    int i;
    int len;
    len = 0;
    i = 0;
    
    va_list args;
    
    va_start(args, first);

    while(first[i] != '\0')
    {
        if(first[i] == '%')
        {
            if(first[i + 1] != '\0')
            {
                ft_findformat(first[i + 1], &args);
            }
        }
        else
        {
            len += write(1, &first[i],1);
        } 
        i++;
    }
    return(len);
}

#include <stdio.h>

int main()
{
    int a = 33;
 
    ft_printf("argümanlar deneme %d", a);
    printf("bla bla %d", a);

}