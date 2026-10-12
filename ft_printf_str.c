/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccascava <ccascava@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 11:32:14 by ccascava          #+#    #+#             */
/*   Updated: 2026/10/12 12:38:49 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_str(const char *str)
{
	int		j;
	int		count;

	count = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	else
	{
		j = 0;
		while (str[j])
		{
			write (1, &str[j], 1);
			count++;
			j++;
		}
	}
	return (count);
}
