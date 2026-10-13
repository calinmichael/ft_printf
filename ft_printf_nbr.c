/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccascava <ccascava@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 11:34:56 by ccascava          #+#    #+#             */
/*   Updated: 2026/10/12 15:03:38 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	assign_str(char *str, int len, long num)
{
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
	free(str);

}

int	update_count(int len, int flag, long num, int count)
{
	char	*str;

	if (num < 0)
		num *= -1;
	str = malloc(len + 1);
	if (!str)
	{
		return (0);
	}
	if (flag == 1)
	{
		write (1, "-", 1);
		count++;
	}
	str[len] = '\0';
	len--;
	assign_str(str, len, num);
	return (count);
}

int	ft_printf_nbr(int n)
{
	long	num;
	int		len;
	int		count;
	int		flag;

	num = n;
	len = 0;
	count = 0;
	flag = 0;
	if (num < 0)
	{
		num *= -1;
		flag = 1;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
		count++;
	}
	if (len == 0)
	{
		len++;
		count++;
	}
	num = n;
	return (update_count(len, flag, num, count));
}
