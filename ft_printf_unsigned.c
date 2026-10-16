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
    str[len] = '\0';
    len--;
    while (len >= 0)
    {
        str[len] = num % 10 + '0';
        num /= 10;
        len--;
    }
    len = 0;
    while (str[len])
    {
        write (1, &str[len], 1);
        len++;
    }
    free (str);
    return (count);
}