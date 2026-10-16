/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccascava <ccascava@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 11:35:41 by ccascava          #+#    #+#             */
/*   Updated: 2026/10/12 11:35:58 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void write_it(char *str, int len)
{
    while (str[len])
    {
        write (1, &str[len], 1);
        len++;
    }
    free (str);
}

void   assign_it(char *str, unsigned int num, int len, char format)
{
    str[len] = '\0';
    len--;
    while (len >= 0)
    {
        if (num % 16 < 10)
        {
            str[len] = num % 16 + '0';
        }
        else 
        {
            if (format == 'X')
                str[len] = num % 16 - 10 + 'A';
            else if (format == 'x')
                str[len] = num % 16 - 10 + 'a';
        }
        num /= 16;
        len--;
    }
    write_it(str, 0);
}

int ft_printf_hex(unsigned int n, char format)
{
    unsigned int    num;
    int             count;
    int             len;
    char            *str;

    count = 0;
    num = n;
    len = 0;
    while (num > 0)
    {
        num /= 16;
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
    if (!str)
        return (0);
    assign_it(str, num, len, format);
    return (count);
}