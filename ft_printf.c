/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccascava <ccascava@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 15:11:52 by ccascava          #+#    #+#             */
/*   Updated: 2026/10/12 16:36:23 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	c_s_p(va_list lst, char conv, int count)
{
	char	ch;
	char	*str;
	void	*ptr;

	if (conv == 'c')
	{
		ch = va_arg(lst, int);
		count += ft_printf_char(ch);
	}
	else if (conv == 's')
	{
		str = va_arg(lst, char *);
		count += ft_printf_str(str);
	}
	else if (conv == 'p')
	{
		ptr = va_arg(lst, void *);
		count += ft_printf_ptr(ptr);
	}
	else if (conv == '%')
	{
		write (1, "%", 1);
		count++;
	}
	return (count);
}

int	di_u_x(va_list lst, char conv, int count)
{
	int				decimal;
	unsigned int	num;

	if (conv == 'd' || conv == 'i')
	{
		decimal = va_arg(lst, int);
		count += ft_printf_nbr(decimal);
	}
	else if (conv == 'u')
	{
		num = va_arg(lst, unsigned int);
		count += ft_printf_unsigned(num);
	}
	else if (conv == 'x' || conv == 'X')
	{
		num = va_arg(lst, unsigned int);
		count += ft_printf_hex(num, conv);
	}
	return (count);
}

int	the_filter(va_list lst, int count, const char *a, int i)
{
	char	conv;

	while (a[i])
	{
		if (a[i] == '%')
		{
			if (!a[i + 1])
				return (0);
			i++;
			conv = a[i];
			if (conv == '%')
				count = c_s_p(lst, conv, count);
			else if (conv == 'c' || conv == 's' || conv == 'p')
				count = c_s_p(lst, conv, count);
			else
				count = di_u_x(lst, conv, count);
		}
		else
		{
			write (1, &a[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *a, ...)
{
	size_t	i;
	int		count;
	va_list	lst;

	if (!a)
		return (0);
	va_start(lst, a);
	count = 0;
	i = 0;
	count = the_filter(lst, count, a, i);
	va_end(lst);
	return (count);
}



#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	real;
	int	mine;

	printf("===== %%c =====\n");
	real = printf("Real: [%c]\n", 'A');
	mine = ft_printf("Mine: [%c]\n", 'A');
	printf("Return: real=%d mine=%d\n\n", real, mine);

	printf("===== %%s =====\n");
	real = printf("Real: [%s]\n", "Hello, world!");
	mine = ft_printf("Mine: [%s]\n", "Hello, world!");
	printf("Return: real=%d mine=%d\n\n", real, mine);

	printf("===== %%p =====\n");
	real = printf("Real: [%p]\n", (void *)0);
	mine = ft_printf("Mine: [%p]\n", (void *)0);
	printf("Return: real=%d mine=%d\n\n", real, mine);

	printf("===== %%d =====\n");
	real = printf("Real: [%d]\n", -42);
	mine = ft_printf("Mine: [%d]\n", -42);
	printf("Return: real=%d mine=%d\n\n", real, mine);

	printf("===== %%i =====\n");
	real = printf("Real: [%i]\n", 2147483647);
	mine = ft_printf("Mine: [%i]\n", 2147483647);
	printf("Return: real=%d mine=%d\n\n", real, mine);

	printf("===== %%u =====\n");
	real = printf("Real: [%u]\n", (unsigned int)-1);
	mine = ft_printf("Mine: [%u]\n", (unsigned int)-1);
	printf("Return: real=%d mine=%d\n\n", real, mine);

	printf("===== %%x =====\n");
	real = printf("Real: [%x]\n", 255u);
	mine = ft_printf("Mine: [%x]\n", 255u);
	printf("Return: real=%d mine=%d\n\n", real, mine);

	printf("===== %%X =====\n");
	real = printf("Real: [%X]\n", 255u);
	mine = ft_printf("Mine: [%X]\n", 255u);
	printf("Return: real=%d mine=%d\n\n", real, mine);

	printf("===== %%%% =====\n");
	real = printf("Real: [%%]\n");
	mine = ft_printf("Mine: [%%]\n");
	printf("Return: real=%d mine=%d\n\n", real, mine);

	printf("===== ZERO TESTS =====\n");
	real = printf("Real: [%d]\n", 0);
	mine = ft_printf("Mine: [%d]\n", 0);
	printf("Return: real=%d mine=%d\n\n", real, mine);

	real = printf("Real: [%u]\n", 0u);
	mine = ft_printf("Mine: [%u]\n", 0u);
	printf("Return: real=%d mine=%d\n\n", real, mine);

	real = printf("Real: [%x]\n", 0u);
	mine = ft_printf("Mine: [%x]\n", 0u);
	printf("Return: real=%d mine=%d\n\n", real, mine);

	printf("===== NO CONVERSION =====\n");
	real = printf("Real: Hello!\n");
	mine = ft_printf("Mine: Hello!\n");
	printf("Return: real=%d mine=%d\n", real, mine);

	return (0);
}

