/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccascava <ccascava@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 11:32:55 by ccascava          #+#    #+#             */
/*   Updated: 2026/10/12 16:41:57 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	find_len(uintptr_t hexa)
{
	int	hexa_count;

	hexa_count = 0;
	while (hexa > 0)
	{
		hexa /= 16;
		hexa_count++;
	}
	return (hexa_count);
}

void	assign(char *str, int hexa_count, uintptr_t hexa, int original)
{
	hexa_count += 2;
	str = malloc(hexa_count + 1);
	if (!str)
	{
		return ;
	}
	str[hexa_count] = '\0';
	hexa_count--;
	while (hexa_count > 1)
	{
		if (hexa % 16 < 10)
			str[hexa_count] = hexa % 16 + '0';
		else
			str[hexa_count] = hexa % 16 - 10 + 'a';
		hexa /= 16;
		hexa_count--;
	}
	str[hexa_count] = 'x';
	str[0] = '0';
	write (1, str, original + 2);
	free(str);
}

int	ft_printf_ptr(void *ptr)
{
	uintptr_t	hexa;
	int			hexa_count;
	char		*str;
	int			original;

	if (!ptr)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	else
	{
		str = NULL;
		hexa = (uintptr_t)ptr;
		hexa_count = find_len(hexa);
		original = hexa_count;
		assign(str, hexa_count, hexa, original);
		/**
		str = malloc(hexa_count + 3);
		if (!str)
		{
			return (0);
		}
		str[hexa_count + 2] = '\0';
		while (hexa_count + 1 > 1)
		{
			if (hexa % 16 < 10)
				str[hexa_count + 1] = hexa % 16 + '0';
			else
				str[hexa_count + 1] = hexa % 16 - 10 + 'a';
			hexa /= 16;
			hexa_count--;
		}
		str[hexa_count + 1] = 'x';
		str[hexa_count] = '0';
		write (1, str, original + 2);
		free(str);
		**/
		return (original + 2);
	}
}
