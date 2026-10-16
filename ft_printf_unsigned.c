/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccascava <ft_printf_unsigned.c>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 11:34:24 by ccascava          #+#    #+#             */
/*   Updated: 2026/10/12 11:34:37 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    pls_print(char *str, int len)
{
    while (str[len])
    {
        write (1, &str[len], 1);
        len++;
    }
    free (str);
}

void    create(char *str, unsigned int num, int len)
{
    str[len] = '\0';
    len--;
    while (len >= 0)
    {
        str[len] = num % 10 + '0';
        num /= 10;
        len--;
    }
    pls_print(str, 0);
}

int ft_printf_unsigned(unsigned int n)
{
    unsigned int    num;
    int             count;
    int             len;
    char            *str;

    num = n;
    count = 0;
    len = 0;
    while (num > 0)
    {
        num /= 10;
        count++;
        len++;
    }
    if (len == 0)
    {
        len++;
        count++;
    }
    num = n;
    str = malloc(len + 1);
    if(!str)
    {
        return (0);
    }
    create(str, num, len);
    return (count);
}