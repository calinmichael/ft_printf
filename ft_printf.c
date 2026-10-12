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

int	tha_switch(va_list lst, char conv, int count)
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

int	p2_switch(va_list lst, char conv, int count)
{
	int				decimal;
	/**unsigned int	num;**/

	if (conv == 'd' || conv == 'i')
	{
		decimal = va_arg(lst, int);
		count += ft_printf_nbr(decimal);
	}
	else if (conv == 'u')
	{
		/**num = va_arg(lst, unsigned int);
		count += ft_printf_unsigned(num);**/
	}
	return (count);
}

int	tha_while(va_list lst, int count, const char *a, int i)
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
				count = tha_switch(lst, conv, count);
			else if (conv == 'c' || conv == 's' || conv == 'p')
				count = tha_switch(lst, conv, count);
			else
				count = p2_switch(lst, conv, count);
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
	count = tha_while(lst, count, a, i);
	va_end(lst);
	return (count);
}

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	printf("\n===== %%c =====\n");
	printf("REAL:      [%c] [%c] [%c]\n", 'A', 'z', '0');
	ft_printf("FT_PRINTF: [%c] [%c] [%c]\n", 'A', 'z', '0');

	printf("\n===== %%s =====\n");
	printf("REAL:      [%s] [%s] [%s]\n", "Hello", "", "42");
	ft_printf("FT_PRINTF: [%s] [%s] [%s]\n", "Hello", "", "42");

	printf("\n===== %%s NULL =====\n");
	printf("REAL:      [%s]\n", (char *)NULL);
	ft_printf("FT_PRINTF: [%s]\n", (char *)NULL);

	printf("\n===== %%p =====\n");
	printf("REAL:      [%p] [%p]\n", (void *)0, (void *)1);
	ft_printf("FT_PRINTF: [%p] [%p]\n", (void *)0, (void *)1);

	printf("\n===== %%p ADDRESS =====\n");
	int x = 42;
	printf("REAL:      [%p]\n", (void *)&x);
	ft_printf("FT_PRINTF: [%p]\n", (void *)&x);

	printf("\n===== %%d =====\n");
	printf("REAL:      [%d] [%d] [%d] [%d]\n", 0, 1, -1, 42);
	ft_printf("FT_PRINTF: [%d] [%d] [%d] [%d]\n", 0, 1, -1, 42);

	printf("\n===== %%d LIMITS =====\n");
	printf("REAL:      [%d] [%d]\n", INT_MAX, INT_MIN);
	ft_printf("FT_PRINTF: [%d] [%d]\n", INT_MAX, INT_MIN);

	printf("\n===== %%i =====\n");
	printf("REAL:      [%i] [%i] [%i] [%i]\n", 0, 42, -42, 123456);
	ft_printf("FT_PRINTF: [%i] [%i] [%i] [%i]\n", 0, 42, -42, 123456);

	printf("\n===== %%i LIMITS =====\n");
	printf("REAL:      [%i] [%i]\n", INT_MAX, INT_MIN);
	ft_printf("FT_PRINTF: [%i] [%i]\n", INT_MAX, INT_MIN);

	printf("\n===== %% =====\n");
	printf("REAL:      [%%] [100%%] [%%%%]\n");
	ft_printf("FT_PRINTF: [%%] [100%%] [%%%%]\n");

	printf("\n===== MIXED =====\n");
	printf("REAL:      %s scored %i points, grade %c (100%%)\n",
		"Alex", 42, 'A');
	ft_printf("FT_PRINTF: %s scored %i points, grade %c (100%%)\n",
		"Alex", 42, 'A');

	printf("\n===== RETURN VALUES =====\n");
	int a = printf("REAL:      Hello %i!\n", 42);
	int b = ft_printf("FT_PRINTF: Hello %i!\n", 42);
	printf("printf returned: %d\n", a);
	printf("ft_printf returned: %d\n", b);

	return (0);
}
